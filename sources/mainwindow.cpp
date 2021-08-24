/*

Copyright 2014 S. Razi Alavizadeh
Copyright 2012-2014 Adam Reichold
Copyright 2014 Dorian Scholz
Copyright 2012 Michał Trybus
Copyright 2012 Alexander Volkov

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

#include "mainwindow.h"

#include <QApplication>
#include <QCheckBox>
#include <QDateTime>
#include <QDebug>
#include <QDesktopServices>
#include <QDockWidget>
#include <QDragEnterEvent>
#include <QFileDialog>
#include <QHeaderView>
#include <QInputDialog>
#include <QMenuBar>
#include <QMessageBox>
#include <QMimeData>
#include <QScrollBar>
#include <QShortcut>
#include <QStandardItemModel>
#include <QTableView>
#include <QTimer>
#include <QToolBar>
#include <QToolButton>
#include <QUrl>
#include <QVBoxLayout>
#include <QWidgetAction>

#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)

#include <QStandardPaths>

#endif // QT_VERSION

#include "settings.h"
#include "shortcuthandler.h"
#include "thumbnailitem.h"
#include "searchmodel.h"
#include "documentview.h"
#include "miscellaneous.h"
#include "printdialog.h"
#include "settingsdialog.h"
#include "fontsdialog.h"
#include "helpdialog.h"
#include "recentlyusedmenu.h"
#include "recentlyclosedmenu.h"
#include "bookmarkmodel.h"
#include "bookmarkmenu.h"
#include "bookmarkdialog.h"
#include "database.h"

namespace
{

using namespace qpdfview;

QModelIndex synchronizeOutlineView(int currentPage, TreeView* outlineView, const QModelIndex& parent)
{
    for(int row = 0, rowCount = outlineView->model()->rowCount(parent); row < rowCount; ++row)
    {
        const QModelIndex index = outlineView->model()->index(row, 0, parent);

        bool ok = false;
        const int page = outlineView->model()->data(index, Qt::UserRole + 1).toInt(&ok);

        if(ok && page == currentPage)
        {
            return index;
        }
    }

    for(int row = 0, rowCount = outlineView->model()->rowCount(parent); row < rowCount; ++row)
    {
        const QModelIndex index = outlineView->model()->index(row, 0, parent);
        const QModelIndex match = synchronizeOutlineView(currentPage, outlineView, index);

        if(match.isValid())
        {
            return match;
        }
    }

    return QModelIndex();
}

void setToolButtonMenu(QToolBar* toolBar, QAction* action, QMenu* menu)
{
    QToolButton* toolButton = qobject_cast< QToolButton* >(toolBar->widgetForAction(action));

    if(toolButton != 0)
    {
        toolButton->setMenu(menu);
    }
}

} // anonymous

namespace qpdfview
{

Settings* MainWindow::s_settings = 0;
Database* MainWindow::s_database = 0;

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    s_instance = this;

    if(s_settings == 0)
    {
        s_settings = Settings::instance();
    }

    s_settings->sync();

    prepareStyle();

    setAcceptDrops(true);

    createWidgets();
    createActions();
    createToolBars();
    createDocks();
    createMenus();

    m_toggleToolBarsAction = createAction(tr("Toggle tool bars"), QLatin1String("toggleToolBars"), QIcon(), QKeySequence(Qt::SHIFT + Qt::ALT + Qt::Key_T), SLOT(on_toggleToolBars_triggered(bool)), true, true);
    m_toggleMenuBarAction = createAction(tr("Toggle menu bar"), QLatin1String("toggleMenuBar"), QIcon(), QKeySequence(Qt::SHIFT + Qt::ALT + Qt::Key_M), SLOT(on_toggleMenuBar_triggered(bool)), true, true);

    restoreGeometry(s_settings->mainWindow().geometry());
    restoreState(s_settings->mainWindow().state());

    m_matchCaseCheckBox->setChecked(s_settings->documentView().matchCase());

    prepareDatabase();

    if(s_settings->mainWindow().restoreTabs())
    {
        s_database->restoreTabs();
    }

    if(s_settings->mainWindow().restoreBookmarks())
    {
        s_database->restoreBookmarks();
    }

    on_tabWidget_currentChanged(m_tabWidget->currentIndex());
}

MainWindow* MainWindow::s_instance = 0;

MainWindow* MainWindow::instance()
{
    return s_instance;
}

QSize MainWindow::sizeHint() const
{
    return QSize(600, 800);
}

QMenu* MainWindow::createPopupMenu()
{
    QMenu* menu = new QMenu();

    menu->addAction(m_fileToolBar->toggleViewAction());
    menu->addAction(m_editToolBar->toggleViewAction());
    menu->addAction(m_viewToolBar->toggleViewAction());
    menu->addSeparator();
    menu->addAction(m_outlineDock->toggleViewAction());
    menu->addAction(m_propertiesDock->toggleViewAction());
    menu->addAction(m_thumbnailsDock->toggleViewAction());
    menu->addAction(m_bookmarksDock->toggleViewAction());

    return menu;
}

bool MainWindow::open(const QString& filePath, int page, const QRectF& highlight, bool quiet)
{
    if(m_tabWidget->currentIndex() != -1)
    {
        saveModifications(currentTab());

        if(currentTab()->open(filePath))
        {
            s_settings->mainWindow().setOpenPath(currentTab()->fileInfo().absolutePath());
            m_recentlyUsedMenu->addOpenAction(currentTab()->fileInfo());

            m_tabWidget->setTabText(m_tabWidget->currentIndex(), currentTab()->title());
            m_tabWidget->setTabToolTip(m_tabWidget->currentIndex(), currentTab()->fileInfo().absoluteFilePath());

            s_database->restorePerFileSettings(currentTab());
            scheduleSaveTabs();

            currentTab()->jumpToPage(page, false);
            currentTab()->setFocus();

            if(!highlight.isNull())
            {
                currentTab()->temporaryHighlight(page, highlight);
            }

            return true;
        }
        else
        {
            if(!quiet)
            {
                QMessageBox::warning(this, tr("Warning"), tr("Could not open '%1'.").arg(filePath));
            }
        }
    }

    return false;
}

bool MainWindow::openInNewTab(const QString& filePath, int page, const QRectF& highlight, bool quiet)
{
    DocumentView* newTab = new DocumentView(this);

    if(newTab->open(filePath))
    {
        s_settings->mainWindow().setOpenPath(newTab->fileInfo().absolutePath());
        m_recentlyUsedMenu->addOpenAction(newTab->fileInfo());

        const int index = addTab(newTab);

        QAction* tabAction = new QAction(m_tabWidget->tabText(index), newTab);
        connect(tabAction, SIGNAL(triggered()), SLOT(on_tabAction_triggered()));

        m_tabsMenu->addAction(tabAction);

        on_thumbnails_dockLocationChanged(dockWidgetArea(m_thumbnailsDock));

        connect(newTab, SIGNAL(documentChanged()), SLOT(on_currentTab_documentChanged()));

        connect(newTab, SIGNAL(numberOfPagesChanged(int)), SLOT(on_currentTab_numberOfPagesChaned(int)));
        connect(newTab, SIGNAL(currentPageChanged(int)), SLOT(on_currentTab_currentPageChanged(int)));

        connect(newTab, SIGNAL(canJumpChanged(bool,bool)), SLOT(on_currentTab_canJumpChanged(bool,bool)));

        connect(newTab, SIGNAL(continuousModeChanged(bool)), SLOT(on_currentTab_continuousModeChanged(bool)));
        connect(newTab, SIGNAL(layoutModeChanged(LayoutMode)), SLOT(on_currentTab_layoutModeChanged(LayoutMode)));
        connect(newTab, SIGNAL(rightToLeftModeChanged(bool)), SLOT(on_currentTab_rightToLeftModeChanged(bool)));
        connect(newTab, SIGNAL(scaleModeChanged(ScaleMode)), SLOT(on_currentTab_scaleModeChanged(ScaleMode)));
        connect(newTab, SIGNAL(scaleFactorChanged(qreal)), SLOT(on_currentTab_scaleFactorChanged(qreal)));
        connect(newTab, SIGNAL(rotationChanged(Rotation)), SLOT(on_currentTab_rotationChanged(Rotation)));

        connect(newTab, SIGNAL(linkClicked(int)), SLOT(on_currentTab_linkClicked(int)));
        connect(newTab, SIGNAL(linkClicked(bool,QString,int)), SLOT(on_currentTab_linkClicked(bool,QString,int)));

        connect(newTab, SIGNAL(invertColorsChanged(bool)), SLOT(on_currentTab_invertColorsChanged(bool)));
        connect(newTab, SIGNAL(convertToGrayscaleChanged(bool)), SLOT(on_currentTab_convertToGrayscale(bool)));
        connect(newTab, SIGNAL(highlightAllChanged(bool)), SLOT(on_currentTab_highlightAllChanged(bool)));
        connect(newTab, SIGNAL(rubberBandModeChanged(RubberBandMode)), SLOT(on_currentTab_rubberBandModeChanged(RubberBandMode)));

        connect(newTab, SIGNAL(searchFinished()), SLOT(on_currentTab_searchFinished()));
        connect(newTab, SIGNAL(searchProgressChanged(int)), SLOT(on_currentTab_searchProgressChanged(int)));

        connect(newTab, SIGNAL(customContextMenuRequested(QPoint)), SLOT(on_currentTab_customContextMenuRequested(QPoint)));

        newTab->show();

        s_database->restorePerFileSettings(newTab);
        scheduleSaveTabs();

        newTab->jumpToPage(page, false);
        newTab->setFocus();

        if(!highlight.isNull())
        {
            newTab->temporaryHighlight(page, highlight);
        }

        return true;
    }
    else
    {
        delete newTab;

        if(!quiet)
        {
            QMessageBox::warning(this, tr("Warning"), tr("Could not open '%1'.").arg(filePath));
        }
    }

    return false;
}

bool MainWindow::jumpToPageOrOpenInNewTab(const QString& filePath, int page, bool refreshBeforeJump, const QRectF& highlight, bool quiet)
{
    const QFileInfo fileInfo(filePath);

    for(int index = 0; index < m_tabWidget->count(); ++index)
    {
        if(tab(index)->fileInfo() == fileInfo)
        {
            m_tabWidget->setCurrentIndex(index);

            if(refreshBeforeJump)
            {
                if(!currentTab()->refresh())
                {
                    return false;
                }
            }

            currentTab()->jumpToPage(page);
            currentTab()->setFocus();

            if(!highlight.isNull())
            {
                currentTab()->temporaryHighlight(page, highlight);
            }

            return true;
        }
    }

    return openInNewTab(filePath, page, highlight, quiet);
}

void MainWindow::startSearch(const QString& text)
{
    if(m_tabWidget->currentIndex() != -1)
    {
        m_searchDock->setVisible(true);

        m_searchLineEdit->setText(text);
        m_searchLineEdit->startSearch();

        currentTab()->setFocus();
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    const bool hasCurrent = index != -1;

    m_openCopyInNewTabAction->setEnabled(hasCurrent);
    m_openContainingFolderAction->setEnabled(hasCurrent);
    m_refreshAction->setEnabled(hasCurrent);
    m_printAction->setEnabled(hasCurrent);

    m_previousPageAction->setEnabled(hasCurrent);
    m_nextPageAction->setEnabled(hasCurrent);
    m_firstPageAction->setEnabled(hasCurrent);
    m_lastPageAction->setEnabled(hasCurrent);

    m_setFirstPageAction->setEnabled(hasCurrent);

    m_jumpToPageAction->setEnabled(hasCurrent);

    m_searchAction->setEnabled(hasCurrent);

    m_copyToClipboardModeAction->setEnabled(hasCurrent);
    m_addAnnotationModeAction->setEnabled(hasCurrent);

    m_continuousModeAction->setEnabled(hasCurrent);
    m_twoPagesModeAction->setEnabled(hasCurrent);
    m_twoPagesWithCoverPageModeAction->setEnabled(hasCurrent);
    m_multiplePagesModeAction->setEnabled(hasCurrent);
    m_rightToLeftModeAction->setEnabled(hasCurrent);

    m_zoomInAction->setEnabled(hasCurrent);
    m_zoomOutAction->setEnabled(hasCurrent);
    m_originalSizeAction->setEnabled(hasCurrent);
    m_fitToPageWidthModeAction->setEnabled(hasCurrent);
    m_fitToPageSizeModeAction->setEnabled(hasCurrent);

    m_rotateLeftAction->setEnabled(hasCurrent);
    m_rotateRightAction->setEnabled(hasCurrent);

    m_invertColorsAction->setEnabled(hasCurrent);
    m_convertToGrayscaleAction->setEnabled(hasCurrent);

    m_fontsAction->setEnabled(hasCurrent);

    m_presentationAction->setEnabled(hasCurrent);

    m_previousTabAction->setEnabled(hasCurrent);
    m_nextTabAction->setEnabled(hasCurrent);
    m_closeTabAction->setEnabled(hasCurrent);
    m_closeAllTabsAction->setEnabled(hasCurrent);
    m_closeAllTabsButCurrentTabAction->setEnabled(hasCurrent);

    m_previousBookmarkAction->setEnabled(hasCurrent);
    m_nextBookmarkAction->setEnabled(hasCurrent);
    m_addBookmarkAction->setEnabled(hasCurrent);
    m_removeBookmarkAction->setEnabled(hasCurrent);

    m_currentPageSpinBox->setEnabled(hasCurrent);
    m_scaleFactorComboBox->setEnabled(hasCurrent);
    m_searchLineEdit->setEnabled(hasCurrent);
    m_matchCaseCheckBox->setEnabled(hasCurrent);
    m_highlightAllCheckBox->setEnabled(hasCurrent);

    m_searchDock->toggleViewAction()->setEnabled(hasCurrent);

    if(hasCurrent)
    {
        m_saveCopyAction->setEnabled(currentTab()->canSave());
        m_saveAsAction->setEnabled(currentTab()->canSave());

        if(m_searchDock->isVisible())
        {
            m_searchLineEdit->stopTimer();
            m_searchLineEdit->setProgress(currentTab()->searchProgress());
        }

        m_outlineView->setModel(currentTab()->outlineModel());
        m_propertiesView->setModel(currentTab()->propertiesModel());
        m_bookmarksView->setModel(bookmarkModelForCurrentTab());
        m_thumbnailsView->setScene(currentTab()->thumbnailsScene());

        on_currentTab_documentChanged();

        on_currentTab_numberOfPagesChaned(currentTab()->numberOfPages());
        on_currentTab_currentPageChanged(currentTab()->currentPage());

        on_currentTab_canJumpChanged(currentTab()->canJumpBackward(), currentTab()->canJumpForward());

        on_currentTab_continuousModeChanged(currentTab()->continuousMode());
        on_currentTab_layoutModeChanged(currentTab()->layoutMode());
        on_currentTab_rightToLeftModeChanged(currentTab()->rightToLeftMode());
        on_currentTab_scaleModeChanged(currentTab()->scaleMode());
        on_currentTab_scaleFactorChanged(currentTab()->scaleFactor());

        on_currentTab_invertColorsChanged(currentTab()->invertColors());
        on_currentTab_convertToGrayscale(currentTab()->convertToGrayscale());
        on_currentTab_highlightAllChanged(currentTab()->highlightAll());
        on_currentTab_rubberBandModeChanged(currentTab()->rubberBandMode());

        m_outlineView->restoreExpansion();
    }
    else
    {
        m_saveCopyAction->setEnabled(false);
        m_saveAsAction->setEnabled(false);

        if(m_searchDock->isVisible())
        {
            m_searchLineEdit->stopTimer();
            m_searchLineEdit->setProgress(0);

            m_searchDock->setVisible(false);
        }

        m_outlineView->setModel(0);
        m_propertiesView->setModel(0);
        m_bookmarksView->setModel(0);
        m_thumbnailsView->setScene(0);

        setWindowTitleForCurrentTab();
        setCurrentPageSuffixForCurrentTab();

        m_currentPageSpinBox->setValue(1);
        m_scaleFactorComboBox->setCurrentIndex(4);

        m_jumpBackwardAction->setEnabled(false);
        m_jumpForwardAction->setEnabled(false);

        m_copyToClipboardModeAction->setChecked(false);
        m_addAnnotationModeAction->setChecked(false);

        m_continuousModeAction->setChecked(false);
        m_twoPagesModeAction->setChecked(false);
        m_twoPagesWithCoverPageModeAction->setChecked(false);
        m_multiplePagesModeAction->setChecked(false);

        m_fitToPageSizeModeAction->setChecked(false);
        m_fitToPageWidthModeAction->setChecked(false);

        m_invertColorsAction->setChecked(false);
    }
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    if(saveModifications(tab(index)))
    {
        closeTab(tab(index));
    }
}

void MainWindow::on_tabWidget_tabContextMenuRequested(const QPoint& globalPos, int index)
{
    QMenu menu;

    const QAction* closeAllTabsAction = menu.addAction(tr("Close all tabs"));
    const QAction* closeAllTabsButThisOneAction = menu.addAction(tr("Close all tabs but this one"));
    const QAction* closeAllTabsToTheLeftAction = menu.addAction(tr("Close all tabs to the left"));
    const QAction* closeAllTabsToTheRightAction = menu.addAction(tr("Close all tabs to the right"));

    const QAction* action = menu.exec(globalPos);

    const int count = m_tabWidget->count();

    QList< DocumentView* > tabsToClose;

    if(action == closeAllTabsAction)
    {
        tabsToClose = tabs();
    }
    else if(action == closeAllTabsButThisOneAction)
    {
        for(int indexToClose = 0; indexToClose < count; ++indexToClose)
        {
            if(indexToClose != index)
            {
                tabsToClose.append(tab(indexToClose));
            }
        }
    }
    else if(action == closeAllTabsToTheLeftAction)
    {
        for(int indexToClose = 0; indexToClose < index; ++indexToClose)
        {
            tabsToClose.append(tab(indexToClose));
        }
    }
    else if(action == closeAllTabsToTheRightAction)
    {
        for(int indexToClose = count - 1; indexToClose > index; --indexToClose)
        {
            tabsToClose.append(tab(indexToClose));
        }
    }

    disconnect(m_tabWidget, SIGNAL(currentChanged(int)), this, SLOT(on_tabWidget_currentChanged(int)));

    foreach(DocumentView* tab, tabsToClose)
    {
        if(saveModifications(tab))
        {
            closeTab(tab);
        }
    }

    connect(m_tabWidget, SIGNAL(currentChanged(int)), this, SLOT(on_tabWidget_currentChanged(int)));

    on_tabWidget_currentChanged(m_tabWidget->currentIndex());
}

void MainWindow::on_currentTab_documentChanged()
{
    for(int index = 0; index < m_tabWidget->count(); ++index)
    {
        if(sender() == m_tabWidget->widget(index))
        {
            m_tabWidget->setTabText(index, tab(index)->title());
            m_tabWidget->setTabToolTip(index, tab(index)->fileInfo().absoluteFilePath());

            foreach(QAction* tabAction, m_tabsMenu->actions())
            {
                if(tabAction->parent() == m_tabWidget->widget(index))
                {
                    tabAction->setText(m_tabWidget->tabText(index));

                    break;
                }
            }

            break;
        }
    }

    if(senderIsCurrentTab())
    {
        setWindowTitleForCurrentTab();
    }
}

void MainWindow::on_currentTab_numberOfPagesChaned(int numberOfPages)
{
    if(senderIsCurrentTab())
    {
        m_currentPageSpinBox->setRange(1, numberOfPages);

        setWindowTitleForCurrentTab();
        setCurrentPageSuffixForCurrentTab();
    }
}

void MainWindow::on_currentTab_currentPageChanged(int currentPage)
{
    if(senderIsCurrentTab())
    {
        m_currentPageSpinBox->setValue(currentPage);

        if(s_settings->mainWindow().synchronizeOutlineView() && m_outlineView->model() != 0)
        {
            const QModelIndex match = synchronizeOutlineView(currentPage, m_outlineView, QModelIndex());

            if(match.isValid())
            {
                m_outlineView->collapseAll();

                m_outlineView->expandAbove(match);
                m_outlineView->setCurrentIndex(match);
            }
        }

        m_thumbnailsView->ensureVisible(currentTab()->thumbnailItems().at(currentPage - 1));

        setWindowTitleForCurrentTab();
        setCurrentPageSuffixForCurrentTab();

        scheduleSaveTabs();
        scheduleSavePerFileSettings();
    }
}

void MainWindow::on_currentTab_canJumpChanged(bool backward, bool forward)
{
    if(senderIsCurrentTab())
    {
        m_jumpBackwardAction->setEnabled(backward);
        m_jumpForwardAction->setEnabled(forward);
    }
}

void MainWindow::on_currentTab_continuousModeChanged(bool continuousMode)
{
    if(senderIsCurrentTab())
    {
        m_continuousModeAction->setChecked(continuousMode);

        scheduleSaveTabs();
        scheduleSavePerFileSettings();
    }
}

void MainWindow::on_currentTab_layoutModeChanged(LayoutMode layoutMode)
{
    if(senderIsCurrentTab())
    {
        m_twoPagesModeAction->setChecked(layoutMode == TwoPagesMode);
        m_twoPagesWithCoverPageModeAction->setChecked(layoutMode == TwoPagesWithCoverPageMode);
        m_multiplePagesModeAction->setChecked(layoutMode == MultiplePagesMode);

        scheduleSaveTabs();
        scheduleSavePerFileSettings();
    }
}

void MainWindow::on_currentTab_rightToLeftModeChanged(bool rightToLeftMode)
{
    if(senderIsCurrentTab())
    {
        m_rightToLeftModeAction->setChecked(rightToLeftMode);

        scheduleSaveTabs();
        scheduleSavePerFileSettings();
    }
}

void MainWindow::on_currentTab_scaleModeChanged(ScaleMode scaleMode)
{
    if(senderIsCurrentTab())
    {
        switch(scaleMode)
        {
        default:
        case ScaleFactorMode:
            m_fitToPageWidthModeAction->setChecked(false);
            m_fitToPageSizeModeAction->setChecked(false);

            on_currentTab_scaleFactorChanged(currentTab()->scaleFactor());
            break;
        case FitToPageWidthMode:
            m_fitToPageWidthModeAction->setChecked(true);
            m_fitToPageSizeModeAction->setChecked(false);

            m_scaleFactorComboBox->setCurrentIndex(0);

            m_zoomInAction->setEnabled(true);
            m_zoomOutAction->setEnabled(true);
            break;
        case FitToPageSizeMode:
            m_fitToPageWidthModeAction->setChecked(false);
            m_fitToPageSizeModeAction->setChecked(true);

            m_scaleFactorComboBox->setCurrentIndex(1);

            m_zoomInAction->setEnabled(true);
            m_zoomOutAction->setEnabled(true);
            break;
        }

        scheduleSaveTabs();
        scheduleSavePerFileSettings();
    }
}

void MainWindow::on_currentTab_scaleFactorChanged(qreal scaleFactor)
{
    if(senderIsCurrentTab())
    {
        if(currentTab()->scaleMode() == ScaleFactorMode)
        {
            m_scaleFactorComboBox->setCurrentIndex(m_scaleFactorComboBox->findData(scaleFactor));
            m_scaleFactorComboBox->lineEdit()->setText(QString("%1 %").arg(qRound(scaleFactor * 100.0)));

            m_zoomInAction->setDisabled(qFuzzyCompare(scaleFactor, s_settings->documentView().maximumScaleFactor()));
            m_zoomOutAction->setDisabled(qFuzzyCompare(scaleFactor, s_settings->documentView().minimumScaleFactor()));
        }

        scheduleSaveTabs();
        scheduleSavePerFileSettings();
    }
}

void MainWindow::on_currentTab_rotationChanged(Rotation rotation)
{
    Q_UNUSED(rotation);

    if(senderIsCurrentTab())
    {
        scheduleSaveTabs();
        scheduleSavePerFileSettings();
    }
}

void MainWindow::on_currentTab_linkClicked(int page)
{
    openInNewTab(currentTab()->fileInfo().filePath(), page);
}

void MainWindow::on_currentTab_linkClicked(bool newTab, const QString& filePath, int page)
{
    if(newTab)
    {
        jumpToPageOrOpenInNewTab(filePath, page, true);
    }
    else
    {
        openInNewTab(filePath, page);
    }
}

void MainWindow::on_currentTab_invertColorsChanged(bool invertColors)
{
    if(senderIsCurrentTab())
    {
        m_invertColorsAction->setChecked(invertColors);
    }
}

void MainWindow::on_currentTab_convertToGrayscale(bool convertToGrayscale)
{
    if(senderIsCurrentTab())
    {
        m_convertToGrayscaleAction->setChecked(convertToGrayscale);
    }
}

void MainWindow::on_currentTab_highlightAllChanged(bool highlightAll)
{
    if(senderIsCurrentTab())
    {
        m_highlightAllCheckBox->setChecked(highlightAll);
    }
}

void MainWindow::on_currentTab_rubberBandModeChanged(RubberBandMode rubberBandMode)
{
    if(senderIsCurrentTab())
    {
        m_copyToClipboardModeAction->setChecked(rubberBandMode == CopyToClipboardMode);
        m_addAnnotationModeAction->setChecked(rubberBandMode == AddAnnotationMode);
    }
}

void MainWindow::on_currentTab_searchFinished()
{
    if(senderIsCurrentTab())
    {
        m_searchLineEdit->setProgress(0);
    }
}

void MainWindow::on_currentTab_searchProgressChanged(int progress)
{
    if(senderIsCurrentTab())
    {
        m_searchLineEdit->setProgress(progress);
    }
}

void MainWindow::on_currentTab_customContextMenuRequested(const QPoint& pos)
{
    if(senderIsCurrentTab())
    {
        QMenu menu;

        menu.addAction(m_openCopyInNewTabAction);
        menu.addSeparator();
        menu.addActions(QList< QAction* >() << m_previousPageAction << m_nextPageAction << m_firstPageAction << m_lastPageAction);
        menu.addSeparator();
        menu.addActions(QList< QAction* >() << m_jumpToPageAction << m_jumpBackwardAction << m_jumpForwardAction);
        menu.addSeparator();
        menu.addAction(m_setFirstPageAction);

        if(m_searchDock->isVisible())
        {
            menu.addSeparator();
            menu.addActions(QList< QAction* >() << m_findPreviousAction << m_findNextAction << m_cancelSearchAction);
        }

        menu.exec(currentTab()->mapToGlobal(pos));
    }
}

void MainWindow::on_currentPage_editingFinished()
{
    if(m_tabWidget->currentIndex() != -1)
    {
        currentTab()->jumpToPage(m_currentPageSpinBox->value());
    }
}

void MainWindow::on_currentPage_returnPressed()
{
    currentTab()->setFocus();
}

void MainWindow::on_scaleFactor_activated(int index)
{
    if(index == 0)
    {
        currentTab()->setScaleMode(FitToPageWidthMode);
    }
    else if(index == 1)
    {
        currentTab()->setScaleMode(FitToPageSizeMode);
    }
    else
    {
        bool ok = false;
        const qreal scaleFactor = m_scaleFactorComboBox->itemData(index).toReal(&ok);

        if(ok)
        {
            currentTab()->setScaleFactor(scaleFactor);
            currentTab()->setScaleMode(ScaleFactorMode);
        }
    }

    currentTab()->setFocus();
}

void MainWindow::on_scaleFactor_editingFinished()
{
    if(m_tabWidget->currentIndex() != -1)
    {
        bool ok = false;
        qreal scaleFactor = m_scaleFactorComboBox->lineEdit()->text().toInt(&ok) / 100.0;

        scaleFactor = qMax(scaleFactor, s_settings->documentView().minimumScaleFactor());
        scaleFactor = qMin(scaleFactor, s_settings->documentView().maximumScaleFactor());

        if(ok)
        {
            currentTab()->setScaleFactor(scaleFactor);
            currentTab()->setScaleMode(ScaleFactorMode);
        }

        on_currentTab_scaleFactorChanged(currentTab()->scaleFactor());
        on_currentTab_scaleModeChanged(currentTab()->scaleMode());
    }
}

void MainWindow::on_scaleFactor_returnPressed()
{
    currentTab()->setFocus();
}

void MainWindow::on_open_triggered()
{
    if(m_tabWidget->currentIndex() != -1)
    {
        const QString path = s_settings->mainWindow().openPath();
        const QString filePath = QFileDialog::getOpenFileName(this, tr("Open"), path, DocumentView::openFilter().join(";;"));

        if(!filePath.isEmpty())
        {
            open(filePath);
        }
    }
    else
    {
        on_openInNewTab_triggered();
    }
}

void MainWindow::on_openInNewTab_triggered()
{
    const QString path = s_settings->mainWindow().openPath();
    const QStringList filePaths = QFileDialog::getOpenFileNames(this, tr("Open in new tab"), path, DocumentView::openFilter().join(";;"));

    if(!filePaths.isEmpty())
    {
        disconnect(m_tabWidget, SIGNAL(currentChanged(int)), this, SLOT(on_tabWidget_currentChanged(int)));

        foreach(const QString& filePath, filePaths)
        {
            openInNewTab(filePath);
        }

        connect(m_tabWidget, SIGNAL(currentChanged(int)), this, SLOT(on_tabWidget_currentChanged(int)));

        on_tabWidget_currentChanged(m_tabWidget->currentIndex());
    }
}

void MainWindow::on_openCopyInNewTab_triggered()
{
    openInNewTab(currentTab()->fileInfo().filePath(), currentTab()->currentPage());
}

void MainWindow::on_openContainingFolder_triggered()
{
    QDesktopServices::openUrl(QUrl::fromLocalFile(currentTab()->fileInfo().absolutePath()));
}

void MainWindow::on_refresh_triggered()
{
    if(!currentTab()->refresh())
    {
        QMessageBox::warning(this, tr("Warning"), tr("Could not refresh '%1'.").arg(currentTab()->fileInfo().filePath()));
    }
}

void MainWindow::on_saveCopy_triggered()
{
    const QDir dir = QDir(s_settings->mainWindow().savePath());
    const QString filePath = QFileDialog::getSaveFileName(this, tr("Save copy"), dir.filePath(currentTab()->fileInfo().fileName()), currentTab()->saveFilter().join(";;"));

    if(!filePath.isEmpty())
    {
        if(currentTab()->save(filePath, false))
        {
            s_settings->mainWindow().setSavePath(QFileInfo(filePath).absolutePath());
        }
        else
        {
            QMessageBox::warning(this, tr("Warning"), tr("Could not save copy at '%1'.").arg(filePath));
        }
    }
}

void MainWindow::on_saveAs_triggered()
{
    const QString filePath = QFileDialog::getSaveFileName(this, tr("Save as"), currentTab()->fileInfo().filePath(), currentTab()->saveFilter().join(";;"));

    if(!filePath.isEmpty())
    {
        if(currentTab()->save(filePath, true))
        {
            open(filePath, currentTab()->currentPage());
        }
        else
        {
            QMessageBox::warning(this, tr("Warning"), tr("Could not save as '%1'.").arg(filePath));
        }
    }
}

void MainWindow::on_print_triggered()
{
    QScopedPointer< QPrinter > printer(PrintDialog::createPrinter());
    QScopedPointer< PrintDialog > printDialog(new PrintDialog(printer.data(), this));

    printer->setDocName(currentTab()->fileInfo().completeBaseName());
    printer->setFullPage(true);

    printDialog->setMinMax(1, currentTab()->numberOfPages());
    printDialog->setOption(QPrintDialog::PrintToFile, false);

#if QT_VERSION >= QT_VERSION_CHECK(4,7,0)

    printDialog->setOption(QPrintDialog::PrintCurrentPage, true);

#endif // QT_VERSION

    if(printDialog->exec() == QDialog::Accepted)
    {

#if QT_VERSION >= QT_VERSION_CHECK(4,7,0)

        if(printDialog->printRange() == QPrintDialog::CurrentPage)
        {
            printer->setFromTo(currentTab()->currentPage(), currentTab()->currentPage());
        }

#endif // QT_VERSION

        if(!currentTab()->print(printer.data(), printDialog->printOptions()))
        {
            QMessageBox::warning(this, tr("Warning"), tr("Could not print '%1'.").arg(currentTab()->fileInfo().filePath()));
        }
    }
}

void MainWindow::on_recentlyUsed_openTriggered(const QString& filePath)
{
    if(!jumpToPageOrOpenInNewTab(filePath, -1, true))
    {
        m_recentlyUsedMenu->removeOpenAction(filePath);
    }
}

void MainWindow::on_previousPage_triggered()
{
    currentTab()->previousPage();
}

void MainWindow::on_nextPage_triggered()
{
    currentTab()->nextPage();
}

void MainWindow::on_firstPage_triggered()
{
    currentTab()->firstPage();
}

void MainWindow::on_lastPage_triggered()
{
    currentTab()->lastPage();
}

void MainWindow::on_setFirstPage_triggered()
{
    bool ok = false;
    const int pageNumber = getMappedNumber(this, SLOT(currentPage_textFromValue(int,bool*)), SLOT(currentPage_valueFromText(QString,bool*)),
                                           this, tr("Set first page"), tr("Select the first page of the body matter:"),
                                           currentTab()->currentPage(), 1, currentTab()->numberOfPages(), &ok);

    if(ok)
    {
        currentTab()->setFirstPage(pageNumber);
    }
}

void MainWindow::on_jumpToPage_triggered()
{
    bool ok = false;
    const int pageNumber = getMappedNumber(this, SLOT(currentPage_textFromValue(int,bool*)), SLOT(currentPage_valueFromText(QString,bool*)),
                                           this, tr("Jump to page"), tr("Page:"),
                                           currentTab()->currentPage(), 1, currentTab()->numberOfPages(), &ok);

    if(ok)
    {
        currentTab()->jumpToPage(pageNumber);
    }
}

void MainWindow::on_jumpBackward_triggered()
{
    currentTab()->jumpBackward();
}

void MainWindow::on_jumpForward_triggered()
{
    currentTab()->jumpForward();
}

void MainWindow::on_search_triggered()
{
    m_searchDock->setVisible(true);
    m_searchDock->raise();

    m_searchLineEdit->selectAll();
    m_searchLineEdit->setFocus();
}

void MainWindow::on_findPrevious_triggered()
{
    if(!m_searchLineEdit->text().isEmpty())
    {
        currentTab()->findPrevious();
    }
}

void MainWindow::on_findNext_triggered()
{
    if(!m_searchLineEdit->text().isEmpty())
    {
        currentTab()->findNext();
    }
}

void MainWindow::on_cancelSearch_triggered()
{
    m_searchLineEdit->stopTimer();
    m_searchLineEdit->setProgress(0);

    for(int index = 0; index < m_tabWidget->count(); ++index)
    {
        tab(index)->cancelSearch();
    }

    if(!s_settings->mainWindow().extendedSearchDock())
    {
        m_searchDock->setVisible(false);
    }
}

void MainWindow::on_copyToClipboardMode_triggered(bool checked)
{
    currentTab()->setRubberBandMode(checked ? CopyToClipboardMode : ModifiersMode);
}

void MainWindow::on_addAnnotationMode_triggered(bool checked)
{
    currentTab()->setRubberBandMode(checked ? AddAnnotationMode : ModifiersMode);
}

void MainWindow::on_settings_triggered()
{
    QScopedPointer< SettingsDialog > settingsDialog(new SettingsDialog(this));

    if(settingsDialog->exec() == QDialog::Accepted)
    {
        s_settings->sync();

        m_tabWidget->setTabPosition(static_cast< QTabWidget::TabPosition >(s_settings->mainWindow().tabPosition()));
        m_tabWidget->setTabBarPolicy(static_cast< TabWidget::TabBarPolicy >(s_settings->mainWindow().tabVisibility()));
        m_tabWidget->setSpreadTabs(s_settings->mainWindow().spreadTabs());

        m_saveDatabaseTimer->setInterval(s_settings->mainWindow().saveDatabaseInterval());

        for(int index = 0; index < m_tabWidget->count(); ++index)
        {
            if(!tab(index)->refresh())
            {
                QMessageBox::warning(this, tr("Warning"), tr("Could not refresh '%1'.").arg(currentTab()->fileInfo().filePath()));
            }
        }
    }
}

void MainWindow::on_continuousMode_triggered(bool checked)
{
    currentTab()->setContinuousMode(checked);
}

void MainWindow::on_twoPagesMode_triggered(bool checked)
{
    currentTab()->setLayoutMode(checked ? TwoPagesMode : SinglePageMode);
}

void MainWindow::on_twoPagesWithCoverPageMode_triggered(bool checked)
{
    currentTab()->setLayoutMode(checked ? TwoPagesWithCoverPageMode : SinglePageMode);
}

void MainWindow::on_multiplePagesMode_triggered(bool checked)
{
    currentTab()->setLayoutMode(checked ? MultiplePagesMode : SinglePageMode);
}

void MainWindow::on_rightToLeftMode_triggered(bool checked)
{
    currentTab()->setRightToLeftMode(checked);
}

void MainWindow::on_zoomIn_triggered()
{
    currentTab()->zoomIn();
}

void MainWindow::on_zoomOut_triggered()
{
    currentTab()->zoomOut();
}

void MainWindow::on_originalSize_triggered()
{
    currentTab()->originalSize();
}

void MainWindow::on_fitToPageWidthMode_triggered(bool checked)
{
    currentTab()->setScaleMode(checked ? FitToPageWidthMode : ScaleFactorMode);
}

void MainWindow::on_fitToPageSizeMode_triggered(bool checked)
{
    currentTab()->setScaleMode(checked ? FitToPageSizeMode : ScaleFactorMode);
}

void MainWindow::on_rotateLeft_triggered()
{
    currentTab()->rotateLeft();
}

void MainWindow::on_rotateRight_triggered()
{
    currentTab()->rotateRight();
}

void MainWindow::on_invertColors_triggered(bool checked)
{
    currentTab()->setInvertColors(checked);
}

void MainWindow::on_convertToGrayscale_triggered(bool checked)
{
    currentTab()->setConvertToGrayscale(checked);
}

void MainWindow::on_fonts_triggered()
{
    QScopedPointer< QStandardItemModel > fontsModel(currentTab()->fontsModel());
    QScopedPointer< FontsDialog > dialog(new FontsDialog(fontsModel.data(), this));

    dialog->exec();
}

void MainWindow::on_fullscreen_triggered(bool checked)
{
    if(checked)
    {
        m_fullscreenAction->setData(saveGeometry());

        showFullScreen();
    }
    else
    {
        restoreGeometry(m_fullscreenAction->data().toByteArray());

        showNormal();

        restoreGeometry(m_fullscreenAction->data().toByteArray());
    }

    if(s_settings->mainWindow().toggleToolAndMenuBarsWithFullscreen())
    {
        m_toggleToolBarsAction->trigger();
        m_toggleMenuBarAction->trigger();
    }
}

void MainWindow::on_presentation_triggered()
{
    currentTab()->startPresentation();
}

void MainWindow::on_previousTab_triggered()
{
    if(m_tabWidget->currentIndex() > 0)
    {
        m_tabWidget->setCurrentIndex(m_tabWidget->currentIndex() - 1);
    }
    else
    {
        m_tabWidget->setCurrentIndex(m_tabWidget->count() - 1);
    }
}

void MainWindow::on_nextTab_triggered()
{
    if(m_tabWidget->currentIndex() < m_tabWidget->count() - 1)
    {
        m_tabWidget->setCurrentIndex(m_tabWidget->currentIndex() + 1);
    }
    else
    {
        m_tabWidget->setCurrentIndex(0);
    }
}

void MainWindow::on_closeTab_triggered()
{
    if(saveModifications(currentTab()))
    {
        closeTab(currentTab());
    }
}

void MainWindow::on_closeAllTabs_triggered()
{
    disconnect(m_tabWidget, SIGNAL(currentChanged(int)), this, SLOT(on_tabWidget_currentChanged(int)));

    foreach(DocumentView* tab, tabs())
    {
        if(saveModifications(tab))
        {
            closeTab(tab);
        }
    }

    connect(m_tabWidget, SIGNAL(currentChanged(int)), this, SLOT(on_tabWidget_currentChanged(int)));

    on_tabWidget_currentChanged(m_tabWidget->currentIndex());
}

void MainWindow::on_closeAllTabsButCurrentTab_triggered()
{
    disconnect(m_tabWidget, SIGNAL(currentChanged(int)), this, SLOT(on_tabWidget_currentChanged(int)));

    DocumentView* tab = currentTab();

    const int oldIndex = m_tabWidget->currentIndex();
    const QString tabText = m_tabWidget->tabText(oldIndex);
    const QString tabToolTip = m_tabWidget->tabToolTip(oldIndex);

    m_tabWidget->removeTab(oldIndex);

    foreach(DocumentView* tab, tabs())
    {
        if(saveModifications(tab))
        {
            closeTab(tab);
        }
    }

    const int newIndex = m_tabWidget->addTab(tab, tabText);
    m_tabWidget->setTabToolTip(newIndex, tabToolTip);
    m_tabWidget->setCurrentIndex(newIndex);

    connect(m_tabWidget, SIGNAL(currentChanged(int)), this, SLOT(on_tabWidget_currentChanged(int)));

    on_tabWidget_currentChanged(m_tabWidget->currentIndex());
}

void MainWindow::on_recentlyClosed_tabActionTriggered(QAction* tabAction)
{
    DocumentView* tab = static_cast< DocumentView* >(tabAction->parent());

    tab->setParent(m_tabWidget);
    tab->setVisible(true);

    addTab(tab);
    m_tabsMenu->addAction(tabAction);
}

void MainWindow::on_tabAction_triggered()
{
    for(int index = 0; index < m_tabWidget->count(); ++index)
    {
        if(sender()->parent() == m_tabWidget->widget(index))
        {
            m_tabWidget->setCurrentIndex(index);

            break;
        }
    }
}

void MainWindow::on_tabShortcut_activated()
{
    for(int index = 0; index < 9; ++index)
    {
        if(sender() == m_tabShortcuts[index])
        {
            m_tabWidget->setCurrentIndex(index);

            break;
        }
    }
}

void MainWindow::on_previousBookmark_triggered()
{
    const BookmarkModel* model = bookmarkModelForCurrentTab();

    if(model != 0)
    {
        QList< int > pages;

        for(int row = 0, rowCount = model->rowCount(); row < rowCount; ++row)
        {
            pages.append(model->index(row).data(BookmarkModel::PageRole).toInt());
        }

        if(!pages.isEmpty())
        {
            qSort(pages);

            QList< int >::const_iterator lowerBound = --qLowerBound(pages, currentTab()->currentPage());

            if(lowerBound >= pages.constBegin())
            {
                currentTab()->jumpToPage(*lowerBound);
            }
            else
            {
                currentTab()->jumpToPage(pages.last());
            }
        }
    }
}

void MainWindow::on_nextBookmark_triggered()
{
    const BookmarkModel* model = bookmarkModelForCurrentTab();

    if(model != 0)
    {
        QList< int > pages;

        for(int row = 0, rowCount = model->rowCount(); row < rowCount; ++row)
        {
            pages.append(model->index(row).data(BookmarkModel::PageRole).toInt());
        }

        if(!pages.isEmpty())
        {
            qSort(pages);

            QList< int >::const_iterator upperBound = qUpperBound(pages, currentTab()->currentPage());

            if(upperBound < pages.constEnd())
            {
                currentTab()->jumpToPage(*upperBound);
            }
            else
            {
                currentTab()->jumpToPage(pages.first());
            }
        }
    }
}

void MainWindow::on_addBookmark_triggered()
{
    const QString& currentPageLabel = s_settings->mainWindow().usePageLabel() || currentTab()->hasFrontMatter()
            ? currentTab()->pageLabelFromNumber(currentTab()->currentPage())
            : currentTab()->defaultPageLabelFromNumber(currentTab()->currentPage());

    BookmarkItem bookmark(currentTab()->currentPage(), tr("Jump to page %1").arg(currentPageLabel));

    BookmarkModel* model = bookmarkModelForCurrentTab(false);

    if(model != 0)
    {
        model->findBookmark(bookmark);
    }

    QScopedPointer< BookmarkDialog > dialog(new BookmarkDialog(bookmark, this));

    if(dialog->exec() == QDialog::Accepted)
    {
        if(model == 0)
        {
            model = bookmarkModelForCurrentTab(true);

            m_bookmarksView->setModel(model);
        }

        model->addBookmark(bookmark);

        m_bookmarksMenuIsDirty = true;
        scheduleSaveBookmarks();
    }
}

void MainWindow::on_removeBookmark_triggered()
{
    BookmarkModel* model = bookmarkModelForCurrentTab();

    if(model != 0)
    {
        model->removeBookmark(BookmarkItem(currentTab()->currentPage()));

        if(model->isEmpty())
        {
            m_bookmarksView->setModel(0);

            BookmarkModel::forgetPath(currentTab()->fileInfo().absoluteFilePath());
        }

        m_bookmarksMenuIsDirty = true;
        scheduleSaveBookmarks();
    }
}

void MainWindow::on_removeAllBookmarks_triggered()
{
    m_bookmarksView->setModel(0);

    BookmarkModel::forgetAllPaths();

    m_bookmarksMenuIsDirty = true;
    scheduleSaveBookmarks();
}

void MainWindow::on_bookmarksMenu_aboutToShow()
{
    if(!m_bookmarksMenuIsDirty)
    {
        return;
    }

    m_bookmarksMenuIsDirty = false;


    m_bookmarksMenu->clear();

    m_bookmarksMenu->addActions(QList< QAction* >() << m_previousBookmarkAction << m_nextBookmarkAction);
    m_bookmarksMenu->addSeparator();
    m_bookmarksMenu->addActions(QList< QAction* >() << m_addBookmarkAction << m_removeBookmarkAction << m_removeAllBookmarksAction);
    m_bookmarksMenu->addSeparator();

    foreach(const QString& absoluteFilePath, BookmarkModel::knownPaths())
    {
        const BookmarkModel* model = BookmarkModel::fromPath(absoluteFilePath);

        BookmarkMenu* menu = new BookmarkMenu(QFileInfo(absoluteFilePath), m_bookmarksMenu);

        for(int row = 0, rowCount = model->rowCount(); row < rowCount; ++row)
        {
            const QModelIndex index = model->index(row);

            menu->addJumpToPageAction(index.data(BookmarkModel::PageRole).toInt(), index.data(BookmarkModel::LabelRole).toString());
        }

        connect(menu, SIGNAL(openTriggered(QString)), SLOT(on_bookmark_openTriggered(QString)));
        connect(menu, SIGNAL(openInNewTabTriggered(QString)), SLOT(on_bookmark_openInNewTabTriggered(QString)));
        connect(menu, SIGNAL(jumpToPageTriggered(QString,int)), SLOT(on_bookmark_jumpToPageTriggered(QString,int)));
        connect(menu, SIGNAL(removeBookmarkTriggered(QString)), SLOT(on_bookmark_removeBookmarkTriggered(QString)));

        m_bookmarksMenu->addMenu(menu);
    }
}

void MainWindow::on_bookmark_openTriggered(const QString& absoluteFilePath)
{
    if(m_tabWidget->currentIndex() != -1)
    {
        open(absoluteFilePath);
    }
    else
    {
        openInNewTab(absoluteFilePath);
    }
}

void MainWindow::on_bookmark_openInNewTabTriggered(const QString& absoluteFilePath)
{
    openInNewTab(absoluteFilePath);
}

void MainWindow::on_bookmark_jumpToPageTriggered(const QString& absoluteFilePath, int page)
{
    jumpToPageOrOpenInNewTab(absoluteFilePath, page);
}

void MainWindow::on_bookmark_removeBookmarkTriggered(const QString& absoluteFilePath)
{
    BookmarkModel* model = BookmarkModel::fromPath(absoluteFilePath);

    if(model == m_bookmarksView->model())
    {
        m_bookmarksView->setModel(0);
    }

    BookmarkModel::forgetPath(absoluteFilePath);

    m_bookmarksMenuIsDirty = true;
    scheduleSaveBookmarks();
}

void MainWindow::on_contents_triggered()
{
    if(m_helpDialog.isNull())
    {
        m_helpDialog = new HelpDialog();

        m_helpDialog->show();
        m_helpDialog->setAttribute(Qt::WA_DeleteOnClose);

        connect(this, SIGNAL(destroyed()), m_helpDialog, SLOT(close()));
    }

    m_helpDialog->raise();
    m_helpDialog->activateWindow();
}

void MainWindow::on_about_triggered()
{
    QMessageBox::about(this, tr("About qpdfview"), (tr("<p><b>qpdfview %1</b></p><p>qpdfview is a tabbed document viewer using Qt.</p>"
                                                      "<p>This version includes:"
                                                      "<ul>").arg(APPLICATION_VERSION)
#ifdef WITH_PDF
                                                      + tr("<li>PDF support using Poppler %1</li>").arg(POPPLER_VERSION)
#endif // WITH_PDF
#ifdef WITH_PS
                                                      + tr("<li>PS support using libspectre %1</li>").arg(LIBSPECTRE_VERSION)
#endif // WITH_PS
#ifdef WITH_DJVU
                                                      + tr("<li>DjVu support using DjVuLibre %1</li>").arg(DJVULIBRE_VERSION)
#endif // WITH_DJVU
#ifdef WITH_FITZ
                                                      + tr("<li>PDF support using Fitz %1</li>").arg(FITZ_VERSION)
#endif // WITH_FITZ
#ifdef WITH_CUPS
                                                      + tr("<li>Printing support using CUPS %1</li>").arg(CUPS_VERSION)
#endif // WITH_CUPS
                                                      + tr("</ul>"
                                                           "<p>See <a href=\"https://launchpad.net/qpdfview\">launchpad.net/qpdfview</a> for more information.</p><p>&copy; 2012-2014 The qpdfview developers</p>")));
}

QString MainWindow::currentPage_textFromValue(int value, bool* ok) const
{
    if(currentTab() == 0 || !(s_settings->mainWindow().usePageLabel() || currentTab()->hasFrontMatter()))
    {
        *ok = false;
        return QString();
    }

    *ok = true;
    return currentTab()->pageLabelFromNumber(value);
}

int MainWindow::currentPage_valueFromText(QString text, bool* ok) const
{
    if(currentTab() == 0 || !(s_settings->mainWindow().usePageLabel() || currentTab()->hasFrontMatter()))
    {
        *ok = false;
        return 0;
    }

    const QString& prefix = m_currentPageSpinBox->prefix();
    const QString& suffix = m_currentPageSpinBox->suffix();

    int from = 0;
    int size = text.size();

    if(!prefix.isEmpty() && text.startsWith(prefix))
    {
        from += prefix.size();
        size -= from;
    }

    if(!suffix.isEmpty() && text.endsWith(suffix))
    {
        size -= suffix.size();
    }

    text = text.mid(from, size).trimmed();

    *ok = true;
    return currentTab()->pageNumberFromLabel(text);
}

void MainWindow::on_focusCurrentPage_activated()
{
    m_currentPageSpinBox->setFocus();
    m_currentPageSpinBox->selectAll();
}

void MainWindow::on_focusScaleFactor_activated()
{
    m_scaleFactorComboBox->setFocus();
    m_scaleFactorComboBox->lineEdit()->selectAll();
}

void MainWindow::on_toggleToolBars_triggered(bool checked)
{
    if(checked)
    {
        m_tabWidget->setTabBarPolicy(static_cast< TabWidget::TabBarPolicy >(m_tabBarHadPolicy));

        m_fileToolBar->setVisible(m_fileToolBarWasVisible);
        m_editToolBar->setVisible(m_editToolBarWasVisible);
        m_viewToolBar->setVisible(m_viewToolBarWasVisible);
    }
    else
    {
        m_tabBarHadPolicy = static_cast< int >(m_tabWidget->tabBarPolicy());

        m_fileToolBarWasVisible = m_fileToolBar->isVisible();
        m_editToolBarWasVisible = m_editToolBar->isVisible();
        m_viewToolBarWasVisible = m_viewToolBar->isVisible();

        m_tabWidget->setTabBarPolicy(TabWidget::TabBarAlwaysOff);

        m_fileToolBar->setVisible(false);
        m_editToolBar->setVisible(false);
        m_viewToolBar->setVisible(false);
    }
}

void MainWindow::on_toggleMenuBar_triggered(bool checked)
{
/*	    menuBar()->setVisible(checked);*/
	    menuBar()->setMaximumHeight(checked ? QWIDGETSIZE_MAX : 0);
    createSearchDock();
}

