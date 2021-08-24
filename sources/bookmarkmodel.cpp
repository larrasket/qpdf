/*

Copyright 2014 Adam Reichold

This file is part of qpdfview.

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

#include "bookmarkmodel.h"

#include <QApplication>
#include <QHash>

namespace
{

using namespace qpdfview;

inline bool operator<(int page, const BookmarkItem& bookmark) { return page < bookmark.page; }
inline bool operator<(const BookmarkItem& bookmark, int page) { return bookmark.page < page; }

QHash< QString, BookmarkModel* > modelsByPath;

}

namespace qpdfview
{

BookmarkModel::BookmarkModel(QObject* parent) : QAbstractListModel(parent),
    m_bookmarks()
{
}

void BookmarkModel::addBookmark(const BookmarkItem& bookmark)
{
    QList< BookmarkItem >::iterator at = qBinaryFind(m_bookmarks.begin(), m_bookmarks.end(), bookmark.page);
    int row = at - m_bookmarks.begin();

    if(at != m_bookmarks.end())
    {
        *at = bookmark;

        emit dataChanged(createIndex(row, 0), createIndex(row, 1));
    }
    else
    {
        at = qUpperBound(m_bookmarks.begin(), m_bookmarks.end(), bookmark.page);
        row = at - m_bookmarks.begin();

        beginInsertRows(QModelIndex(), row, row);

        m_bookmarks.insert(at, bookmark);

        endInsertRows();
    }
}

void BookmarkModel::removeBookmark(const BookmarkItem& bookmark)
{
    const QList< BookmarkItem >::iterator at = qBinaryFind(m_bookmarks.begin(), m_bookmarks.end(), bookmark.page);
    const int row = at - m_bookmarks.begin();

    if(at != m_bookmarks.end())
    {
        beginRemoveRows(QModelIndex(), row, row);

        m_bookmarks.erase(at);

        endRemoveRows();
    }
}

void BookmarkModel::findBookmark(BookmarkItem& bookmark) const
{
    const QList< BookmarkItem >::const_iterator at = qBinaryFind(m_bookmarks.constBegin(), m_bookmarks.constEnd(), bookmark.page);

    if(at != m_bookmarks.constEnd())
    {
        bookmark = *at;
    }
}

BookmarkModel* BookmarkModel::fromPath(const QString& path, bool create)
{
    BookmarkModel* model = modelsByPath.value(path, 0);

    if(create && model == 0)
    {
        model = new BookmarkModel(qApp);

        modelsByPath.insert(path, model);
    }

    return model;
}

QList< QString > BookmarkModel::knownPaths()
{
    return modelsByPath.keys();
}

void BookmarkModel::forgetPath(const QString& path)
{
    QHash< QString, BookmarkModel* >::iterator at = modelsByPath.find(path);

    if(at != modelsByPath.end())
    {
        delete at.value();

        modelsByPath.erase(at);
    }
}

void BookmarkModel::forgetAllPaths()
{
    qDeleteAll(modelsByPath);
    modelsByPath.clear();
}

Qt::ItemFlags BookmarkModel::flags(const QModelIndex&) const
{
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

int BookmarkModel::columnCount(const QModelIndex&) const
{
    return 2;
}

int BookmarkModel::rowCount(const QModelIndex& parent) const
{
    return !parent.isValid() ? m_bookmarks.count() : 0;
}

QVariant BookmarkModel::data(const QModelIndex& index, int role) const
{
    if(!index.isValid() || index.row() >= m_bookmarks.count())
    {
        return QVariant();
    }

    const BookmarkItem& bookmark = m_bookmarks.at(index.row());

    switch(role)
    {
    default:
        return QVariant();
    case PageRole:
        return bookmark.page;
    case LabelRole:
    case Qt::DisplayRole:
        return index.column() == 0 ? bookmark.label : QString::number(bookmark.page);
    case CommentRole:
    case Qt::ToolTipRole:
        return bookmark.comment;
    case ModifiedRole:
        return bookmark.modified;
    case Qt::TextAlignmentRole:
        return index.column() == 0 ? Qt::AlignLeft : Qt::AlignRight;
    }
}

} // qpdfview
