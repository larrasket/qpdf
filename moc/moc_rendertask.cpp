/****************************************************************************
** Meta object code from reading C++ file 'rendertask.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../sources/rendertask.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rendertask.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_qpdfview__RenderTask_t {
    QByteArrayData data[15];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qpdfview__RenderTask_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qpdfview__RenderTask_t qt_meta_stringdata_qpdfview__RenderTask = {
    {
QT_MOC_LITERAL(0, 0, 20), // "qpdfview::RenderTask"
QT_MOC_LITERAL(1, 21, 8), // "finished"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 10), // "imageReady"
QT_MOC_LITERAL(4, 42, 11), // "RenderParam"
QT_MOC_LITERAL(5, 54, 11), // "renderParam"
QT_MOC_LITERAL(6, 66, 4), // "rect"
QT_MOC_LITERAL(7, 71, 8), // "prefetch"
QT_MOC_LITERAL(8, 80, 5), // "image"
QT_MOC_LITERAL(9, 86, 8), // "cropRect"
QT_MOC_LITERAL(10, 95, 5), // "start"
QT_MOC_LITERAL(11, 101, 11), // "trimMargins"
QT_MOC_LITERAL(12, 113, 10), // "paperColor"
QT_MOC_LITERAL(13, 124, 6), // "cancel"
QT_MOC_LITERAL(14, 131, 5) // "force"

    },
    "qpdfview::RenderTask\0finished\0\0"
    "imageReady\0RenderParam\0renderParam\0"
    "rect\0prefetch\0image\0cropRect\0start\0"
    "trimMargins\0paperColor\0cancel\0force"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qpdfview__RenderTask[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    5,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    5,   51,    2, 0x0a /* Public */,
      13,    1,   62,    2, 0x0a /* Public */,
      13,    0,   65,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QRect, QMetaType::Bool, QMetaType::QImage, QMetaType::QRectF,    5,    6,    7,    8,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, QMetaType::QRect, QMetaType::Bool, QMetaType::Bool, QMetaType::QColor,    5,    6,    7,   11,   12,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void,

       0        // eod
};

void qpdfview::RenderTask::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RenderTask *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->imageReady((*reinterpret_cast< const RenderParam(*)>(_a[1])),(*reinterpret_cast< const QRect(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< QImage(*)>(_a[4])),(*reinterpret_cast< QRectF(*)>(_a[5]))); break;
        case 2: _t->start((*reinterpret_cast< const RenderParam(*)>(_a[1])),(*reinterpret_cast< const QRect(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< const QColor(*)>(_a[5]))); break;
        case 3: _t->cancel((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->cancel(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RenderTask::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RenderTask::finished)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RenderTask::*)(const RenderParam & , const QRect & , bool , QImage , QRectF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RenderTask::imageReady)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject qpdfview::RenderTask::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_qpdfview__RenderTask.data,
    qt_meta_data_qpdfview__RenderTask,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *qpdfview::RenderTask::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qpdfview::RenderTask::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qpdfview__RenderTask.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QRunnable"))
        return static_cast< QRunnable*>(this);
    return QObject::qt_metacast(_clname);
}

int qpdfview::RenderTask::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void qpdfview::RenderTask::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qpdfview::RenderTask::imageReady(const RenderParam & _t1, const QRect & _t2, bool _t3, QImage _t4, QRectF _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