void MainWindow::on_searchInitiated(const QString& text, bool modified)
{
    if(!text.isEmpty())
    {
        const bool allTabs = s_settings->mainWindow().extendedSearchDock() ? !modified : modified;

        if(allTabs)
        {
            for(int index = 0; index < m_tabWidget->count(); ++index)
            {
                tab(index)->startSearch(text, m_matchCaseCheckBox->isChecked());
            }
        }
        else
        {
            currentTab()->startSearch(text, m_matchCaseCheckBox->isChecked());
        }
    }
}

void MainWindow::on_highlightAll_clicked(bool checked)
{
    currentTab()->setHighlightAll(checked);
}

void MainWindow::on_dock_dockLocationChanged(Qt::DockWidgetArea area)
{
    QDockWidget* dock = qobject_cast< QDockWidget* >(sender());

    if(dock == 0)
    {
        return;
    }

    QDockWidget::DockWidgetFeatures features = dock->features();

    if(area == Qt::TopDockWidgetArea || area == Qt::BottomDockWidgetArea)
    {
        features |= QDockWidget::DockWidgetVerticalTitleBar;
    }
    else
    {
        features &= ~QDockWidget::DockWidgetVerticalTitleBar;
    }

    dock->setFeatures(features);
}

void MainWindow::on_outline_sectionCountChanged()
{
    if(m_outlineView->header()->count() > 0)
    {
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)

        m_outlineView->header()->setSectionResizeMode(0, QHeaderView::Stretch);

#else

        m_outlineView->header()->setResizeMode(0, QHeaderView::Stretch);

#endif // QT_VERSION
    }

    if(m_outlineView->header()->count() > 1)
    {
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)

        m_outlineView->header()->setSectionResizeMode(1, QHeaderView::ResizeToContents);

