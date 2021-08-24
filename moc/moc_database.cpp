/****************************************************************************
** Meta object code from reading C++ file 'database.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../sources/database.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'database.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_qpdfview__Database_t {
    QByteArrayData data[14];
    char stringdata0[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qpdfview__Database_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qpdfview__Database_t qt_meta_stringdata_qpdfview__Database = {
    {
QT_MOC_LITERAL(0, 0, 18), // "qpdfview::Database"
QT_MOC_LITERAL(1, 19, 11), // "tabRestored"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 16), // "absoluteFilePath"
QT_MOC_LITERAL(4, 49, 14), // "continuousMode"
QT_MOC_LITERAL(5, 64, 10), // "LayoutMode"
QT_MOC_LITERAL(6, 75, 10), // "layoutMode"
QT_MOC_LITERAL(7, 86, 15), // "rightToLeftMode"
QT_MOC_LITERAL(8, 102, 9), // "ScaleMode"
QT_MOC_LITERAL(9, 112, 9), // "scaleMode"
QT_MOC_LITERAL(10, 122, 11), // "scaleFactor"
QT_MOC_LITERAL(11, 134, 8), // "Rotation"
QT_MOC_LITERAL(12, 143, 8), // "rotation"
QT_MOC_LITERAL(13, 152, 11) // "currentPage"

    },
    "qpdfview::Database\0tabRestored\0\0"
    "absoluteFilePath\0continuousMode\0"
    "LayoutMode\0layoutMode\0rightToLeftMode\0"
    "ScaleMode\0scaleMode\0scaleFactor\0"
    "Rotation\0rotation\0currentPage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qpdfview__Database[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    8,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, 0x80000000 | 5, QMetaType::Bool, 0x80000000 | 8, QMetaType::QReal, 0x80000000 | 11, QMetaType::Int,    3,    4,    6,    7,    9,   10,   12,   13,

       0        // eod
};

void qpdfview::Database::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Database *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->tabRestored((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< LayoutMode(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< ScaleMode(*)>(_a[5])),(*reinterpret_cast< qreal(*)>(_a[6])),(*reinterpret_cast< Rotation(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Database::*)(const QString & , bool , LayoutMode , bool , ScaleMode , qreal , Rotation , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Database::tabRestored)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject qpdfview::Database::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_qpdfview__Database.data,
    qt_meta_data_qpdfview__Database,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *qpdfview::Database::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qpdfview::Database::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qpdfview__Database.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qpdfview::Database::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void qpdfview::Database::tabRestored(const QString & _t1, bool _t2, LayoutMode _t3, bool _t4, ScaleMode _t5, qreal _t6, Rotation _t7, int _t8)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
