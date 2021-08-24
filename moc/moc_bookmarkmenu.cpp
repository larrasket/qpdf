/****************************************************************************
** Meta object code from reading C++ file 'bookmarkmenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../sources/bookmarkmenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bookmarkmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_qpdfview__BookmarkMenu_t {
    QByteArrayData data[14];
    char stringdata0[230];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qpdfview__BookmarkMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qpdfview__BookmarkMenu_t qt_meta_stringdata_qpdfview__BookmarkMenu = {
    {
QT_MOC_LITERAL(0, 0, 22), // "qpdfview::BookmarkMenu"
QT_MOC_LITERAL(1, 23, 13), // "openTriggered"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 8), // "filePath"
QT_MOC_LITERAL(4, 47, 21), // "openInNewTabTriggered"
QT_MOC_LITERAL(5, 69, 19), // "jumpToPageTriggered"
QT_MOC_LITERAL(6, 89, 4), // "page"
QT_MOC_LITERAL(7, 94, 23), // "removeBookmarkTriggered"
QT_MOC_LITERAL(8, 118, 17), // "on_open_triggered"
QT_MOC_LITERAL(9, 136, 25), // "on_openInNewTab_triggered"
QT_MOC_LITERAL(10, 162, 23), // "on_jumpToPage_triggered"
QT_MOC_LITERAL(11, 186, 8), // "QAction*"
QT_MOC_LITERAL(12, 195, 6), // "action"
QT_MOC_LITERAL(13, 202, 27) // "on_removeBookmark_triggered"

    },
    "qpdfview::BookmarkMenu\0openTriggered\0"
    "\0filePath\0openInNewTabTriggered\0"
    "jumpToPageTriggered\0page\0"
    "removeBookmarkTriggered\0on_open_triggered\0"
    "on_openInNewTab_triggered\0"
    "on_jumpToPage_triggered\0QAction*\0"
    "action\0on_removeBookmark_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qpdfview__BookmarkMenu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    1,   57,    2, 0x06 /* Public */,
       5,    2,   60,    2, 0x06 /* Public */,
       7,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   68,    2, 0x09 /* Protected */,
       9,    0,   69,    2, 0x09 /* Protected */,
      10,    1,   70,    2, 0x09 /* Protected */,
      13,    0,   73,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    6,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,

       0        // eod
};

void qpdfview::BookmarkMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BookmarkMenu *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->openTriggered((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->openInNewTabTriggered((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->jumpToPageTriggered((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->removeBookmarkTriggered((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_open_triggered(); break;
        case 5: _t->on_openInNewTab_triggered(); break;
        case 6: _t->on_jumpToPage_triggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 7: _t->on_removeBookmark_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BookmarkMenu::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BookmarkMenu::openTriggered)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BookmarkMenu::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BookmarkMenu::openInNewTabTriggered)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BookmarkMenu::*)(const QString & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BookmarkMenu::jumpToPageTriggered)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BookmarkMenu::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BookmarkMenu::removeBookmarkTriggered)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject qpdfview::BookmarkMenu::staticMetaObject = { {
    QMetaObject::SuperData::link<QMenu::staticMetaObject>(),
    qt_meta_stringdata_qpdfview__BookmarkMenu.data,
    qt_meta_data_qpdfview__BookmarkMenu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *qpdfview::BookmarkMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qpdfview::BookmarkMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qpdfview__BookmarkMenu.stringdata0))
        return static_cast<void*>(this);
    return QMenu::qt_metacast(_clname);
}

int qpdfview::BookmarkMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void qpdfview::BookmarkMenu::openTriggered(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void qpdfview::BookmarkMenu::openInNewTabTriggered(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void qpdfview::BookmarkMenu::jumpToPageTriggered(const QString & _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void qpdfview::BookmarkMenu::removeBookmarkTriggered(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