#else

        m_outlineView->header()->setResizeMode(1, QHeaderView::ResizeToContents);

#endif // QT_VERSION
    }

    m_outlineView->header()->setMinimumSectionSize(0);
    m_outlineView->header()->setStretchLastSection(false);
    m_outlineView->header()->setVisible(false);
}

void MainWindow::on_outline_clicked(const QModelIndex& index)
{
    bool ok = false;
    const int page = index.data(Qt::UserRole + 1).toInt(&ok);
    const qreal left = index.data(Qt::UserRole + 2).toReal();
    const qreal top = index.data(Qt::UserRole + 3).toReal();

    if(ok)
    {
        currentTab()->jumpToPage(page, true, left, top);
    }
}

void MainWindow::on_properties_sectionCountChanged()
{
    if(m_propertiesView->horizontalHeader()->count() > 0)
    {
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)

        m_propertiesView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

#else

        m_propertiesView->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);

#endif // QT_VERSION
    }

    if(m_propertiesView->horizontalHeader()->count() > 1)
    {
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)

        m_propertiesView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

#else

        m_propertiesView->horizontalHeader()->setResizeMode(1, QHeaderView::Stretch);

#endif // QT_VERSION
    }

    m_propertiesView->horizontalHeader()->setVisible(false);


    if(m_propertiesView->verticalHeader()->count() > 0)
    {
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)

        m_propertiesView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

