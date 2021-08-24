/****************************************************************************
** Meta object code from reading C++ file 'tileitem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../sources/tileitem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tileitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_qpdfview__TileItem_t {
    QByteArrayData data[15];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qpdfview__TileItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qpdfview__TileItem_t qt_meta_stringdata_qpdfview__TileItem = {
    {
QT_MOC_LITERAL(0, 0, 18), // "qpdfview::TileItem"
QT_MOC_LITERAL(1, 19, 7), // "refresh"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 19), // "keepObsoletePixmaps"
QT_MOC_LITERAL(4, 48, 11), // "startRender"
QT_MOC_LITERAL(5, 60, 8), // "prefetch"
QT_MOC_LITERAL(6, 69, 12), // "cancelRender"
QT_MOC_LITERAL(7, 82, 17), // "deleteAfterRender"
QT_MOC_LITERAL(8, 100, 22), // "on_renderTask_finished"
QT_MOC_LITERAL(9, 123, 24), // "on_renderTask_imageReady"
QT_MOC_LITERAL(10, 148, 11), // "RenderParam"
QT_MOC_LITERAL(11, 160, 11), // "renderParam"
QT_MOC_LITERAL(12, 172, 4), // "rect"
QT_MOC_LITERAL(13, 177, 5), // "image"
QT_MOC_LITERAL(14, 183, 8) // "cropRect"

    },
    "qpdfview::TileItem\0refresh\0\0"
    "keepObsoletePixmaps\0startRender\0"
    "prefetch\0cancelRender\0deleteAfterRender\0"
    "on_renderTask_finished\0on_renderTask_imageReady\0"
    "RenderParam\0renderParam\0rect\0image\0"
    "cropRect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qpdfview__TileItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       1,    0,   57,    2, 0x2a /* Public | MethodCloned */,
       4,    1,   58,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x2a /* Public | MethodCloned */,
       6,    0,   62,    2, 0x0a /* Public */,
       7,    0,   63,    2, 0x0a /* Public */,
       8,    0,   64,    2, 0x09 /* Protected */,
       9,    5,   65,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Bool,    5,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10, QMetaType::QRect, QMetaType::Bool, QMetaType::QImage, QMetaType::QRectF,   11,   12,    5,   13,   14,

       0        // eod
};

void qpdfview::TileItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TileItem *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->refresh((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->refresh(); break;
        case 2: { int _r = _t->startRender((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->startRender();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->cancelRender(); break;
        case 5: _t->deleteAfterRender(); break;
        case 6: _t->on_renderTask_finished(); break;
        case 7: _t->on_renderTask_imageReady((*reinterpret_cast< const RenderParam(*)>(_a[1])),(*reinterpret_cast< const QRect(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QImage(*)>(_a[4])),(*reinterpret_cast< QRectF(*)>(_a[5]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject qpdfview::TileItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_qpdfview__TileItem.data,
    qt_meta_data_qpdfview__TileItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *qpdfview::TileItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qpdfview::TileItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qpdfview__TileItem.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int qpdfview::TileItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
