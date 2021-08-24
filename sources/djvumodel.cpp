/*

Copyright 2014 S. Razi Alavizadeh
Copyright 2013-2014 Adam Reichold
Copyright 2013 Alexander Volkov

This file is part of qpdfview.

The implementation is based on KDjVu by Pino Toscano.

qpdfview is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

qpdfview is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with qpdfview.  If not, see <http://www.gnu.org/licenses/>.

*/

#include "djvumodel.h"

#include <cstdio>

#include <QFile>
#include <qmath.h>

#include <libdjvu/ddjvuapi.h>
#include <libdjvu/miniexp.h>

#define LOCK_PAGE QMutexLocker mutexLocker(&m_parent->m_mutex);
#define LOCK_DOCUMENT QMutexLocker mutexLocker(&m_mutex);

#if DDJVUAPI_VERSION < 23

#define LOCK_PAGE_GLOBAL QMutexLocker globalMutexLocker(m_parent->m_globalMutex);
#define LOCK_DOCUMENT_GLOBAL QMutexLocker globalMutexLocker(m_globalMutex);

#else

#define LOCK_PAGE_GLOBAL
#define LOCK_DOCUMENT_GLOBAL

#endif // DDJVUAPI_VERSION

namespace
{

using namespace qpdfview::Model;

inline miniexp_t miniexp_cadddr(miniexp_t exp)
{
    return miniexp_cadr(miniexp_cddr(exp));
}

inline miniexp_t miniexp_caddddr(miniexp_t exp)
{
    return miniexp_caddr(miniexp_cddr(exp));
}

inline miniexp_t skip(miniexp_t exp, int offset)
{
    while(offset-- > 0)
    {
        exp = miniexp_cdr(exp);
    }

    return exp;
}

void clearMessageQueue(ddjvu_context_t* context, bool wait)
{
    if(wait)
    {
        ddjvu_message_wait(context);
    }

    while(true)
    {
        if(ddjvu_message_peek(context) != 0)
        {
            ddjvu_message_pop(context);
        }
        else
        {
            break;
        }
    }
}

void waitForMessageTag(ddjvu_context_t* context, ddjvu_message_tag_t tag)
{
    ddjvu_message_wait(context);

    while(true)
    {
        ddjvu_message_t* message = ddjvu_message_peek(context);

        if(message != 0)
        {
            if(message->m_any.tag == tag)
            {
                break;
            }

            ddjvu_message_pop(context);
        }
        else
        {
            break;
        }
    }
}

QPainterPath loadLinkBoundary(const QString& type, miniexp_t boundaryExp, const QSizeF& size)
{
    QPainterPath boundary;

    const int count = miniexp_length(boundaryExp);

    if(count == 4 && (type == QLatin1String("rect") || type == QLatin1String("oval")))
    {
        QPoint p(miniexp_to_int(miniexp_car(boundaryExp)), miniexp_to_int(miniexp_cadr(boundaryExp)));
        QSize s(miniexp_to_int(miniexp_caddr(boundaryExp)), miniexp_to_int(miniexp_cadddr(boundaryExp)));

        p.setY(size.height() - s.height() - p.y());

        const QRectF r(p, s);

        if(type == QLatin1String("rect"))
        {
            boundary.addRect(r);
        }
        else
        {
            boundary.addEllipse(r);
        }
    }
    else if(count > 0 && count % 2 == 0 && type == QLatin1String("poly"))
    {
        QPolygon polygon;

        for(int index = 0; index < count; index += 2)
        {
            QPoint p(miniexp_to_int(miniexp_nth(index, boundaryExp)), miniexp_to_int(miniexp_nth(index + 1, boundaryExp)));

            p.setY(size.height() - p.y());

            polygon << p;
        }

        boundary.addPolygon(polygon);
    }

    return QTransform::fromScale(1.0 / size.width(), 1.0 / size.height()).map(boundary);
}

Link* loadLinkTarget(const QPainterPath& boundary, miniexp_t targetExp, int index, const QHash< QString, int >& indexByName)
{
    QString target;

    if(miniexp_stringp(targetExp))
    {
        target = QString::fromUtf8(miniexp_to_str(targetExp));
    }
    else if(miniexp_length(targetExp) == 3 && qstrcmp(miniexp_to_name(miniexp_car(targetExp)), "url") == 0)
    {
        target = QString::fromUtf8(miniexp_to_str(miniexp_cadr(targetExp)));
    }

    if(target.isEmpty())
    {
        return 0;
    }

    if(target.at(0) == QLatin1Char('#'))
    {
        target.remove(0, 1);

        bool ok = false;
        int targetPage = target.toInt(&ok);

        if(!ok)
        {
            if(indexByName.contains(target))
            {
                targetPage = indexByName[target] + 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if(target.at(0) == QLatin1Char('+') || target.at(0) == QLatin1Char('-'))
            {
                targetPage += index + 1;
            }
        }

        return new Link(boundary, targetPage);
    }
    else
    {
        return new Link(boundary, target);
    }
}

QList< Link* > loadLinks(miniexp_t linkExp, const QSizeF& size, int index, const QHash< QString, int >& indexByName)
{
    QList< Link* > links;

    for(miniexp_t linkItem = miniexp_nil; miniexp_consp(linkExp); linkExp = miniexp_cdr(linkExp))
    {
        linkItem = miniexp_car(linkExp);

        if(miniexp_length(linkItem) < 4 || qstrcmp(miniexp_to_name(miniexp_car(linkItem)), "maparea") != 0)
        {
            continue;
        }

        miniexp_t targetExp = miniexp_cadr(linkItem);
        miniexp_t boundaryExp = miniexp_cadddr(linkItem);

        if(!miniexp_symbolp(miniexp_car(boundaryExp)))
        {
            continue;
        }

        const QString type = QString::fromUtf8(miniexp_to_name(miniexp_car(boundaryExp)));

        if(type == QLatin1String("rect") || type == QLatin1String("oval") || type == QLatin1String("poly"))
        {
            QPainterPath boundary = loadLinkBoundary(type, miniexp_cdr(boundaryExp), size);

            if(!boundary.isEmpty())
            {
                Link* link = loadLinkTarget(boundary, targetExp, index, indexByName);

                if(link != 0)
                {
                    links.append(link);
                }
            }
        }
    }

    return links;
}

QString loadText(miniexp_t textExp, const QSizeF& size, const QRectF& rect)
{
    if(miniexp_length(textExp) < 6 && !miniexp_symbolp(miniexp_car(textExp)))
    {
        return QString();
    }

    const int xmin = miniexp_to_int(miniexp_cadr(textExp));
    const int ymin = miniexp_to_int(miniexp_caddr(textExp));
    const int xmax = miniexp_to_int(miniexp_cadddr(textExp));
    const int ymax = miniexp_to_int(miniexp_caddddr(textExp));

    if(rect.intersects(QRect(xmin, size.height() - ymax, xmax - xmin, ymax - ymin)))
    {
        const QString type = QString::fromUtf8(miniexp_to_name(miniexp_car(textExp)));

        if(type == QLatin1String("word"))
        {
            return QString::fromUtf8(miniexp_to_str(miniexp_nth(5, textExp)));
        }
        else
        {
            QStringList text;

            textExp = skip(textExp, 5);

            for(miniexp_t textItem = miniexp_nil; miniexp_consp(textExp); textExp = miniexp_cdr(textExp))
            {
                textItem = miniexp_car(textExp);

                text.append(loadText(textItem, size, rect));
            }

            return type == QLatin1String("line") ? text.join(" ") : text.join("\n");
        }
    }

    return QString();
}

QList< QRectF > findText(miniexp_t pageTextExp, const QSizeF& size, const QTransform& transform, const QString& text, bool matchCase)
{
    QList< miniexp_t > words;
    QList< QRectF > results;

    int index = 0;
    QRectF rect;

    words.append(pageTextExp);

    while(!words.isEmpty())
    {
        miniexp_t textExp = words.takeFirst();

        if(miniexp_length(textExp) < 6 || !miniexp_symbolp(miniexp_car(textExp)))
        {
            continue;
        }

        const QString type = QString::fromUtf8(miniexp_to_name(miniexp_car(textExp)));

        if(type == QLatin1String("word"))
        {
            const QString word = QString::fromUtf8(miniexp_to_str(miniexp_nth(5, textExp)));

            index = word.indexOf(text, index, matchCase ? Qt::CaseSensitive : Qt::CaseInsensitive);

            if(index != -1)
            {
                const int xmin = miniexp_to_int(miniexp_cadr(textExp));
                const int ymin = miniexp_to_int(miniexp_caddr(textExp));
                const int xmax = miniexp_to_int(miniexp_cadddr(textExp));
                const int ymax = miniexp_to_int(miniexp_caddddr(textExp));

                index += text.length();
                rect = rect.united(QRectF(xmin, size.height() - ymax, xmax - xmin, ymax - ymin));

                if(index == word.length() || !word.at(index).isLetter())
                {
                    results.append(transform.mapRect(rect));

                    index = 0;
                    rect = QRectF();
                }
            }
            else
            {
                index = 0;
                rect = QRectF();
            }
        }
        else
        {
            textExp = skip(textExp, 5);

            for(miniexp_t textItem = miniexp_nil; miniexp_consp(textExp); textExp = miniexp_cdr(textExp))
            {
                textItem = miniexp_car(textExp);

                words.append(textItem);
            }
        }
    }

    return results;
}

void loadOutline(miniexp_t outlineExp, QStandardItem* parent, const QHash< QString, int >& indexByName)
{
    for(miniexp_t outlineItem = miniexp_nil; miniexp_consp(outlineExp); outlineExp = miniexp_cdr(outlineExp))
    {
        outlineItem = miniexp_car(outlineExp);

        if(miniexp_length(outlineItem) < 2 || !miniexp_stringp(miniexp_car(outlineItem)) || !miniexp_stringp(miniexp_cadr(outlineItem)))
        {
            continue;
        }

        const QString title = QString::fromUtf8(miniexp_to_str(miniexp_car(outlineItem)));
        QString destination = QString::fromUtf8(miniexp_to_str(miniexp_cadr(outlineItem)));

        if(!title.isEmpty() && !destination.isEmpty())
        {
            if(destination.at(0) == QLatin1Char('#'))
            {
                destination.remove(0,1);

                bool ok = false;
                int destinationPage = destination.toInt(&ok);

                if(!ok)
                {
                    if(indexByName.contains(destination))
                    {
                        destinationPage = indexByName[destination] + 1;
                    }
                    else
                    {
                        continue;
                    }
                }

                QStandardItem* item = new QStandardItem(title);
                item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);

                item->setData(destinationPage, Qt::UserRole + 1);

                QStandardItem* pageItem = item->clone();
                pageItem->setText(QString::number(destinationPage));
                pageItem->setTextAlignment(Qt::AlignRight);

                parent->appendRow(QList< QStandardItem* >() << item << pageItem);

                if(miniexp_length(outlineItem) > 2)
                {
                    loadOutline(skip(outlineItem, 2), item, indexByName);
                }
            }
        }
    }
}

void loadProperties(miniexp_t annoExp, QStandardItemModel* model)
{
    for(miniexp_t annoItem = miniexp_nil; miniexp_consp(annoExp); annoExp = miniexp_cdr(annoExp))
    {
        annoItem = miniexp_car(annoExp);

        if(miniexp_length(annoItem) < 2 || qstrcmp(miniexp_to_name(miniexp_car(annoItem)), "metadata") != 0)
        {
            continue;
        }

        annoItem = miniexp_cdr(annoItem);

        for(miniexp_t keyValueItem = miniexp_nil; miniexp_consp(annoItem); annoItem = miniexp_cdr(annoItem))
        {
            keyValueItem = miniexp_car(annoItem);

            if(miniexp_length(keyValueItem) != 2)
            {
                continue;
            }

            const QString key = QString::fromUtf8(miniexp_to_name(miniexp_car(keyValueItem)));
            const QString value = QString::fromUtf8(miniexp_to_str(miniexp_cadr(keyValueItem)));

            if(!key.isEmpty() && !value.isEmpty())
            {
                model->appendRow(QList< QStandardItem* >() << new QStandardItem(key) << new QStandardItem(value));
            }
        }
    }
}

} // anonymous