#else

        m_propertiesView->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);

#endif // QT_VERSION
    }

    m_propertiesView->verticalHeader()->setVisible(false);
}

void MainWindow::on_thumbnails_dockLocationChanged(Qt::DockWidgetArea area)
{
    for(int index = 0; index < m_tabWidget->count(); ++index)
    {
        tab(index)->setThumbnailsOrientation(area == Qt::TopDockWidgetArea || area == Qt::BottomDockWidgetArea ? Qt::Horizontal : Qt::Vertical);
    }
}

void MainWindow::on_thumbnails_verticalScrollBar_valueChanged(int value)
{
    Q_UNUSED(value);

    if(m_thumbnailsView->scene() != 0)
    {
        const QRectF visibleRect = m_thumbnailsView->mapToScene(m_thumbnailsView->viewport()->rect()).boundingRect();

        foreach(ThumbnailItem* page, currentTab()->thumbnailItems())
        {
            if(!page->boundingRect().translated(page->pos()).intersects(visibleRect))
            {
                page->cancelRender();
            }
        }
    }
}

void MainWindow::on_bookmarks_sectionCountChanged()
{
    if(m_bookmarksView->horizontalHeader()->count() > 0)
    {
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)

        m_bookmarksView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

#else

        m_bookmarksView->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);

