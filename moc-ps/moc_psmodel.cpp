/****************************************************************************
** Meta object code from reading C++ file 'psmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../sources/psmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'psmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_qpdfview__PsSettingsWidget_t {
    QByteArrayData data[1];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qpdfview__PsSettingsWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qpdfview__PsSettingsWidget_t qt_meta_stringdata_qpdfview__PsSettingsWidget = {
    {
QT_MOC_LITERAL(0, 0, 26) // "qpdfview::PsSettingsWidget"

    },
    "qpdfview::PsSettingsWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qpdfview__PsSettingsWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void qpdfview::PsSettingsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject qpdfview::PsSettingsWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<SettingsWidget::staticMetaObject>(),
    qt_meta_stringdata_qpdfview__PsSettingsWidget.data,
    qt_meta_data_qpdfview__PsSettingsWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *qpdfview::PsSettingsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qpdfview::PsSettingsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qpdfview__PsSettingsWidget.stringdata0))
        return static_cast<void*>(this);
    return SettingsWidget::qt_metacast(_clname);
}

int qpdfview::PsSettingsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SettingsWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_qpdfview__PsPlugin_t {
    QByteArrayData data[1];
    char stringdata0[19];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qpdfview__PsPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qpdfview__PsPlugin_t qt_meta_stringdata_qpdfview__PsPlugin = {
    {
QT_MOC_LITERAL(0, 0, 18) // "qpdfview::PsPlugin"

    },
    "qpdfview::PsPlugin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qpdfview__PsPlugin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void qpdfview::PsPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject qpdfview::PsPlugin::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_qpdfview__PsPlugin.data,
    qt_meta_data_qpdfview__PsPlugin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *qpdfview::PsPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qpdfview::PsPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qpdfview__PsPlugin.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Plugin"))
        return static_cast< Plugin*>(this);
    if (!strcmp(_clname, "local.qpdfview.Plugin"))
        return static_cast< qpdfview::Plugin*>(this);
    return QObject::qt_metacast(_clname);
}

int qpdfview::PsPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}

QT_PLUGIN_METADATA_SECTION
static constexpr unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x75,  'l',  'o',  'c',  'a',  'l',  '.', 
    'q',  'p',  'd',  'f',  'v',  'i',  'e',  'w', 
    '.',  'P',  'l',  'u',  'g',  'i',  'n', 
    // "className"
    0x03,  0x68,  'P',  's',  'P',  'l',  'u',  'g', 
    'i',  'n', 
    0xff, 
};
using namespace qpdfview;
QT_MOC_EXPORT_PLUGIN(qpdfview::PsPlugin, PsPlugin)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
