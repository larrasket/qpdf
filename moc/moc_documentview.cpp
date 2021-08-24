/****************************************************************************
** Meta object code from reading C++ file 'documentview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../sources/documentview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'documentview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_qpdfview__DocumentView_t {
    QByteArrayData data[103];
    char stringdata0[1448];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qpdfview__DocumentView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qpdfview__DocumentView_t qt_meta_stringdata_qpdfview__DocumentView = {
    {
QT_MOC_LITERAL(0, 0, 22), // "qpdfview::DocumentView"
QT_MOC_LITERAL(1, 23, 15), // "documentChanged"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 16), // "documentModified"
QT_MOC_LITERAL(4, 57, 20), // "numberOfPagesChanged"
QT_MOC_LITERAL(5, 78, 13), // "numberOfPages"
QT_MOC_LITERAL(6, 92, 18), // "currentPageChanged"
QT_MOC_LITERAL(7, 111, 11), // "currentPage"
QT_MOC_LITERAL(8, 123, 11), // "trackChange"
QT_MOC_LITERAL(9, 135, 14), // "canJumpChanged"
QT_MOC_LITERAL(10, 150, 8), // "backward"
QT_MOC_LITERAL(11, 159, 7), // "forward"
QT_MOC_LITERAL(12, 167, 21), // "continuousModeChanged"
QT_MOC_LITERAL(13, 189, 14), // "continuousMode"
QT_MOC_LITERAL(14, 204, 17), // "layoutModeChanged"
QT_MOC_LITERAL(15, 222, 10), // "LayoutMode"
QT_MOC_LITERAL(16, 233, 10), // "layoutMode"
QT_MOC_LITERAL(17, 244, 22), // "rightToLeftModeChanged"
QT_MOC_LITERAL(18, 267, 15), // "rightToLeftMode"
QT_MOC_LITERAL(19, 283, 16), // "scaleModeChanged"
QT_MOC_LITERAL(20, 300, 9), // "ScaleMode"
QT_MOC_LITERAL(21, 310, 9), // "scaleMode"
QT_MOC_LITERAL(22, 320, 18), // "scaleFactorChanged"
QT_MOC_LITERAL(23, 339, 11), // "scaleFactor"
QT_MOC_LITERAL(24, 351, 15), // "rotationChanged"
QT_MOC_LITERAL(25, 367, 8), // "Rotation"
QT_MOC_LITERAL(26, 376, 8), // "rotation"
QT_MOC_LITERAL(27, 385, 11), // "linkClicked"
QT_MOC_LITERAL(28, 397, 4), // "page"
QT_MOC_LITERAL(29, 402, 6), // "newTab"
QT_MOC_LITERAL(30, 409, 8), // "filePath"
QT_MOC_LITERAL(31, 418, 19), // "invertColorsChanged"
QT_MOC_LITERAL(32, 438, 12), // "invertColors"
QT_MOC_LITERAL(33, 451, 25), // "convertToGrayscaleChanged"
QT_MOC_LITERAL(34, 477, 18), // "convertToGrayscale"
QT_MOC_LITERAL(35, 496, 19), // "highlightAllChanged"
QT_MOC_LITERAL(36, 516, 12), // "highlightAll"
QT_MOC_LITERAL(37, 529, 21), // "rubberBandModeChanged"
QT_MOC_LITERAL(38, 551, 14), // "RubberBandMode"
QT_MOC_LITERAL(39, 566, 14), // "rubberBandMode"
QT_MOC_LITERAL(40, 581, 14), // "searchFinished"
QT_MOC_LITERAL(41, 596, 21), // "searchProgressChanged"
QT_MOC_LITERAL(42, 618, 8), // "progress"
QT_MOC_LITERAL(43, 627, 4), // "show"
QT_MOC_LITERAL(44, 632, 4), // "open"
QT_MOC_LITERAL(45, 637, 7), // "refresh"
QT_MOC_LITERAL(46, 645, 4), // "save"
QT_MOC_LITERAL(47, 650, 11), // "withChanges"
QT_MOC_LITERAL(48, 662, 5), // "print"
QT_MOC_LITERAL(49, 668, 9), // "QPrinter*"
QT_MOC_LITERAL(50, 678, 7), // "printer"
QT_MOC_LITERAL(51, 686, 12), // "PrintOptions"
QT_MOC_LITERAL(52, 699, 12), // "printOptions"
QT_MOC_LITERAL(53, 712, 12), // "previousPage"
QT_MOC_LITERAL(54, 725, 8), // "nextPage"
QT_MOC_LITERAL(55, 734, 9), // "firstPage"
QT_MOC_LITERAL(56, 744, 8), // "lastPage"
QT_MOC_LITERAL(57, 753, 10), // "jumpToPage"
QT_MOC_LITERAL(58, 764, 10), // "changeLeft"
QT_MOC_LITERAL(59, 775, 9), // "changeTop"
QT_MOC_LITERAL(60, 785, 15), // "canJumpBackward"
QT_MOC_LITERAL(61, 801, 12), // "jumpBackward"
QT_MOC_LITERAL(62, 814, 14), // "canJumpForward"
QT_MOC_LITERAL(63, 829, 11), // "jumpForward"
QT_MOC_LITERAL(64, 841, 18), // "temporaryHighlight"
QT_MOC_LITERAL(65, 860, 9), // "highlight"
QT_MOC_LITERAL(66, 870, 11), // "startSearch"
QT_MOC_LITERAL(67, 882, 4), // "text"
QT_MOC_LITERAL(68, 887, 9), // "matchCase"
QT_MOC_LITERAL(69, 897, 12), // "cancelSearch"
QT_MOC_LITERAL(70, 910, 12), // "clearResults"
QT_MOC_LITERAL(71, 923, 12), // "findPrevious"
QT_MOC_LITERAL(72, 936, 8), // "findNext"
QT_MOC_LITERAL(73, 945, 10), // "findResult"
QT_MOC_LITERAL(74, 956, 11), // "QModelIndex"
QT_MOC_LITERAL(75, 968, 5), // "index"
QT_MOC_LITERAL(76, 974, 6), // "zoomIn"
QT_MOC_LITERAL(77, 981, 7), // "zoomOut"
QT_MOC_LITERAL(78, 989, 12), // "originalSize"
QT_MOC_LITERAL(79, 1002, 10), // "rotateLeft"
QT_MOC_LITERAL(80, 1013, 11), // "rotateRight"
QT_MOC_LITERAL(81, 1025, 17), // "startPresentation"
QT_MOC_LITERAL(82, 1043, 33), // "on_verticalScrollBar_valueCha..."
QT_MOC_LITERAL(83, 1077, 22), // "on_autoRefresh_timeout"
QT_MOC_LITERAL(84, 1100, 19), // "on_prefetch_timeout"
QT_MOC_LITERAL(85, 1120, 29), // "on_temporaryHighlight_timeout"
QT_MOC_LITERAL(86, 1150, 29), // "on_searchTask_progressChanged"
QT_MOC_LITERAL(87, 1180, 26), // "on_searchTask_resultsReady"
QT_MOC_LITERAL(88, 1207, 13), // "QList<QRectF>"
QT_MOC_LITERAL(89, 1221, 7), // "results"
QT_MOC_LITERAL(90, 1229, 24), // "on_pages_cropRectChanged"
QT_MOC_LITERAL(91, 1254, 29), // "on_thumbnails_cropRectChanged"
QT_MOC_LITERAL(92, 1284, 20), // "on_pages_linkClicked"
QT_MOC_LITERAL(93, 1305, 4), // "left"
QT_MOC_LITERAL(94, 1310, 3), // "top"
QT_MOC_LITERAL(95, 1314, 8), // "fileName"
QT_MOC_LITERAL(96, 1323, 3), // "url"
QT_MOC_LITERAL(97, 1327, 27), // "on_pages_rubberBandFinished"
QT_MOC_LITERAL(98, 1355, 28), // "on_pages_editSourceRequested"
QT_MOC_LITERAL(99, 1384, 3), // "pos"
QT_MOC_LITERAL(100, 1388, 33), // "on_pages_zoomToSelectionReque..."
QT_MOC_LITERAL(101, 1422, 4), // "rect"
QT_MOC_LITERAL(102, 1427, 20) // "on_pages_wasModified"

    },
    "qpdfview::DocumentView\0documentChanged\0"
    "\0documentModified\0numberOfPagesChanged\0"
    "numberOfPages\0currentPageChanged\0"
    "currentPage\0trackChange\0canJumpChanged\0"
    "backward\0forward\0continuousModeChanged\0"
    "continuousMode\0layoutModeChanged\0"
    "LayoutMode\0layoutMode\0rightToLeftModeChanged\0"
    "rightToLeftMode\0scaleModeChanged\0"
    "ScaleMode\0scaleMode\0scaleFactorChanged\0"
    "scaleFactor\0rotationChanged\0Rotation\0"
    "rotation\0linkClicked\0page\0newTab\0"
    "filePath\0invertColorsChanged\0invertColors\0"
    "convertToGrayscaleChanged\0convertToGrayscale\0"
    "highlightAllChanged\0highlightAll\0"
    "rubberBandModeChanged\0RubberBandMode\0"
    "rubberBandMode\0searchFinished\0"
    "searchProgressChanged\0progress\0show\0"
    "open\0refresh\0save\0withChanges\0print\0"
    "QPrinter*\0printer\0PrintOptions\0"
    "printOptions\0previousPage\0nextPage\0"
    "firstPage\0lastPage\0jumpToPage\0changeLeft\0"
    "changeTop\0canJumpBackward\0jumpBackward\0"
    "canJumpForward\0jumpForward\0"
    "temporaryHighlight\0highlight\0startSearch\0"
    "text\0matchCase\0cancelSearch\0clearResults\0"
    "findPrevious\0findNext\0findResult\0"
    "QModelIndex\0index\0zoomIn\0zoomOut\0"
    "originalSize\0rotateLeft\0rotateRight\0"
    "startPresentation\0on_verticalScrollBar_valueChanged\0"
    "on_autoRefresh_timeout\0on_prefetch_timeout\0"
    "on_temporaryHighlight_timeout\0"
    "on_searchTask_progressChanged\0"
    "on_searchTask_resultsReady\0QList<QRectF>\0"
    "results\0on_pages_cropRectChanged\0"
    "on_thumbnails_cropRectChanged\0"
    "on_pages_linkClicked\0left\0top\0fileName\0"
    "url\0on_pages_rubberBandFinished\0"
    "on_pages_editSourceRequested\0pos\0"
    "on_pages_zoomToSelectionRequested\0"
    "rect\0on_pages_wasModified"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qpdfview__DocumentView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      67,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      20,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  349,    2, 0x06 /* Public */,
       3,    0,  350,    2, 0x06 /* Public */,
       4,    1,  351,    2, 0x06 /* Public */,
       6,    2,  354,    2, 0x06 /* Public */,
       6,    1,  359,    2, 0x26 /* Public | MethodCloned */,
       9,    2,  362,    2, 0x06 /* Public */,
      12,    1,  367,    2, 0x06 /* Public */,
      14,    1,  370,    2, 0x06 /* Public */,
      17,    1,  373,    2, 0x06 /* Public */,
      19,    1,  376,    2, 0x06 /* Public */,
      22,    1,  379,    2, 0x06 /* Public */,
      24,    1,  382,    2, 0x06 /* Public */,
      27,    1,  385,    2, 0x06 /* Public */,
      27,    3,  388,    2, 0x06 /* Public */,
      31,    1,  395,    2, 0x06 /* Public */,
      33,    1,  398,    2, 0x06 /* Public */,
      35,    1,  401,    2, 0x06 /* Public */,
      37,    1,  404,    2, 0x06 /* Public */,
      40,    0,  407,    2, 0x06 /* Public */,
      41,    1,  408,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      43,    0,  411,    2, 0x0a /* Public */,
      44,    1,  412,    2, 0x0a /* Public */,
      45,    0,  415,    2, 0x0a /* Public */,
      46,    2,  416,    2, 0x0a /* Public */,
      48,    2,  421,    2, 0x0a /* Public */,
      48,    1,  426,    2, 0x2a /* Public | MethodCloned */,
      53,    0,  429,    2, 0x0a /* Public */,
      54,    0,  430,    2, 0x0a /* Public */,
      55,    0,  431,    2, 0x0a /* Public */,
      56,    0,  432,    2, 0x0a /* Public */,
      57,    4,  433,    2, 0x0a /* Public */,
      57,    3,  442,    2, 0x2a /* Public | MethodCloned */,
      57,    2,  449,    2, 0x2a /* Public | MethodCloned */,
      57,    1,  454,    2, 0x2a /* Public | MethodCloned */,
      60,    0,  457,    2, 0x0a /* Public */,
      61,    0,  458,    2, 0x0a /* Public */,
      62,    0,  459,    2, 0x0a /* Public */,
      63,    0,  460,    2, 0x0a /* Public */,
      64,    2,  461,    2, 0x0a /* Public */,
      66,    2,  466,    2, 0x0a /* Public */,
      66,    1,  471,    2, 0x2a /* Public | MethodCloned */,
      69,    0,  474,    2, 0x0a /* Public */,
      70,    0,  475,    2, 0x0a /* Public */,
      71,    0,  476,    2, 0x0a /* Public */,
      72,    0,  477,    2, 0x0a /* Public */,
      73,    1,  478,    2, 0x0a /* Public */,
      76,    0,  481,    2, 0x0a /* Public */,
      77,    0,  482,    2, 0x0a /* Public */,
      78,    0,  483,    2, 0x0a /* Public */,
      79,    0,  484,    2, 0x0a /* Public */,
      80,    0,  485,    2, 0x0a /* Public */,
      81,    0,  486,    2, 0x0a /* Public */,
      82,    0,  487,    2, 0x09 /* Protected */,
      83,    0,  488,    2, 0x09 /* Protected */,
      84,    0,  489,    2, 0x09 /* Protected */,
      85,    0,  490,    2, 0x09 /* Protected */,
      86,    1,  491,    2, 0x09 /* Protected */,
      87,    2,  494,    2, 0x09 /* Protected */,
      90,    0,  499,    2, 0x09 /* Protected */,
      91,    0,  500,    2, 0x09 /* Protected */,
      92,    4,  501,    2, 0x09 /* Protected */,
      92,    3,  510,    2, 0x09 /* Protected */,
      92,    1,  517,    2, 0x09 /* Protected */,
      97,    0,  520,    2, 0x09 /* Protected */,
      98,    2,  521,    2, 0x09 /* Protected */,
     100,    2,  526,    2, 0x09 /* Protected */,
     102,    0,  531,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    7,    8,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   10,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void, QMetaType::QReal,   23,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString, QMetaType::Int,   29,   30,   28,
    QMetaType::Void, QMetaType::Bool,   32,
    QMetaType::Void, QMetaType::Bool,   34,
    QMetaType::Void, QMetaType::Bool,   36,
    QMetaType::Void, 0x80000000 | 38,   39,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   42,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,   30,
    QMetaType::Bool,
    QMetaType::Bool, QMetaType::QString, QMetaType::Bool,   30,   47,
    QMetaType::Bool, 0x80000000 | 49, 0x80000000 | 51,   50,   52,
    QMetaType::Bool, 0x80000000 | 49,   50,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::QReal, QMetaType::QReal,   28,    8,   58,   59,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::QReal,   28,    8,   58,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   28,    8,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QRectF,   28,   65,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   67,   68,
    QMetaType::Void, QMetaType::QString,   67,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 74,   75,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   42,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 88,   75,   89,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int, QMetaType::QReal, QMetaType::QReal,   29,   28,   93,   94,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString, QMetaType::Int,   29,   95,   28,
    QMetaType::Void, QMetaType::QString,   96,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QPointF,   28,   99,
    QMetaType::Void, QMetaType::Int, QMetaType::QRectF,   28,  101,
    QMetaType::Void,

       0        // eod
};