#endif // QT_VERSION
    }

    if(m_bookmarksView->horizontalHeader()->count() > 1)
    {
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)

        m_bookmarksView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);

#else

        m_bookmarksView->horizontalHeader()->setResizeMode(1, QHeaderView::ResizeToContents);

#endif // QT_VERSION
    }

    m_bookmarksView->horizontalHeader()->setMinimumSectionSize(0);
    m_bookmarksView->horizontalHeader()->setStretchLastSection(false);
    m_bookmarksView->horizontalHeader()->setVisible(false);

    if(m_bookmarksView->verticalHeader()->count() > 0)
    {
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)

        m_bookmarksView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

#else

        m_bookmarksView->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);

#endif // QT_VERSION
    }

    m_bookmarksView->verticalHeader()->setVisible(false);
}

void MainWindow::on_bookmarks_clicked(const QModelIndex& index)
{
    bool ok = false;
    const int page = index.data(BookmarkModel::PageRole).toInt(&ok);

    if(ok)
    {
        currentTab()->jumpToPage(page);
    }
}

void MainWindow::on_bookmarks_contextMenuRequested(const QPoint& pos)
{
    QMenu menu;

    menu.addActions(QList< QAction* >() << m_previousBookmarkAction << m_nextBookmarkAction);
    menu.addSeparator();
    menu.addAction(m_addBookmarkAction);

    QAction* removeBookmarkAction = menu.addAction(tr("&Remove bookmark"));
    QAction* editBookmarkAction = menu.addAction(tr("&Edit bookmark"));

    const QModelIndex index = m_bookmarksView->indexAt(pos);

    removeBookmarkAction->setVisible(index.isValid());
    editBookmarkAction->setVisible(index.isValid());

    const QAction* action = menu.exec(m_bookmarksView->mapToGlobal(pos));

    if(action == removeBookmarkAction)
    {
        BookmarkModel* model = qobject_cast< BookmarkModel* >(m_bookmarksView->model());

        if(model != 0)
        {
            model->removeBookmark(BookmarkItem(index.data(BookmarkModel::PageRole).toInt()));

            if(model->isEmpty())
            {
                m_bookmarksView->setModel(0);

                BookmarkModel::forgetPath(currentTab()->fileInfo().absoluteFilePath());
            }

            m_bookmarksMenuIsDirty = true;
            scheduleSaveBookmarks();
        }

    }
    else if(action == editBookmarkAction)
    {
        BookmarkModel* model = qobject_cast< BookmarkModel* >(m_bookmarksView->model());

        if(model != 0)
        {
            BookmarkItem bookmark(index.data(BookmarkModel::PageRole).toInt());

            model->findBookmark(bookmark);

            QScopedPointer< BookmarkDialog > dialog(new BookmarkDialog(bookmark, this));

            if(dialog->exec() == QDialog::Accepted)
            {
                model->addBookmark(bookmark);

                m_bookmarksMenuIsDirty = true;
                scheduleSaveBookmarks();
            }
        }
    }
}

void MainWindow::on_search_sectionCountChanged()
{
    if(m_searchView->header()->count() > 0)
    {
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)

        m_searchView->header()->setSectionResizeMode(0, QHeaderView::Stretch);

#else

        m_searchView->header()->setResizeMode(0, QHeaderView::Stretch);

#endif // QT_VERSION
    }

    m_searchView->header()->setMinimumSectionSize(0);
    m_searchView->header()->setStretchLastSection(false);
    m_searchView->header()->setVisible(false);
}

void MainWindow::on_search_visibilityChanged(bool visible)
{
    if(!visible)
    {
        m_searchLineEdit->stopTimer();
        m_searchLineEdit->setProgress(0);

        for(int index = 0; index < m_tabWidget->count(); ++index)
        {
            tab(index)->cancelSearch();
            tab(index)->clearResults();
        }

        if(m_tabWidget->currentWidget() != 0)
        {
            m_tabWidget->currentWidget()->setFocus();
        }
    }
}

void MainWindow::on_search_clicked(const QModelIndex& index)
{
    DocumentView* tab = SearchModel::instance()->viewForIndex(index);

    m_tabWidget->setCurrentWidget(tab);

    tab->findResult(index);
}

void MainWindow::on_database_tabRestored(const QString& absoluteFilePath, bool continuousMode, LayoutMode layoutMode, bool rightToLeftMode, ScaleMode scaleMode, qreal scaleFactor, Rotation rotation, int currentPage)
{
    if(openInNewTab(absoluteFilePath))
    {
        currentTab()->setContinuousMode(continuousMode);
        currentTab()->setLayoutMode(layoutMode);
        currentTab()->setRightToLeftMode(rightToLeftMode);

        currentTab()->setScaleMode(scaleMode);
        currentTab()->setScaleFactor(scaleFactor);

        currentTab()->setRotation(rotation);

        currentTab()->jumpToPage(currentPage);
    }
}

void MainWindow::on_saveDatabase_timeout()
{
    if(s_settings->mainWindow().restoreTabs())
    {
        s_database->saveTabs(tabs());
    }

    if(s_settings->mainWindow().restoreBookmarks())
    {
        s_database->saveBookmarks();
    }

    if(s_settings->mainWindow().restorePerFileSettings())
    {
        foreach(DocumentView* tab, tabs())
        {
            s_database->savePerFileSettings(tab);
        }
    }
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    m_searchDock->setVisible(false);

    for(int index = 0; index < m_tabWidget->count(); ++index)
    {
        if(!saveModifications(tab(index)))
        {
            m_tabWidget->setCurrentIndex(index);

            event->setAccepted(false);
            return;
        }
    }

    if(s_settings->mainWindow().restoreTabs())
    {
        s_database->saveTabs(tabs());
    }
    else
    {
        s_database->clearTabs();
    }

    if(s_settings->mainWindow().restoreBookmarks())
    {
        s_database->saveBookmarks();
    }
    else
    {
        s_database->clearBookmarks();
    }

    s_settings->mainWindow().setRecentlyUsed(s_settings->mainWindow().trackRecentlyUsed() ? m_recentlyUsedMenu->filePaths() : QStringList());

    s_settings->documentView().setMatchCase(m_matchCaseCheckBox->isChecked());

    s_settings->mainWindow().setGeometry(m_fullscreenAction->isChecked() ? m_fullscreenAction->data().toByteArray() : saveGeometry());
    s_settings->mainWindow().setState(saveState());

    QMainWindow::closeEvent(event);
}

void MainWindow::dragEnterEvent(QDragEnterEvent* event)
{
    if(event->mimeData()->hasUrls())
    {
        event->acceptProposedAction();
    }
}

void MainWindow::dropEvent(QDropEvent* event)
{
    if(event->mimeData()->hasUrls())
    {
        event->acceptProposedAction();

        disconnect(m_tabWidget, SIGNAL(currentChanged(int)), this, SLOT(on_tabWidget_currentChanged(int)));

        foreach(const QUrl& url, event->mimeData()->urls())
        {
#if QT_VERSION >= QT_VERSION_CHECK(4,8,0)
            if(url.isLocalFile())
#else
            if(url.scheme() == "file")
#endif // QT_VERSION
            {
                openInNewTab(url.toLocalFile());
            }
        }

        connect(m_tabWidget, SIGNAL(currentChanged(int)), this, SLOT(on_tabWidget_currentChanged(int)));

        on_tabWidget_currentChanged(m_tabWidget->currentIndex());
    }
}

void MainWindow::prepareStyle()
{
    if(s_settings->mainWindow().hasIconTheme())
    {
        QIcon::setThemeName(s_settings->mainWindow().iconTheme());
    }

    if(s_settings->mainWindow().hasStyleSheet())
    {
        qApp->setStyleSheet(s_settings->mainWindow().styleSheet());
    }

    ProxyStyle* style = new ProxyStyle();

    style->setScrollableMenus(s_settings->mainWindow().scrollableMenus());

    qApp->setStyle(style);
}

TreeView* MainWindow::outlineView() const
{
    return m_outlineView;
}

DocumentView* MainWindow::currentTab() const
{
    return qobject_cast< DocumentView* >(m_tabWidget->currentWidget());
}

DocumentView* MainWindow::tab(int index) const
{
    return qobject_cast< DocumentView* >(m_tabWidget->widget(index));
}

QList< DocumentView* > MainWindow::tabs() const
{
    QList< DocumentView* > tabs;

    for(int index = 0; index < m_tabWidget->count(); ++index)
    {
        tabs.append(tab(index));
    }

    return tabs;
}

bool MainWindow::senderIsCurrentTab() const
{
     return sender() == m_tabWidget->currentWidget() || qobject_cast< DocumentView* >(sender()) == 0;
}

int MainWindow::addTab(DocumentView* tab)
{
    const int index = s_settings->mainWindow().newTabNextToCurrentTab() ?
                m_tabWidget->insertTab(m_tabWidget->currentIndex() + 1, tab, tab->title()) :
                m_tabWidget->addTab(tab, tab->title());

    m_tabWidget->setTabToolTip(index, tab->fileInfo().absoluteFilePath());
    m_tabWidget->setCurrentIndex(index);

    return index;
}

void MainWindow::closeTab(DocumentView* tab)
{
    if(s_settings->mainWindow().keepRecentlyClosed())
    {
        foreach(QAction* tabAction, m_tabsMenu->actions())
        {
            if(tabAction->parent() == tab)
            {
                m_tabsMenu->removeAction(tabAction);
                m_tabWidget->removeTab(m_tabWidget->indexOf(tab));

                tab->setParent(this);
                tab->setVisible(false);

                m_recentlyClosedMenu->addTabAction(tabAction);

                break;
            }
        }
    }
    else
    {
        delete tab;
    }

    if(s_settings->mainWindow().exitAfterLastTab() && m_tabWidget->count() == 0)
    {
        close();
    }
}

bool MainWindow::saveModifications(DocumentView* tab)
{
    s_database->savePerFileSettings(tab);
    scheduleSaveTabs();

    if(tab->wasModified())
    {
        const int button = QMessageBox::warning(this, tr("Warning"), tr("The document '%1' has been modified. Do you want to save your changes?").arg(tab->fileInfo().filePath()), QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel, QMessageBox::Save);

        if(button == QMessageBox::Save)
        {
            const QString filePath = QFileDialog::getSaveFileName(this, tr("Save as"), tab->fileInfo().filePath(), tab->saveFilter().join(";;"));

            if(!filePath.isEmpty())
            {
                if(tab->save(filePath, true))
                {
                    return true;
                }
                else
                {
                    QMessageBox::warning(this, tr("Warning"), tr("Could not save as '%1'.").arg(filePath));
                }
            }
        }
        else if(button == QMessageBox::Discard)
        {
            return true;
        }

        return false;
    }

    return true;
}

void MainWindow::setWindowTitleForCurrentTab()
{
    QString currentPage;
    QString tabText;
    QString instanceName;

    if(m_tabWidget->currentIndex() != -1)
    {
        if(s_settings->mainWindow().currentPageInWindowTitle())
        {
            currentPage = QString(" (%1 / %2)").arg(currentTab()->currentPage()).arg(currentTab()->numberOfPages());
        }

        tabText = m_tabWidget->tabText(m_tabWidget->currentIndex()) + currentPage + QLatin1String(" - ");
    }

    if(s_settings->mainWindow().instanceNameInWindowTitle() && !qApp->objectName().isEmpty())
    {
        instanceName = QLatin1String(" (") + qApp->objectName() + QLatin1String(")");
    }

    setWindowTitle(tabText + QLatin1String("qpdfview") + instanceName);
}

