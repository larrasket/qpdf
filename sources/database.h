/*

Copyright 2014 S. Razi Alavizadeh
Copyright 2013-2014 Adam Reichold

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

#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>

#ifdef WITH_SQL

#include <QSqlDatabase>

#endif // WITH_SQL

class QDateTime;

#include "global.h"

namespace qpdfview
{

class DocumentView;

class Database : public QObject
{
    Q_OBJECT

public:
    static Database* instance();
    ~Database();

    QStringList loadInstanceNames();

    void restoreTabs();
    void saveTabs(const QList< DocumentView* >& tabs);
    void clearTabs();

    void restoreBookmarks();
    void saveBookmarks();
    void clearBookmarks();

    void restorePerFileSettings(DocumentView* tab);
    void savePerFileSettings(const DocumentView* tab);

signals:
    void tabRestored(const QString& absoluteFilePath, bool continuousMode, LayoutMode layoutMode, bool rightToLeftMode, ScaleMode scaleMode, qreal scaleFactor, Rotation rotation, int currentPage);

private:
    Q_DISABLE_COPY(Database)

    static Database* s_instance;
    Database(QObject* parent = 0);

    static QString instanceName();

#ifdef WITH_SQL

    bool prepareTabs_v3();
    bool prepareBookmarks_v3();
    bool preparePerFileSettings_v3();

    void migrateTabs_v2_v3();
    void migrateTabs_v1_v3();
    void migrateBookmarks_v2_v3();
    void migrateBookmarks_v1_v3();
    void migratePerFileSettings_v2_v3();
    void migratePerFileSettings_v1_v3();

    void limitPerFileSettings();

    QSqlDatabase m_database;

#endif // WITH_SQL

};

} // qpdfview

#endif // DATABASE_H