void qpdfview::DocumentView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DocumentView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->documentChanged(); break;
        case 1: _t->documentModified(); break;
        case 2: _t->numberOfPagesChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->currentPageChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->currentPageChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->canJumpChanged((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->continuousModeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->layoutModeChanged((*reinterpret_cast< LayoutMode(*)>(_a[1]))); break;
        case 8: _t->rightToLeftModeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->scaleModeChanged((*reinterpret_cast< ScaleMode(*)>(_a[1]))); break;
        case 10: _t->scaleFactorChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 11: _t->rotationChanged((*reinterpret_cast< Rotation(*)>(_a[1]))); break;
        case 12: _t->linkClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->linkClicked((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 14: _t->invertColorsChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->convertToGrayscaleChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->highlightAllChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->rubberBandModeChanged((*reinterpret_cast< RubberBandMode(*)>(_a[1]))); break;
        case 18: _t->searchFinished(); break;
        case 19: _t->searchProgressChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->show(); break;
        case 21: { bool _r = _t->open((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 22: { bool _r = _t->refresh();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 23: { bool _r = _t->save((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 24: { bool _r = _t->print((*reinterpret_cast< QPrinter*(*)>(_a[1])),(*reinterpret_cast< const PrintOptions(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 25: { bool _r = _t->print((*reinterpret_cast< QPrinter*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 26: _t->previousPage(); break;
        case 27: _t->nextPage(); break;
        case 28: _t->firstPage(); break;
        case 29: _t->lastPage(); break;
        case 30: _t->jumpToPage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4]))); break;
        case 31: _t->jumpToPage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3]))); break;
        case 32: _t->jumpToPage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 33: _t->jumpToPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: { bool _r = _t->canJumpBackward();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 35: _t->jumpBackward(); break;
        case 36: { bool _r = _t->canJumpForward();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 37: _t->jumpForward(); break;
        case 38: _t->temporaryHighlight((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QRectF(*)>(_a[2]))); break;
        case 39: _t->startSearch((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 40: _t->startSearch((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 41: _t->cancelSearch(); break;
        case 42: _t->clearResults(); break;
        case 43: _t->findPrevious(); break;
        case 44: _t->findNext(); break;
        case 45: _t->findResult((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 46: _t->zoomIn(); break;
        case 47: _t->zoomOut(); break;
        case 48: _t->originalSize(); break;
        case 49: _t->rotateLeft(); break;
        case 50: _t->rotateRight(); break;
        case 51: _t->startPresentation(); break;
        case 52: _t->on_verticalScrollBar_valueChanged(); break;
        case 53: _t->on_autoRefresh_timeout(); break;
        case 54: _t->on_prefetch_timeout(); break;
        case 55: _t->on_temporaryHighlight_timeout(); break;
        case 56: _t->on_searchTask_progressChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 57: _t->on_searchTask_resultsReady((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QList<QRectF>(*)>(_a[2]))); break;
        case 58: _t->on_pages_cropRectChanged(); break;
        case 59: _t->on_thumbnails_cropRectChanged(); break;
        case 60: _t->on_pages_linkClicked((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< qreal(*)>(_a[3])),(*reinterpret_cast< qreal(*)>(_a[4]))); break;
        case 61: _t->on_pages_linkClicked((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 62: _t->on_pages_linkClicked((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 63: _t->on_pages_rubberBandFinished(); break;
        case 64: _t->on_pages_editSourceRequested((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QPointF(*)>(_a[2]))); break;
        case 65: _t->on_pages_zoomToSelectionRequested((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QRectF(*)>(_a[2]))); break;
        case 66: _t->on_pages_wasModified(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 57:
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
            using _t = void (DocumentView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentView::documentChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DocumentView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentView::documentModified)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DocumentView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentView::numberOfPagesChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DocumentView::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentView::currentPageChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DocumentView::*)(bool , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentView::canJumpChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (DocumentView::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentView::continuousModeChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (DocumentView::*)(LayoutMode );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentView::layoutModeChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (DocumentView::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentView::rightToLeftModeChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (DocumentView::*)(ScaleMode );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentView::scaleModeChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (DocumentView::*)(qreal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentView::scaleFactorChanged)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (DocumentView::*)(Rotation );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentView::rotationChanged)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (DocumentView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentView::linkClicked)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (DocumentView::*)(bool , const QString & , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentView::linkClicked)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (DocumentView::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentView::invertColorsChanged)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (DocumentView::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentView::convertToGrayscaleChanged)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (DocumentView::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentView::highlightAllChanged)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (DocumentView::*)(RubberBandMode );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentView::rubberBandModeChanged)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (DocumentView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentView::searchFinished)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (DocumentView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DocumentView::searchProgressChanged)) {
                *result = 19;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject qpdfview::DocumentView::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_qpdfview__DocumentView.data,
    qt_meta_data_qpdfview__DocumentView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *qpdfview::DocumentView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qpdfview::DocumentView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qpdfview__DocumentView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int qpdfview::DocumentView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 67)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 67;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 67)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 67;
    }
    return _id;
}

// SIGNAL 0
void qpdfview::DocumentView::documentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void qpdfview::DocumentView::documentModified()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void qpdfview::DocumentView::numberOfPagesChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void qpdfview::DocumentView::currentPageChanged(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 5
void qpdfview::DocumentView::canJumpChanged(bool _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void qpdfview::DocumentView::continuousModeChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void qpdfview::DocumentView::layoutModeChanged(LayoutMode _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void qpdfview::DocumentView::rightToLeftModeChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void qpdfview::DocumentView::scaleModeChanged(ScaleMode _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void qpdfview::DocumentView::scaleFactorChanged(qreal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void qpdfview::DocumentView::rotationChanged(Rotation _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void qpdfview::DocumentView::linkClicked(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void qpdfview::DocumentView::linkClicked(bool _t1, const QString & _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void qpdfview::DocumentView::invertColorsChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void qpdfview::DocumentView::convertToGrayscaleChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void qpdfview::DocumentView::highlightAllChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void qpdfview::DocumentView::rubberBandModeChanged(RubberBandMode _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void qpdfview::DocumentView::searchFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void qpdfview::DocumentView::searchProgressChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