void MainWindow::setCurrentPageSuffixForCurrentTab()
{
    QString suffix;

    if(m_tabWidget->currentIndex() != -1)
    {
        const int currentPage = currentTab()->currentPage();
        const int numberOfPages = currentTab()->numberOfPages();

        const QString& defaultPageLabel = currentTab()->defaultPageLabelFromNumber(currentPage);
        const QString& pageLabel = currentTab()->pageLabelFromNumber(currentPage);

        const QString& lastDefaultPageLabel = currentTab()->defaultPageLabelFromNumber(numberOfPages);

        if((s_settings->mainWindow().usePageLabel() || currentTab()->hasFrontMatter()) && defaultPageLabel != pageLabel)
        {
            suffix = QString(" (%1 / %2)").arg(defaultPageLabel).arg(lastDefaultPageLabel);
        }
        else
        {
            suffix = QString(" / %1").arg(lastDefaultPageLabel);
        }
    }
    else
    {
        suffix = QLatin1String(" / 1");
    }

    m_currentPageSpinBox->setSuffix(suffix);
}

BookmarkModel* MainWindow::bookmarkModelForCurrentTab(bool create)
{
    return BookmarkModel::fromPath(currentTab()->fileInfo().absoluteFilePath(), create);
}

void MainWindow::prepareDatabase()
{
    if(s_database == 0)
    {
        s_database = Database::instance();
    }

    connect(s_database, SIGNAL(tabRestored(QString,bool,LayoutMode,bool,ScaleMode,qreal,Rotation,int)), SLOT(on_database_tabRestored(QString,bool,LayoutMode,bool,ScaleMode,qreal,Rotation,int)));

    m_saveDatabaseTimer = new QTimer(this);
    m_saveDatabaseTimer->setSingleShot(true);
    m_saveDatabaseTimer->setInterval(s_settings->mainWindow().saveDatabaseInterval());

    connect(m_saveDatabaseTimer, SIGNAL(timeout()), SLOT(on_saveDatabase_timeout()));
}

void MainWindow::scheduleSaveDatabase()
{
    if(m_saveDatabaseTimer->interval() > 0 && !m_saveDatabaseTimer->isActive())
    {
        m_saveDatabaseTimer->start();
    }
}

void MainWindow::scheduleSaveTabs()
{
    if(s_settings->mainWindow().restoreTabs())
    {
        scheduleSaveDatabase();
    }
}

void MainWindow::scheduleSaveBookmarks()
{
    if(s_settings->mainWindow().restoreBookmarks())
    {
        scheduleSaveDatabase();
    }
}

void MainWindow::scheduleSavePerFileSettings()
{
    if(s_settings->mainWindow().restorePerFileSettings())
    {
        scheduleSaveDatabase();
    }
}

void MainWindow::createWidgets()
{
    m_tabWidget = new TabWidget(this);

    m_tabWidget->setDocumentMode(true);
    m_tabWidget->setMovable(true);
    m_tabWidget->setTabsClosable(true);
    m_tabWidget->setElideMode(Qt::ElideRight);

    m_tabWidget->setTabPosition(static_cast< QTabWidget::TabPosition >(s_settings->mainWindow().tabPosition()));
    m_tabWidget->setTabBarPolicy(static_cast< TabWidget::TabBarPolicy >(s_settings->mainWindow().tabVisibility()));
    m_tabWidget->setSpreadTabs(s_settings->mainWindow().spreadTabs());

    setCentralWidget(m_tabWidget);

    connect(m_tabWidget, SIGNAL(currentChanged(int)), SLOT(on_tabWidget_currentChanged(int)));
    connect(m_tabWidget, SIGNAL(tabCloseRequested(int)), SLOT(on_tabWidget_tabCloseRequested(int)));
    connect(m_tabWidget, SIGNAL(tabContextMenuRequested(QPoint,int)), SLOT(on_tabWidget_tabContextMenuRequested(QPoint,int)));

    // current page

    m_currentPageSpinBox = new MappingSpinBox(this, SLOT(currentPage_textFromValue(int,bool*)), SLOT(currentPage_valueFromText(QString,bool*)), this);

    m_currentPageSpinBox->setAlignment(Qt::AlignCenter);
    m_currentPageSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
    m_currentPageSpinBox->setKeyboardTracking(false);

    connect(m_currentPageSpinBox, SIGNAL(editingFinished()), SLOT(on_currentPage_editingFinished()));
    connect(m_currentPageSpinBox, SIGNAL(returnPressed()), SLOT(on_currentPage_returnPressed()));

    m_currentPageAction = new QWidgetAction(this);

    m_currentPageAction->setObjectName(QLatin1String("currentPage"));
    m_currentPageAction->setDefaultWidget(m_currentPageSpinBox);

    // scale factor

    m_scaleFactorComboBox = new ComboBox(this);

    m_scaleFactorComboBox->setEditable(true);
    m_scaleFactorComboBox->setInsertPolicy(QComboBox::NoInsert);

    m_scaleFactorComboBox->addItem(tr("Page width"));
    m_scaleFactorComboBox->addItem(tr("Page size"));
    m_scaleFactorComboBox->addItem("50 %", 0.5);
    m_scaleFactorComboBox->addItem("75 %", 0.75);
    m_scaleFactorComboBox->addItem("100 %", 1.0);
    m_scaleFactorComboBox->addItem("125 %", 1.25);
    m_scaleFactorComboBox->addItem("150 %", 1.5);
    m_scaleFactorComboBox->addItem("200 %", 2.0);
    m_scaleFactorComboBox->addItem("300 %", 3.0);
    m_scaleFactorComboBox->addItem("400 %", 4.0);
    m_scaleFactorComboBox->addItem("500 %", 5.0);

    connect(m_scaleFactorComboBox, SIGNAL(activated(int)), SLOT(on_scaleFactor_activated(int)));
    connect(m_scaleFactorComboBox->lineEdit(), SIGNAL(editingFinished()), SLOT(on_scaleFactor_editingFinished()));
    connect(m_scaleFactorComboBox->lineEdit(), SIGNAL(returnPressed()), SLOT(on_scaleFactor_returnPressed()));

    m_scaleFactorAction = new QWidgetAction(this);

    m_scaleFactorAction->setObjectName(QLatin1String("scaleFactor"));
    m_scaleFactorAction->setDefaultWidget(m_scaleFactorComboBox);

    // search

    m_searchLineEdit = new SearchLineEdit(this);
    m_matchCaseCheckBox = new QCheckBox(tr("Match &case"), this);
    m_highlightAllCheckBox = new QCheckBox(tr("Highlight &all"), this);

    connect(m_searchLineEdit, SIGNAL(searchInitiated(QString,bool)), SLOT(on_searchInitiated(QString,bool)));
    connect(m_highlightAllCheckBox, SIGNAL(clicked(bool)), SLOT(on_highlightAll_clicked(bool)));
}

QAction* MainWindow::createAction(const QString& text, const QString& objectName, const QIcon& icon, const QKeySequence& shortcut, const char* member, bool checkable, bool checked)
{
    QAction* action = new QAction(text, this);

    action->setObjectName(objectName);
    action->setIcon(icon);
    action->setShortcut(shortcut);

    if(!objectName.isEmpty())
    {
        ShortcutHandler::instance()->registerAction(action);
    }

    if(checkable)
    {
        action->setCheckable(true);
        action->setChecked(checked);

        connect(action, SIGNAL(triggered(bool)), member);
    }
    else
    {
        action->setIconVisibleInMenu(true);

        connect(action, SIGNAL(triggered()), member);
    }

    addAction(action);

    return action;
}

QAction* MainWindow::createAction(const QString& text, const QString& objectName, const QString& iconName, const QKeySequence& shortcut, const char* member, bool checkable, bool checked)
{
    return createAction(text, objectName, QIcon::fromTheme(iconName, QIcon(QLatin1String(":icons/") + iconName + QLatin1String(".svg"))), shortcut, member, checkable, checked);
}

void MainWindow::createActions()
{
    // file

    m_openAction = createAction(tr("&Open..."), QLatin1String("open"), QLatin1String("document-open"), QKeySequence::Open, SLOT(on_open_triggered()));
    m_openInNewTabAction = createAction(tr("Open in new &tab..."), QLatin1String("openInNewTab"), QLatin1String("tab-new"), QKeySequence::AddTab, SLOT(on_openInNewTab_triggered()));
    m_openCopyInNewTabAction = createAction(tr("Open &copy in new tab"), QLatin1String("openCopyInNewTab"), QIcon(), QKeySequence(), SLOT(on_openCopyInNewTab_triggered()));
    m_openContainingFolderAction = createAction(tr("Open containing &folder"), QLatin1String("openContainingFolder"), QLatin1String("folder"), QKeySequence(), SLOT(on_openContainingFolder_triggered()));
    m_refreshAction = createAction(tr("&Refresh"), QLatin1String("refresh"), QLatin1String("view-refresh"), QKeySequence::Refresh, SLOT(on_refresh_triggered()));
    m_saveCopyAction = createAction(tr("&Save copy..."), QLatin1String("saveCopy"), QLatin1String("document-save"), QKeySequence::Save, SLOT(on_saveCopy_triggered()));
    m_saveAsAction = createAction(tr("Save &as..."), QLatin1String("saveAs"), QLatin1String("document-save-as"), QKeySequence::SaveAs, SLOT(on_saveAs_triggered()));
    m_printAction = createAction(tr("&Print..."), QLatin1String("print"), QLatin1String("document-print"), QKeySequence::Print, SLOT(on_print_triggered()));
    m_exitAction = createAction(tr("E&xit"), QLatin1String("exit"), QIcon::fromTheme("application-exit"), QKeySequence::Quit, SLOT(close()));

    // edit

    m_previousPageAction = createAction(tr("&Previous page"), QLatin1String("previousPage"), QLatin1String("go-previous"), QKeySequence(Qt::Key_Backspace), SLOT(on_previousPage_triggered()));
    m_nextPageAction = createAction(tr("&Next page"), QLatin1String("nextPage"), QLatin1String("go-next"), QKeySequence(Qt::Key_Space), SLOT(on_nextPage_triggered()));
    m_firstPageAction = createAction(tr("&First page"), QLatin1String("firstPage"), QLatin1String("go-first"), QKeySequence(Qt::Key_Home), SLOT(on_firstPage_triggered()));
    m_lastPageAction = createAction(tr("&Last page"), QLatin1String("lastPage"), QLatin1String("go-last"), QKeySequence(Qt::Key_End), SLOT(on_lastPage_triggered()));

    m_setFirstPageAction = createAction(tr("&Set first page..."), QString(), QIcon(), QKeySequence(), SLOT(on_setFirstPage_triggered()));

    m_jumpToPageAction = createAction(tr("&Jump to page..."), QLatin1String("jumpToPage"), QLatin1String("go-jump"), QKeySequence(Qt::CTRL + Qt::Key_J), SLOT(on_jumpToPage_triggered()));

    m_jumpBackwardAction = createAction(tr("Jump &backward"), QLatin1String("jumpBackward"), QLatin1String("media-seek-backward"), QKeySequence(Qt::CTRL + Qt::Key_Return), SLOT(on_jumpBackward_triggered()));
    m_jumpForwardAction = createAction(tr("Jump for&ward"), QLatin1String("jumpForward"), QLatin1String("media-seek-forward"), QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_Return), SLOT(on_jumpForward_triggered()));

    m_searchAction = createAction(tr("&Search..."), QLatin1String("search"), QLatin1String("edit-find"), QKeySequence::Find, SLOT(on_search_triggered()));
    m_findPreviousAction = createAction(tr("Find previous"), QLatin1String("findPrevious"), QLatin1String("go-up"), QKeySequence::FindPrevious, SLOT(on_findPrevious_triggered()));
    m_findNextAction = createAction(tr("Find next"), QLatin1String("findNext"), QLatin1String("go-down"), QKeySequence::FindNext, SLOT(on_findNext_triggered()));
    m_cancelSearchAction = createAction(tr("Cancel search"), QLatin1String("cancelSearch"), QLatin1String("process-stop"), QKeySequence(Qt::Key_Escape), SLOT(on_cancelSearch_triggered()));

    m_copyToClipboardModeAction = createAction(tr("&Copy to clipboard"), QLatin1String("copyToClipboardMode"), QLatin1String("edit-copy"), QKeySequence(Qt::CTRL + Qt::Key_C), SLOT(on_copyToClipboardMode_triggered(bool)), true);
    m_addAnnotationModeAction = createAction(tr("&Add annotation"), QLatin1String("addAnnotationMode"), QLatin1String("mail-attachment"), QKeySequence(Qt::CTRL + Qt::Key_A), SLOT(on_addAnnotationMode_triggered(bool)), true);

    m_settingsAction = createAction(tr("Settings..."), QString(), QIcon(), QKeySequence(), SLOT(on_settings_triggered()));

    // view

    m_continuousModeAction = createAction(tr("&Continuous"), QLatin1String("continuousMode"), QIcon(":icons/continuous.svg"), QKeySequence(Qt::CTRL + Qt::Key_7), SLOT(on_continuousMode_triggered(bool)), true);
    m_twoPagesModeAction = createAction(tr("&Two pages"), QLatin1String("twoPagesMode"), QIcon(":icons/two-pages.svg"), QKeySequence(Qt::CTRL + Qt::Key_6), SLOT(on_twoPagesMode_triggered(bool)), true);
    m_twoPagesWithCoverPageModeAction = createAction(tr("Two pages &with cover page"), QLatin1String("twoPagesWithCoverPageMode"), QIcon(":icons/two-pages-with-cover-page.svg"), QKeySequence(Qt::CTRL + Qt::Key_5), SLOT(on_twoPagesWithCoverPageMode_triggered(bool)), true);
    m_multiplePagesModeAction = createAction(tr("&Multiple pages"), QLatin1String("multiplePagesMode"), QIcon(":icons/multiple-pages.svg"), QKeySequence(Qt::CTRL + Qt::Key_4), SLOT(on_multiplePagesMode_triggered(bool)), true);

    m_rightToLeftModeAction = createAction(tr("Right to left"), QLatin1String("rightToLeftMode"), QIcon(":icons/right-to-left.svg"), QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_R), SLOT(on_rightToLeftMode_triggered(bool)), true);

    m_zoomInAction = createAction(tr("Zoom &in"), QLatin1String("zoomIn"), QLatin1String("zoom-in"), QKeySequence(Qt::CTRL + Qt::Key_Up), SLOT(on_zoomIn_triggered()));
    m_zoomOutAction = createAction(tr("Zoom &out"), QLatin1String("zoomOut"), QLatin1String("zoom-out"), QKeySequence(Qt::CTRL + Qt::Key_Down), SLOT(on_zoomOut_triggered()));
    m_originalSizeAction = createAction(tr("Original &size"), QLatin1String("originalSize"), QLatin1String("zoom-original"), QKeySequence(Qt::CTRL + Qt::Key_0), SLOT(on_originalSize_triggered()));

    m_fitToPageWidthModeAction = createAction(tr("Fit to page width"), QLatin1String("fitToPageWidthMode"), QIcon(":icons/fit-to-page-width.svg"), QKeySequence(Qt::CTRL + Qt::Key_9), SLOT(on_fitToPageWidthMode_triggered(bool)), true);
    m_fitToPageSizeModeAction = createAction(tr("Fit to page size"), QLatin1String("fitToPageSizeMode"), QIcon(":icons/fit-to-page-size.svg"), QKeySequence(Qt::CTRL + Qt::Key_8), SLOT(on_fitToPageSizeMode_triggered(bool)), true);

    m_rotateLeftAction = createAction(tr("Rotate &left"), QLatin1String("rotateLeft"), QLatin1String("object-rotate-left"), QKeySequence(Qt::CTRL + Qt::Key_Left), SLOT(on_rotateLeft_triggered()));
    m_rotateRightAction = createAction(tr("Rotate &right"), QLatin1String("rotateRight"), QLatin1String("object-rotate-right"), QKeySequence(Qt::CTRL + Qt::Key_Right), SLOT(on_rotateRight_triggered()));

    m_invertColorsAction = createAction(tr("Invert colors"), QLatin1String("invertColors"), QIcon(), QKeySequence(Qt::CTRL + Qt::Key_I), SLOT(on_invertColors_triggered(bool)), true);
    m_convertToGrayscaleAction = createAction(tr("Convert to grayscale"), QLatin1String("convertToGrayscale"), QIcon(), QKeySequence(Qt::CTRL + Qt::Key_U), SLOT(on_convertToGrayscale_triggered(bool)), true);

    m_fontsAction = createAction(tr("Fonts..."), QString(), QIcon(), QKeySequence(), SLOT(on_fonts_triggered()));

    m_fullscreenAction = createAction(tr("&Fullscreen"), QLatin1String("fullscreen"), QLatin1String("view-fullscreen"), QKeySequence(Qt::Key_F11), SLOT(on_fullscreen_triggered(bool)), true);
    m_presentationAction = createAction(tr("&Presentation..."), QLatin1String("presentation"), QLatin1String("x-office-presentation"), QKeySequence(Qt::Key_F12), SLOT(on_presentation_triggered()));

    // tabs

    m_previousTabAction = createAction(tr("&Previous tab"), QLatin1String("previousTab"), QIcon(), QKeySequence::PreviousChild, SLOT(on_previousTab_triggered()));
    m_nextTabAction = createAction(tr("&Next tab"), QLatin1String("nextTab"), QIcon(), QKeySequence::NextChild, SLOT(on_nextTab_triggered()));

    m_closeTabAction = createAction(tr("&Close tab"), QLatin1String("closeTab"), QIcon::fromTheme("window-close"), QKeySequence(Qt::CTRL + Qt::Key_W), SLOT(on_closeTab_triggered()));
    m_closeAllTabsAction = createAction(tr("Close &all tabs"), QLatin1String("closeAllTabs"), QIcon(), QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_W), SLOT(on_closeAllTabs_triggered()));
    m_closeAllTabsButCurrentTabAction = createAction(tr("Close all tabs &but current tab"), QLatin1String("closeAllTabsButCurrent"), QIcon(), QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_W), SLOT(on_closeAllTabsButCurrentTab_triggered()));

    // tab shortcuts

    for(int index = 0; index < 9; ++index)
    {
        m_tabShortcuts[index] = new QShortcut(QKeySequence(Qt::ALT + Qt::Key_1 + index), this, SLOT(on_tabShortcut_activated()));
    }

    // bookmarks

    m_previousBookmarkAction = createAction(tr("&Previous bookmark"), QLatin1String("previousBookmarkAction"), QIcon(), QKeySequence(Qt::CTRL + Qt::Key_PageUp), SLOT(on_previousBookmark_triggered()));
    m_nextBookmarkAction = createAction(tr("&Next bookmark"), QLatin1String("nextBookmarkAction"), QIcon(), QKeySequence(Qt::CTRL + Qt::Key_PageDown), SLOT(on_nextBookmark_triggered()));

    m_addBookmarkAction = createAction(tr("&Add bookmark"), QLatin1String("addBookmark"), QIcon(), QKeySequence(Qt::CTRL + Qt::Key_B), SLOT(on_addBookmark_triggered()));
    m_removeBookmarkAction = createAction(tr("&Remove bookmark"), QLatin1String("removeBookmark"), QIcon(), QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_B), SLOT(on_removeBookmark_triggered()));
    m_removeAllBookmarksAction = createAction(tr("Remove all bookmarks"), QLatin1String("removeAllBookmark"), QIcon(), QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_B), SLOT(on_removeAllBookmarks_triggered()));

    // help

    m_contentsAction = createAction(tr("&Contents"), QLatin1String("contents"), QIcon::fromTheme("help-contents"), QKeySequence::HelpContents, SLOT(on_contents_triggered()));
    m_aboutAction = createAction(tr("&About"), QString(), QIcon::fromTheme("help-about"), QKeySequence(), SLOT(on_about_triggered()));
}