namespace qpdfview
{

namespace Model
{

DjVuPage::DjVuPage(const DjVuDocument* parent, int index, const ddjvu_pageinfo_t& pageinfo) :
    m_parent(parent),
    m_index(index),
    m_size(pageinfo.width, pageinfo.height),
    m_resolution(pageinfo.dpi)
{
}

DjVuPage::~DjVuPage()
{
}

QSizeF DjVuPage::size() const
{
    return 72.0 / m_resolution * m_size;
}

QImage DjVuPage::render(qreal horizontalResolution, qreal verticalResolution, Rotation rotation, const QRect& boundingRect) const
{
    LOCK_PAGE

    ddjvu_page_t* page = ddjvu_page_create_by_pageno(m_parent->m_document, m_index);

    if(page == 0)
    {
        return QImage();
    }

    ddjvu_status_t status;

    while(true)
    {
        status = ddjvu_page_decoding_status(page);

        if(status < DDJVU_JOB_OK)
        {
            clearMessageQueue(m_parent->m_context, true);
        }
        else
        {
            break;
        }
    }

    if(status >= DDJVU_JOB_FAILED)
    {
        ddjvu_page_release(page);

        return QImage();
    }

    switch(rotation)
    {
    default:
    case RotateBy0:
        ddjvu_page_set_rotation(page, DDJVU_ROTATE_0);
        break;
    case RotateBy90:
        ddjvu_page_set_rotation(page, DDJVU_ROTATE_270);
        break;
    case RotateBy180:
        ddjvu_page_set_rotation(page, DDJVU_ROTATE_180);
        break;
    case RotateBy270:
        ddjvu_page_set_rotation(page, DDJVU_ROTATE_90);
        break;
    }

    ddjvu_rect_t pagerect;

    pagerect.x = 0;
    pagerect.y = 0;

    switch(rotation)
    {
    default:
    case RotateBy0:
    case RotateBy180:
        pagerect.w = qRound(horizontalResolution / m_resolution * m_size.width());
        pagerect.h = qRound(verticalResolution / m_resolution * m_size.height());
        break;
    case RotateBy90:
    case RotateBy270:
        pagerect.w = qRound(horizontalResolution / m_resolution * m_size.height());
        pagerect.h = qRound(verticalResolution / m_resolution * m_size.width());
        break;
    }

    ddjvu_rect_t renderrect;

    if(boundingRect.isNull())
    {
        renderrect.x = pagerect.x;
        renderrect.y = pagerect.y;
        renderrect.w = pagerect.w;
        renderrect.h = pagerect.h;
    }
    else
    {
        renderrect.x = boundingRect.x();
        renderrect.y = boundingRect.y();
        renderrect.w = boundingRect.width();
        renderrect.h = boundingRect.height();
    }

    QImage image(renderrect.w, renderrect.h, QImage::Format_RGB32);

    if(!ddjvu_page_render(page, DDJVU_RENDER_COLOR, &pagerect, &renderrect, m_parent->m_format, image.bytesPerLine(), reinterpret_cast< char* >(image.bits())))
    {
        image = QImage();
    }

    clearMessageQueue(m_parent->m_context, false);

    ddjvu_page_release(page);

    return image;
}

QList< Link* > DjVuPage::links() const
{
    LOCK_PAGE

    miniexp_t pageAnnoExp = miniexp_nil;

    {
        LOCK_PAGE_GLOBAL

        while(true)
        {
            pageAnnoExp = ddjvu_document_get_pageanno(m_parent->m_document, m_index);

            if(pageAnnoExp == miniexp_dummy)
            {
                clearMessageQueue(m_parent->m_context, true);
            }
            else
            {
                break;
            }
        }
    }

    const QList< Link* > links = loadLinks(pageAnnoExp, m_size, m_index, m_parent->m_indexByName);

    {
        LOCK_PAGE_GLOBAL

        ddjvu_miniexp_release(m_parent->m_document, pageAnnoExp);
    }

    return links;
}

QString DjVuPage::text(const QRectF& rect) const
{
    LOCK_PAGE

    miniexp_t pageTextExp = miniexp_nil;

    {
        LOCK_PAGE_GLOBAL

        while(true)
        {
            pageTextExp = ddjvu_document_get_pagetext(m_parent->m_document, m_index, "word");

            if(pageTextExp == miniexp_dummy)
            {
                clearMessageQueue(m_parent->m_context, true);
            }
            else
            {
                break;
            }
        }
    }

    const QTransform transform = QTransform::fromScale(m_resolution / 72.0, m_resolution / 72.0);

    const QString text = loadText(pageTextExp, m_size, transform.mapRect(rect)).simplified();

    {
        LOCK_PAGE_GLOBAL

        ddjvu_miniexp_release(m_parent->m_document, pageTextExp);
    }

    return text;
}

QList< QRectF > DjVuPage::search(const QString& text, bool matchCase) const
{
    LOCK_PAGE

    miniexp_t pageTextExp = miniexp_nil;

    {
        LOCK_PAGE_GLOBAL

        while(true)
        {
            pageTextExp = ddjvu_document_get_pagetext(m_parent->m_document, m_index, "word");

            if(pageTextExp == miniexp_dummy)
            {
                clearMessageQueue(m_parent->m_context, true);
            }
            else
            {
                break;
            }
        }
    }

    const QTransform transform = QTransform::fromScale(72.0 / m_resolution, 72.0 / m_resolution);

    const QList< QRectF > results = findText(pageTextExp, m_size, transform, text, matchCase);

    {
        LOCK_PAGE_GLOBAL

        ddjvu_miniexp_release(m_parent->m_document, pageTextExp);
    }

    return results;
}

DjVuDocument::DjVuDocument(QMutex* globalMutex, ddjvu_context_t* context, ddjvu_document_t* document) :
    m_mutex(),
    m_globalMutex(globalMutex),
    m_context(context),
    m_document(document),
    m_format(0),
    m_indexByName()
{
    unsigned int mask[] = {0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000};

    m_format = ddjvu_format_create(DDJVU_FORMAT_RGBMASK32, 4, mask);
    ddjvu_format_set_row_order(m_format, 1);
    ddjvu_format_set_y_direction(m_format, 1);

    prepareIndexByName();
}

DjVuDocument::~DjVuDocument()
{
    ddjvu_document_release(m_document);
    ddjvu_context_release(m_context);
    ddjvu_format_release(m_format);
}

int DjVuDocument::numberOfPages() const
{
    LOCK_DOCUMENT

    return ddjvu_document_get_pagenum(m_document);
}

Page* DjVuDocument::page(int index) const
{
    LOCK_DOCUMENT

    ddjvu_status_t status;
    ddjvu_pageinfo_t pageinfo;

    while(true)
    {
        status = ddjvu_document_get_pageinfo(m_document, index, &pageinfo);

        if(status < DDJVU_JOB_OK)
        {
            clearMessageQueue(m_context, true);
        }
        else
        {
            break;
        }
    }

    if(status >= DDJVU_JOB_FAILED)
    {
        return 0;
    }

    return new DjVuPage(this, index, pageinfo);
}

QStringList DjVuDocument::saveFilter() const
{
    return QStringList() << QLatin1String("DjVu (*.djvu *.djv)");
}

bool DjVuDocument::canSave() const
{
    return true;
}

bool DjVuDocument::save(const QString& filePath, bool withChanges) const
{
    Q_UNUSED(withChanges);

    LOCK_DOCUMENT

#ifdef _MSC_VER

    FILE* file = _wfopen(reinterpret_cast< const wchar_t* >(filePath.utf16()), L"w+");

#else

    FILE* file = fopen(QFile::encodeName(filePath), "w+");

#endif // _MSC_VER

    if(file == 0)
    {
        return false;
    }

    ddjvu_job_t* job = ddjvu_document_save(m_document, file, 0, 0);

    while(!ddjvu_job_done(job))
    {
        clearMessageQueue(m_context, true);
    }

    fclose(file);

    return !ddjvu_job_error(job);
}

void DjVuDocument::loadOutline(QStandardItemModel* outlineModel) const
{
    Document::loadOutline(outlineModel);

    LOCK_DOCUMENT

    miniexp_t outlineExp = miniexp_nil;

    {
        LOCK_DOCUMENT_GLOBAL

        while(true)
        {
            outlineExp = ddjvu_document_get_outline(m_document);

            if(outlineExp == miniexp_dummy)
            {
                clearMessageQueue(m_context, true);
            }
            else
            {
                break;
            }
        }
    }

    if(miniexp_length(outlineExp) < 2 || qstrcmp(miniexp_to_name(miniexp_car(outlineExp)), "bookmarks") != 0)
    {
        return;
    }

    ::loadOutline(skip(outlineExp, 1), outlineModel->invisibleRootItem(), m_indexByName);

    {
        LOCK_DOCUMENT_GLOBAL

        ddjvu_miniexp_release(m_document, outlineExp);
    }
}

void DjVuDocument::loadProperties(QStandardItemModel* propertiesModel) const
{
    Document::loadProperties(propertiesModel);

    LOCK_DOCUMENT

    miniexp_t annoExp = miniexp_nil;

    {
        LOCK_DOCUMENT_GLOBAL

        while(true)
        {
            annoExp = ddjvu_document_get_anno(m_document, TRUE);

            if(annoExp == miniexp_dummy)
            {
                clearMessageQueue(m_context, true);
            }
            else
            {
                break;
            }
        }
    }

    ::loadProperties(annoExp, propertiesModel);

    {
        LOCK_DOCUMENT_GLOBAL

        ddjvu_miniexp_release(m_document, annoExp);
    }
}

void DjVuDocument::prepareIndexByName()
{
    for(int index = 0, count = ddjvu_document_get_filenum(m_document); index < count; ++index)
    {
        ddjvu_fileinfo_t fileinfo;

        if(ddjvu_document_get_fileinfo(m_document, index, &fileinfo) != DDJVU_JOB_OK || fileinfo.type != 'P')
        {
            continue;
        }

        m_indexByName[QString::fromUtf8(fileinfo.id)] = m_indexByName[QString::fromUtf8(fileinfo.name)] = m_indexByName[QString::fromUtf8(fileinfo.title)] = fileinfo.pageno;
    }
}

} // Model

DjVuPlugin::DjVuPlugin(QObject* parent) : QObject(parent),
    m_globalMutex()
{
    setObjectName("DjVuPlugin");
}

Model::Document* DjVuPlugin::loadDocument(const QString& filePath) const
{
    ddjvu_context_t* context = ddjvu_context_create("qpdfview");

    if(context == 0)
    {
        return 0;
    }

#if DDJVUAPI_VERSION >= 19

    ddjvu_document_t* document = ddjvu_document_create_by_filename_utf8(context, filePath.toUtf8(), FALSE);

#else

    ddjvu_document_t* document = ddjvu_document_create_by_filename(context, QFile::encodeName(filePath), FALSE);

#endif // DDJVUAPI_VERSION

    if(document == 0)
    {
        ddjvu_context_release(context);

        return 0;
    }

    waitForMessageTag(context, DDJVU_DOCINFO);

    if(ddjvu_document_decoding_error(document))
    {
        ddjvu_document_release(document);
        ddjvu_context_release(context);

        return 0;
    }

    return new Model::DjVuDocument(&m_globalMutex, context, document);
}

} // qpdfview

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)

Q_EXPORT_PLUGIN2(qpdfview_djvu, qpdfview::DjVuPlugin)

#endif // QT_VERSION
