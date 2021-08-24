/****************************************************************************
** Meta object code from reading C++ file 'searchtask.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../sources/searchtask.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'searchtask.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_qpdfview__SearchTask_t {
    QByteArrayData data[15];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qpdfview__SearchTask_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qpdfview__SearchTask_t qt_meta_stringdata_qpdfview__SearchTask = {
    {
QT_MOC_LITERAL(0, 0, 20), // "qpdfview::SearchTask"
QT_MOC_LITERAL(1, 21, 15), // "progressChanged"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 8), // "progress"
QT_MOC_LITERAL(4, 47, 12), // "resultsReady"
QT_MOC_LITERAL(5, 60, 5), // "index"
QT_MOC_LITERAL(6, 66, 13), // "QList<QRectF>"
QT_MOC_LITERAL(7, 80, 7), // "results"
QT_MOC_LITERAL(8, 88, 5), // "start"
QT_MOC_LITERAL(9, 94, 21), // "QVector<Model::Page*>"
QT_MOC_LITERAL(10, 116, 5), // "pages"
QT_MOC_LITERAL(11, 122, 4), // "text"
QT_MOC_LITERAL(12, 127, 9), // "matchCase"
QT_MOC_LITERAL(13, 137, 11), // "beginAtPage"
QT_MOC_LITERAL(14, 149, 6) // "cancel"

    },
    "qpdfview::SearchTask\0progressChanged\0"
    "\0progress\0resultsReady\0index\0QList<QRectF>\0"
    "results\0start\0QVector<Model::Page*>\0"
    "pages\0text\0matchCase\0beginAtPage\0"
    "cancel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qpdfview__SearchTask[] = {

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
       1,    1,   39,    2, 0x06 /* Public */,
       4,    2,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    4,   47,    2, 0x0a /* Public */,
       8,    3,   56,    2, 0x2a /* Public | MethodCloned */,
      14,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 6,    5,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString, QMetaType::Bool, QMetaType::Int,   10,   11,   12,   13,
    QMetaType::Void, 0x80000000 | 9, QMetaType::QString, QMetaType::Bool,   10,   11,   12,
    QMetaType::Void,

       0        // eod
};

void qpdfview::SearchTask::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SearchTask *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->progressChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->resultsReady((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<QRectF>(*)>(_a[2]))); break;
        case 2: _t->start((*reinterpret_cast< const QVector<Model::Page*>(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: _t->start((*reinterpret_cast< const QVector<Model::Page*>(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 4: _t->cancel(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QRectF> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SearchTask::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SearchTask::progressChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SearchTask::*)(int , QList<QRectF> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SearchTask::resultsReady)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject qpdfview::SearchTask::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_qpdfview__SearchTask.data,
    qt_meta_data_qpdfview__SearchTask,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *qpdfview::SearchTask::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qpdfview::SearchTask::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qpdfview__SearchTask.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int qpdfview::SearchTask::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void qpdfview::SearchTask::progressChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void qpdfview::SearchTask::resultsReady(int _t1, QList<QRectF> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