QToolBar* MainWindow::createToolBar(const QString& text, const QString& objectName, const QStringList& actionNames, const QList< QAction* >& actions)
{
    QToolBar* toolBar = addToolBar(text);
    toolBar->setObjectName(objectName);

    foreach(const QString& actionName, actionNames)
    {
        if(actionName == QLatin1String("separator"))
        {
            toolBar->addSeparator();

            continue;
        }

        foreach(QAction* action, actions)
        {
            if(actionName == action->objectName())
            {
                toolBar->addAction(action);

                break;
            }
        }
    }

    toolBar->toggleViewAction()->setObjectName(objectName + QLatin1String("ToggleView"));
    ShortcutHandler::instance()->registerAction(toolBar->toggleViewAction());

    return toolBar;
}

void MainWindow::createToolBars()
{
    m_fileToolBar = createToolBar(tr("&File"), QLatin1String("fileToolBar"), s_settings->mainWindow().fileToolBar(),
                                  QList< QAction* >() << m_openAction << m_openInNewTabAction << m_openContainingFolderAction << m_refreshAction << m_saveCopyAction << m_saveAsAction << m_printAction);

    m_editToolBar = createToolBar(tr("&Edit"), QLatin1String("editToolBar"), s_settings->mainWindow().editToolBar(),
                                  QList< QAction* >() << m_currentPageAction << m_previousPageAction << m_nextPageAction << m_firstPageAction << m_lastPageAction << m_jumpToPageAction << m_searchAction << m_jumpBackwardAction << m_jumpForwardAction << m_copyToClipboardModeAction << m_addAnnotationModeAction);

    m_viewToolBar = createToolBar(tr("&View"), QLatin1String("viewToolBar"), s_settings->mainWindow().viewToolBar(),
                                  QList< QAction* >() << m_scaleFactorAction << m_continuousModeAction << m_twoPagesModeAction << m_twoPagesWithCoverPageModeAction << m_multiplePagesModeAction << m_rightToLeftModeAction << m_zoomInAction << m_zoomOutAction << m_originalSizeAction << m_fitToPageWidthModeAction << m_fitToPageSizeModeAction << m_rotateLeftAction << m_rotateRightAction << m_fullscreenAction << m_presentationAction);

    m_focusCurrentPageShortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_K), this, SLOT(on_focusCurrentPage_activated()));
    m_focusScaleFactorShortcut = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_L), this, SLOT(on_focusScaleFactor_activated()));
}

QDockWidget* MainWindow::createDock(const QString& text, const QString& objectName, const QKeySequence& toggleViewShortcut)
{
    QDockWidget* dock = new QDockWidget(text, this);
    dock->setObjectName(objectName);
    dock->setFeatures(QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetMovable);

#ifdef Q_OS_WIN

    dock->setWindowTitle(dock->windowTitle().remove(QLatin1Char('&')));

#endif // Q_OS_WIN

    addDockWidget(Qt::LeftDockWidgetArea, dock);

    connect(dock, SIGNAL(dockLocationChanged(Qt::DockWidgetArea)), SLOT(on_dock_dockLocationChanged(Qt::DockWidgetArea)));

    dock->toggleViewAction()->setObjectName(objectName + QLatin1String("ToggleView"));
    dock->toggleViewAction()->setShortcut(toggleViewShortcut);

    ShortcutHandler::instance()->registerAction(dock->toggleViewAction());

    dock->hide();

    return dock;
}

void MainWindow::createSearchDock()
{
    m_searchDock = new QDockWidget(tr("&Search"), this);
    m_searchDock->setObjectName(QLatin1String("searchDock"));
    m_searchDock->setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetVerticalTitleBar);

#ifdef Q_OS_WIN

    m_searchDock->setWindowTitle(m_searchDock->windowTitle().remove(QLatin1Char('&')));

#endif // Q_OS_WIN

    addDockWidget(Qt::BottomDockWidgetArea, m_searchDock);

    connect(m_searchDock, SIGNAL(dockLocationChanged(Qt::DockWidgetArea)), SLOT(on_dock_dockLocationChanged(Qt::DockWidgetArea)));
    connect(m_searchDock, SIGNAL(visibilityChanged(bool)), SLOT(on_search_visibilityChanged(bool)));

    m_searchWidget = new QWidget(this);

    QToolButton* findPreviousButton = new QToolButton(m_searchWidget);
    findPreviousButton->setAutoRaise(true);
    findPreviousButton->setDefaultAction(m_findPreviousAction);

    QToolButton* findNextButton = new QToolButton(m_searchWidget);
    findNextButton->setAutoRaise(true);
    findNextButton->setDefaultAction(m_findNextAction);

    QToolButton* cancelSearchButton = new QToolButton(m_searchWidget);
    cancelSearchButton->setAutoRaise(true);
    cancelSearchButton->setDefaultAction(m_cancelSearchAction);

    QGridLayout* searchLayout = new QGridLayout(m_searchWidget);
    searchLayout->setRowStretch(2, 1);
    searchLayout->setColumnStretch(2, 1);
    searchLayout->addWidget(m_searchLineEdit, 0, 0, 1, 6);
    searchLayout->addWidget(m_matchCaseCheckBox, 1, 0);
    searchLayout->addWidget(m_highlightAllCheckBox, 1, 1);
    searchLayout->addWidget(findPreviousButton, 1, 3);
    searchLayout->addWidget(findNextButton, 1, 4);
    searchLayout->addWidget(cancelSearchButton, 1, 5);

    m_searchDock->setWidget(m_searchWidget);

    connect(m_searchDock, SIGNAL(visibilityChanged(bool)), m_findPreviousAction, SLOT(setEnabled(bool)));
    connect(m_searchDock, SIGNAL(visibilityChanged(bool)), m_findNextAction, SLOT(setEnabled(bool)));
    connect(m_searchDock, SIGNAL(visibilityChanged(bool)), m_cancelSearchAction, SLOT(setEnabled(bool)));

    m_searchDock->setVisible(false);

    m_findPreviousAction->setEnabled(false);
    m_findNextAction->setEnabled(false);
    m_cancelSearchAction->setEnabled(false);

    if(s_settings->mainWindow().extendedSearchDock())
    {
        m_searchDock->setFeatures(m_searchDock->features() | QDockWidget::DockWidgetClosable);

        m_searchDock->toggleViewAction()->setObjectName(QLatin1String("searchDockToggleView"));
        m_searchDock->toggleViewAction()->setShortcut(QKeySequence(Qt::Key_F10));

        ShortcutHandler::instance()->registerAction(m_searchDock->toggleViewAction());

        m_searchView = new QTreeView(m_searchWidget);
        m_searchView->setAlternatingRowColors(true);
        m_searchView->setUniformRowHeights(true);
        m_searchView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        m_searchView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        m_searchView->setSelectionMode(QAbstractItemView::SingleSelection);
        m_searchView->setSelectionBehavior(QAbstractItemView::SelectRows);

        connect(m_searchView->header(), SIGNAL(sectionCountChanged(int,int)), SLOT(on_search_sectionCountChanged()));
        connect(m_searchView, SIGNAL(clicked(QModelIndex)), SLOT(on_search_clicked(QModelIndex)));
        connect(m_searchView, SIGNAL(activated(QModelIndex)), SLOT(on_search_clicked(QModelIndex)));

        m_searchView->setItemDelegate(new SearchItemDelegate(m_searchView));
        m_searchView->setModel(SearchModel::instance());

        searchLayout->addWidget(m_searchView, 2, 0, 1, 6);
    }
    else
    {
        m_searchView = 0;
    }
}

void MainWindow::createDocks()
{
    // outline

    m_outlineDock = createDock(tr("&Outline"), QLatin1String("outlineDock"), QKeySequence(Qt::Key_F6));

    m_outlineView = new TreeView(Qt::UserRole + 4, Qt::UserRole + 5, this);
    m_outlineView->setAlternatingRowColors(true);
    m_outlineView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_outlineView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    m_outlineView->setSelectionBehavior(QAbstractItemView::SelectRows);

    connect(m_outlineView->header(), SIGNAL(sectionCountChanged(int,int)), SLOT(on_outline_sectionCountChanged()));
    connect(m_outlineView, SIGNAL(clicked(QModelIndex)), SLOT(on_outline_clicked(QModelIndex)));
    connect(m_outlineView, SIGNAL(activated(QModelIndex)), SLOT(on_outline_clicked(QModelIndex)));

    m_outlineDock->setWidget(m_outlineView);

    // properties

    m_propertiesDock = createDock(tr("&Properties"), QLatin1String("propertiesDock"), QKeySequence(Qt::Key_F7));

    m_propertiesView = new QTableView(this);
    m_propertiesView->setAlternatingRowColors(true);
    m_propertiesView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_propertiesView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

    connect(m_propertiesView->horizontalHeader(), SIGNAL(sectionCountChanged(int,int)), SLOT(on_properties_sectionCountChanged()));

    m_propertiesDock->setWidget(m_propertiesView);

    // thumbnails

    m_thumbnailsDock = createDock(tr("Thumb&nails"), QLatin1String("thumbnailsDock"), QKeySequence(Qt::Key_F8));

    connect(m_thumbnailsDock, SIGNAL(dockLocationChanged(Qt::DockWidgetArea)), SLOT(on_thumbnails_dockLocationChanged(Qt::DockWidgetArea)));

    m_thumbnailsView = new QGraphicsView(this);

    connect(m_thumbnailsView->verticalScrollBar(), SIGNAL(valueChanged(int)), SLOT(on_thumbnails_verticalScrollBar_valueChanged(int)));

    m_thumbnailsDock->setWidget(m_thumbnailsView);

    // bookmarks

    m_bookmarksDock = createDock(tr("Book&marks"), QLatin1String("bookmarksDock"), QKeySequence(Qt::Key_F9));

    m_bookmarksView = new QTableView(this);
    m_bookmarksView->setShowGrid(false);
    m_bookmarksView->setAlternatingRowColors(true);
    m_bookmarksView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_bookmarksView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    m_bookmarksView->setSelectionMode(QAbstractItemView::SingleSelection);
    m_bookmarksView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_bookmarksView->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(m_bookmarksView->horizontalHeader(), SIGNAL(sectionCountChanged(int,int)), SLOT(on_bookmarks_sectionCountChanged()));
    connect(m_bookmarksView, SIGNAL(clicked(QModelIndex)), SLOT(on_bookmarks_clicked(QModelIndex)));
    connect(m_bookmarksView, SIGNAL(activated(QModelIndex)), SLOT(on_bookmarks_clicked(QModelIndex)));
    connect(m_bookmarksView, SIGNAL(customContextMenuRequested(QPoint)), SLOT(on_bookmarks_contextMenuRequested(QPoint)));

    m_bookmarksDock->setWidget(m_bookmarksView);

    // search

    createSearchDock();
}

void MainWindow::createMenus()
{
    // file

    m_fileMenu = menuBar()->addMenu(tr("&File"));
    m_fileMenu->addActions(QList< QAction* >() << m_openAction << m_openInNewTabAction << m_openContainingFolderAction);

    m_recentlyUsedMenu = new RecentlyUsedMenu(s_settings->mainWindow().recentlyUsed(), s_settings->mainWindow().recentlyUsedCount(), this);

    connect(m_recentlyUsedMenu, SIGNAL(openTriggered(QString)), SLOT(on_recentlyUsed_openTriggered(QString)));

    if(s_settings->mainWindow().trackRecentlyUsed())
    {
        m_fileMenu->addMenu(m_recentlyUsedMenu);

        setToolButtonMenu(m_fileToolBar, m_openAction, m_recentlyUsedMenu);
        setToolButtonMenu(m_fileToolBar, m_openInNewTabAction, m_recentlyUsedMenu);
    }

    m_fileMenu->addActions(QList< QAction* >() << m_refreshAction << m_saveCopyAction << m_saveAsAction << m_printAction);
    m_fileMenu->addSeparator();
    m_fileMenu->addAction(m_exitAction);

    // edit

    m_editMenu = menuBar()->addMenu(tr("&Edit"));
    m_editMenu->addActions(QList< QAction* >() << m_previousPageAction << m_nextPageAction << m_firstPageAction << m_lastPageAction << m_jumpToPageAction);
    m_editMenu->addSeparator();
    m_editMenu->addActions(QList< QAction* >() << m_jumpBackwardAction << m_jumpForwardAction);
    m_editMenu->addSeparator();
    m_editMenu->addActions(QList< QAction* >() << m_searchAction << m_findPreviousAction << m_findNextAction << m_cancelSearchAction);
    m_editMenu->addSeparator();
    m_editMenu->addActions(QList< QAction* >() << m_copyToClipboardModeAction << m_addAnnotationModeAction);
    m_editMenu->addSeparator();
    m_editMenu->addAction(m_settingsAction);

    // view

    m_viewMenu = menuBar()->addMenu(tr("&View"));
    m_viewMenu->addActions(QList< QAction* >() << m_continuousModeAction << m_twoPagesModeAction << m_twoPagesWithCoverPageModeAction << m_multiplePagesModeAction);
    m_viewMenu->addSeparator();
    m_viewMenu->addAction(m_rightToLeftModeAction);
    m_viewMenu->addSeparator();
    m_viewMenu->addActions(QList< QAction* >() << m_zoomInAction << m_zoomOutAction << m_originalSizeAction << m_fitToPageWidthModeAction << m_fitToPageSizeModeAction);
    m_viewMenu->addSeparator();
    m_viewMenu->addActions(QList< QAction* >() << m_rotateLeftAction << m_rotateRightAction);
    m_viewMenu->addSeparator();
    m_viewMenu->addActions(QList< QAction* >() << m_invertColorsAction << m_convertToGrayscaleAction);
    m_viewMenu->addSeparator();

    QMenu* toolBarsMenu = m_viewMenu->addMenu(tr("&Tool bars"));
    toolBarsMenu->addActions(QList< QAction* >() << m_fileToolBar->toggleViewAction() << m_editToolBar->toggleViewAction() << m_viewToolBar->toggleViewAction());

    QMenu* docksMenu = m_viewMenu->addMenu(tr("&Docks"));
    docksMenu->addActions(QList< QAction* >() << m_outlineDock->toggleViewAction() << m_propertiesDock->toggleViewAction() << m_thumbnailsDock->toggleViewAction() << m_bookmarksDock->toggleViewAction());

    if(s_settings->mainWindow().extendedSearchDock())
    {
        docksMenu->addAction(m_searchDock->toggleViewAction());
    }

    m_viewMenu->addAction(m_fontsAction);
    m_viewMenu->addSeparator();
    m_viewMenu->addActions(QList< QAction* >() << m_fullscreenAction << m_presentationAction);

    // tabs

    m_tabsMenu = menuBar()->addMenu(tr("&Tabs"));
    m_tabsMenu->addActions(QList< QAction* >() << m_previousTabAction << m_nextTabAction);
    m_tabsMenu->addSeparator();
    m_tabsMenu->addActions(QList< QAction* >() << m_closeTabAction << m_closeAllTabsAction << m_closeAllTabsButCurrentTabAction);

    m_recentlyClosedMenu = new RecentlyClosedMenu(s_settings->mainWindow().recentlyClosedCount(), this);

    connect(m_recentlyClosedMenu, SIGNAL(tabActionTriggered(QAction*)), SLOT(on_recentlyClosed_tabActionTriggered(QAction*)));

    if(s_settings->mainWindow().keepRecentlyClosed())
    {
        m_tabsMenu->addMenu(m_recentlyClosedMenu);
    }

    m_tabsMenu->addSeparator();

    // bookmarks

    m_bookmarksMenu = menuBar()->addMenu(tr("&Bookmarks"));

    connect(m_bookmarksMenu, SIGNAL(aboutToShow()), this, SLOT(on_bookmarksMenu_aboutToShow()));

    m_bookmarksMenuIsDirty = true;

    // help

    m_helpMenu = menuBar()->addMenu(tr("&Help"));
    m_helpMenu->addActions(QList< QAction* >() << m_contentsAction << m_aboutAction);
}

#ifdef WITH_DBUS

MainWindowAdaptor::MainWindowAdaptor(MainWindow* mainWindow) : QDBusAbstractAdaptor(mainWindow)
{
}

void MainWindowAdaptor::raiseAndActivate()
{
    mainWindow()->raise();
    mainWindow()->activateWindow();
}

bool MainWindowAdaptor::open(const QString& absoluteFilePath, int page, const QRectF& highlight, bool quiet)
{
    return mainWindow()->open(absoluteFilePath, page, highlight, quiet);
}

bool MainWindowAdaptor::openInNewTab(const QString& absoluteFilePath, int page, const QRectF& highlight, bool quiet)
{
    return mainWindow()->openInNewTab(absoluteFilePath, page, highlight, quiet);
}

bool MainWindowAdaptor::jumpToPageOrOpenInNewTab(const QString& absoluteFilePath, int page, bool refreshBeforeJump, const QRectF& highlight, bool quiet)
{
    return mainWindow()->jumpToPageOrOpenInNewTab(absoluteFilePath, page, refreshBeforeJump, highlight, quiet);
}

void MainWindowAdaptor::startSearch(const QString& text)
{
    mainWindow()->startSearch(text);
}

#define ONLY_IF_CURRENT_TAB if(mainWindow()->m_tabWidget->currentIndex() == -1) { return; }

void MainWindowAdaptor::previousPage()
{
    ONLY_IF_CURRENT_TAB

    mainWindow()->on_previousPage_triggered();
}

void MainWindowAdaptor::nextPage()
{
    ONLY_IF_CURRENT_TAB

    mainWindow()->on_nextPage_triggered();
}

void MainWindowAdaptor::firstPage()
{
    ONLY_IF_CURRENT_TAB

    mainWindow()->on_firstPage_triggered();
}

void MainWindowAdaptor::lastPage()
{
    ONLY_IF_CURRENT_TAB

    mainWindow()->on_lastPage_triggered();
}

void MainWindowAdaptor::previousBookmark()
{
    ONLY_IF_CURRENT_TAB

    mainWindow()->on_previousBookmark_triggered();
}

void MainWindowAdaptor::nextBookmark()
{
    ONLY_IF_CURRENT_TAB

    mainWindow()->on_nextBookmark_triggered();
}

bool MainWindowAdaptor::jumpToBookmark(const QString& label)
{
    if(mainWindow()->m_tabWidget->currentIndex() == -1) { return false; }

    const BookmarkModel* model = mainWindow()->bookmarkModelForCurrentTab();

    if(model != 0)
    {
        for(int row = 0, rowCount = model->rowCount(); row < rowCount; ++row)
        {
            const QModelIndex index = model->index(row);

            if(label == index.data(BookmarkModel::LabelRole).toString())
            {
                mainWindow()->currentTab()->jumpToPage(index.data(BookmarkModel::PageRole).toInt());

                return true;
            }
        }
    }

    return false;
}

void MainWindowAdaptor::continuousModeAction(bool checked)
{
    ONLY_IF_CURRENT_TAB

    mainWindow()->on_continuousMode_triggered(checked);
}

void MainWindowAdaptor::twoPagesModeAction(bool checked)
{
    ONLY_IF_CURRENT_TAB

    mainWindow()->on_twoPagesMode_triggered(checked);
}

void MainWindowAdaptor::twoPagesWithCoverPageModeAction(bool checked)
{
    ONLY_IF_CURRENT_TAB

    mainWindow()->on_twoPagesWithCoverPageMode_triggered(checked);
}

void MainWindowAdaptor::multiplePagesModeAction(bool checked)
{
    ONLY_IF_CURRENT_TAB

    mainWindow()->on_multiplePagesMode_triggered(checked);
}

void MainWindowAdaptor::fitToPageWidthModeAction(bool checked)
{
    ONLY_IF_CURRENT_TAB

    mainWindow()->on_fitToPageWidthMode_triggered(checked);
}

void MainWindowAdaptor::fitToPageSizeModeAction(bool checked)
{
    ONLY_IF_CURRENT_TAB

    mainWindow()->on_fitToPageSizeMode_triggered(checked);
}

void MainWindowAdaptor::invertColorsAction(bool checked)
{
    ONLY_IF_CURRENT_TAB

    mainWindow()->on_invertColors_triggered(checked);
}

void MainWindowAdaptor::fullscreenAction(bool checked)
{
    if(mainWindow()->m_fullscreenAction->isChecked() != checked)
    {
        mainWindow()->m_fullscreenAction->trigger();
    }
}

void MainWindowAdaptor::presentationAction()
{
    ONLY_IF_CURRENT_TAB

    mainWindow()->on_presentation_triggered();
}

void MainWindowAdaptor::closeTab()
{
    ONLY_IF_CURRENT_TAB

    mainWindow()->on_closeTab_triggered();
}

void MainWindowAdaptor::closeAllTabs()
{
    mainWindow()->on_closeAllTabs_triggered();
}

void MainWindowAdaptor::closeAllTabsButCurrentTab()
{
    mainWindow()->on_closeAllTabsButCurrentTab_triggered();
}

bool MainWindowAdaptor::closeTab(const QString& absoluteFilePath)
{
    if(mainWindow()->m_tabWidget->currentIndex() == -1) { return false; }

    const QFileInfo fileInfo(absoluteFilePath);

    foreach(DocumentView* tab, mainWindow()->tabs())
    {
        if(tab->fileInfo() == fileInfo)
        {
            if(mainWindow()->saveModifications(tab))
            {
                mainWindow()->closeTab(tab);
            }

            return true;
        }
    }

    return false;
}

MainWindow* MainWindowAdaptor::mainWindow() const
{
    return qobject_cast< MainWindow* >(parent());
}

# endif // WITH_DBUS

} // qpdfview
