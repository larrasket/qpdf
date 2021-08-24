/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../sources/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_qpdfview__MainWindow_t {
    QByteArrayData data[156];
    char stringdata0[3557];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qpdfview__MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qpdfview__MainWindow_t qt_meta_stringdata_qpdfview__MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 20), // "qpdfview::MainWindow"
QT_MOC_LITERAL(1, 21, 4), // "open"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "filePath"
QT_MOC_LITERAL(4, 36, 4), // "page"
QT_MOC_LITERAL(5, 41, 9), // "highlight"
QT_MOC_LITERAL(6, 51, 5), // "quiet"
QT_MOC_LITERAL(7, 57, 12), // "openInNewTab"
QT_MOC_LITERAL(8, 70, 24), // "jumpToPageOrOpenInNewTab"
QT_MOC_LITERAL(9, 95, 17), // "refreshBeforeJump"
QT_MOC_LITERAL(10, 113, 11), // "startSearch"
QT_MOC_LITERAL(11, 125, 4), // "text"
QT_MOC_LITERAL(12, 130, 27), // "on_tabWidget_currentChanged"
QT_MOC_LITERAL(13, 158, 5), // "index"
QT_MOC_LITERAL(14, 164, 30), // "on_tabWidget_tabCloseRequested"
QT_MOC_LITERAL(15, 195, 36), // "on_tabWidget_tabContextMenuRe..."
QT_MOC_LITERAL(16, 232, 9), // "globalPos"
QT_MOC_LITERAL(17, 242, 29), // "on_currentTab_documentChanged"
QT_MOC_LITERAL(18, 272, 33), // "on_currentTab_numberOfPagesCh..."
QT_MOC_LITERAL(19, 306, 13), // "numberOfPages"
QT_MOC_LITERAL(20, 320, 32), // "on_currentTab_currentPageChanged"
QT_MOC_LITERAL(21, 353, 11), // "currentPage"
QT_MOC_LITERAL(22, 365, 28), // "on_currentTab_canJumpChanged"
QT_MOC_LITERAL(23, 394, 8), // "backward"
QT_MOC_LITERAL(24, 403, 7), // "forward"
QT_MOC_LITERAL(25, 411, 35), // "on_currentTab_continuousModeC..."
QT_MOC_LITERAL(26, 447, 14), // "continuousMode"
QT_MOC_LITERAL(27, 462, 31), // "on_currentTab_layoutModeChanged"
QT_MOC_LITERAL(28, 494, 10), // "LayoutMode"
QT_MOC_LITERAL(29, 505, 10), // "layoutMode"
QT_MOC_LITERAL(30, 516, 36), // "on_currentTab_rightToLeftMode..."
QT_MOC_LITERAL(31, 553, 15), // "rightToLeftMode"
QT_MOC_LITERAL(32, 569, 30), // "on_currentTab_scaleModeChanged"
QT_MOC_LITERAL(33, 600, 9), // "ScaleMode"
QT_MOC_LITERAL(34, 610, 9), // "scaleMode"
QT_MOC_LITERAL(35, 620, 32), // "on_currentTab_scaleFactorChanged"
QT_MOC_LITERAL(36, 653, 11), // "scaleFactor"
QT_MOC_LITERAL(37, 665, 29), // "on_currentTab_rotationChanged"
QT_MOC_LITERAL(38, 695, 8), // "Rotation"
QT_MOC_LITERAL(39, 704, 8), // "rotation"
QT_MOC_LITERAL(40, 713, 25), // "on_currentTab_linkClicked"
QT_MOC_LITERAL(41, 739, 6), // "newTab"
QT_MOC_LITERAL(42, 746, 33), // "on_currentTab_invertColorsCha..."
QT_MOC_LITERAL(43, 780, 12), // "invertColors"
QT_MOC_LITERAL(44, 793, 32), // "on_currentTab_convertToGrayscale"
QT_MOC_LITERAL(45, 826, 18), // "convertToGrayscale"
QT_MOC_LITERAL(46, 845, 33), // "on_currentTab_highlightAllCha..."
QT_MOC_LITERAL(47, 879, 12), // "highlightAll"
QT_MOC_LITERAL(48, 892, 35), // "on_currentTab_rubberBandModeC..."
QT_MOC_LITERAL(49, 928, 14), // "RubberBandMode"
QT_MOC_LITERAL(50, 943, 14), // "rubberBandMode"
QT_MOC_LITERAL(51, 958, 28), // "on_currentTab_searchFinished"
QT_MOC_LITERAL(52, 987, 35), // "on_currentTab_searchProgressC..."
QT_MOC_LITERAL(53, 1023, 8), // "progress"
QT_MOC_LITERAL(54, 1032, 40), // "on_currentTab_customContextMe..."
QT_MOC_LITERAL(55, 1073, 3), // "pos"
QT_MOC_LITERAL(56, 1077, 30), // "on_currentPage_editingFinished"
QT_MOC_LITERAL(57, 1108, 28), // "on_currentPage_returnPressed"
QT_MOC_LITERAL(58, 1137, 24), // "on_scaleFactor_activated"
QT_MOC_LITERAL(59, 1162, 30), // "on_scaleFactor_editingFinished"
QT_MOC_LITERAL(60, 1193, 28), // "on_scaleFactor_returnPressed"
QT_MOC_LITERAL(61, 1222, 17), // "on_open_triggered"
QT_MOC_LITERAL(62, 1240, 25), // "on_openInNewTab_triggered"
QT_MOC_LITERAL(63, 1266, 29), // "on_openCopyInNewTab_triggered"
QT_MOC_LITERAL(64, 1296, 33), // "on_openContainingFolder_trigg..."
QT_MOC_LITERAL(65, 1330, 20), // "on_refresh_triggered"
QT_MOC_LITERAL(66, 1351, 21), // "on_saveCopy_triggered"
QT_MOC_LITERAL(67, 1373, 19), // "on_saveAs_triggered"
QT_MOC_LITERAL(68, 1393, 18), // "on_print_triggered"
QT_MOC_LITERAL(69, 1412, 29), // "on_recentlyUsed_openTriggered"
QT_MOC_LITERAL(70, 1442, 25), // "on_previousPage_triggered"
QT_MOC_LITERAL(71, 1468, 21), // "on_nextPage_triggered"
QT_MOC_LITERAL(72, 1490, 22), // "on_firstPage_triggered"
QT_MOC_LITERAL(73, 1513, 21), // "on_lastPage_triggered"
QT_MOC_LITERAL(74, 1535, 25), // "on_setFirstPage_triggered"
QT_MOC_LITERAL(75, 1561, 23), // "on_jumpToPage_triggered"
QT_MOC_LITERAL(76, 1585, 25), // "on_jumpBackward_triggered"
QT_MOC_LITERAL(77, 1611, 24), // "on_jumpForward_triggered"
QT_MOC_LITERAL(78, 1636, 19), // "on_search_triggered"
QT_MOC_LITERAL(79, 1656, 25), // "on_findPrevious_triggered"
QT_MOC_LITERAL(80, 1682, 21), // "on_findNext_triggered"
QT_MOC_LITERAL(81, 1704, 25), // "on_cancelSearch_triggered"
QT_MOC_LITERAL(82, 1730, 32), // "on_copyToClipboardMode_triggered"
QT_MOC_LITERAL(83, 1763, 7), // "checked"
QT_MOC_LITERAL(84, 1771, 30), // "on_addAnnotationMode_triggered"
QT_MOC_LITERAL(85, 1802, 21), // "on_settings_triggered"
QT_MOC_LITERAL(86, 1824, 27), // "on_continuousMode_triggered"
QT_MOC_LITERAL(87, 1852, 25), // "on_twoPagesMode_triggered"
QT_MOC_LITERAL(88, 1878, 38), // "on_twoPagesWithCoverPageMode_..."
QT_MOC_LITERAL(89, 1917, 30), // "on_multiplePagesMode_triggered"
QT_MOC_LITERAL(90, 1948, 28), // "on_rightToLeftMode_triggered"
QT_MOC_LITERAL(91, 1977, 19), // "on_zoomIn_triggered"
QT_MOC_LITERAL(92, 1997, 20), // "on_zoomOut_triggered"
QT_MOC_LITERAL(93, 2018, 25), // "on_originalSize_triggered"
QT_MOC_LITERAL(94, 2044, 31), // "on_fitToPageWidthMode_triggered"
QT_MOC_LITERAL(95, 2076, 30), // "on_fitToPageSizeMode_triggered"
QT_MOC_LITERAL(96, 2107, 23), // "on_rotateLeft_triggered"
QT_MOC_LITERAL(97, 2131, 24), // "on_rotateRight_triggered"
QT_MOC_LITERAL(98, 2156, 25), // "on_invertColors_triggered"
QT_MOC_LITERAL(99, 2182, 31), // "on_convertToGrayscale_triggered"
QT_MOC_LITERAL(100, 2214, 18), // "on_fonts_triggered"
QT_MOC_LITERAL(101, 2233, 23), // "on_fullscreen_triggered"
QT_MOC_LITERAL(102, 2257, 25), // "on_presentation_triggered"
QT_MOC_LITERAL(103, 2283, 24), // "on_previousTab_triggered"
QT_MOC_LITERAL(104, 2308, 20), // "on_nextTab_triggered"
QT_MOC_LITERAL(105, 2329, 21), // "on_closeTab_triggered"
QT_MOC_LITERAL(106, 2351, 25), // "on_closeAllTabs_triggered"
QT_MOC_LITERAL(107, 2377, 38), // "on_closeAllTabsButCurrentTab_..."
QT_MOC_LITERAL(108, 2416, 36), // "on_recentlyClosed_tabActionTr..."
QT_MOC_LITERAL(109, 2453, 8), // "QAction*"
QT_MOC_LITERAL(110, 2462, 9), // "tabAction"
QT_MOC_LITERAL(111, 2472, 22), // "on_tabAction_triggered"
QT_MOC_LITERAL(112, 2495, 24), // "on_tabShortcut_activated"
QT_MOC_LITERAL(113, 2520, 29), // "on_previousBookmark_triggered"
QT_MOC_LITERAL(114, 2550, 25), // "on_nextBookmark_triggered"
QT_MOC_LITERAL(115, 2576, 24), // "on_addBookmark_triggered"
QT_MOC_LITERAL(116, 2601, 27), // "on_removeBookmark_triggered"
QT_MOC_LITERAL(117, 2629, 31), // "on_removeAllBookmarks_triggered"
QT_MOC_LITERAL(118, 2661, 28), // "on_bookmarksMenu_aboutToShow"
QT_MOC_LITERAL(119, 2690, 25), // "on_bookmark_openTriggered"
QT_MOC_LITERAL(120, 2716, 16), // "absoluteFilePath"
QT_MOC_LITERAL(121, 2733, 33), // "on_bookmark_openInNewTabTrigg..."
QT_MOC_LITERAL(122, 2767, 31), // "on_bookmark_jumpToPageTriggered"
QT_MOC_LITERAL(123, 2799, 35), // "on_bookmark_removeBookmarkTri..."
QT_MOC_LITERAL(124, 2835, 21), // "on_contents_triggered"
QT_MOC_LITERAL(125, 2857, 18), // "on_about_triggered"
QT_MOC_LITERAL(126, 2876, 25), // "currentPage_textFromValue"
QT_MOC_LITERAL(127, 2902, 5), // "value"
QT_MOC_LITERAL(128, 2908, 5), // "bool*"
QT_MOC_LITERAL(129, 2914, 2), // "ok"
QT_MOC_LITERAL(130, 2917, 25), // "currentPage_valueFromText"
QT_MOC_LITERAL(131, 2943, 29), // "on_focusCurrentPage_activated"
QT_MOC_LITERAL(132, 2973, 29), // "on_focusScaleFactor_activated"
QT_MOC_LITERAL(133, 3003, 27), // "on_toggleToolBars_triggered"
QT_MOC_LITERAL(134, 3031, 26), // "on_toggleMenuBar_triggered"
QT_MOC_LITERAL(135, 3058, 18), // "on_searchInitiated"
QT_MOC_LITERAL(136, 3077, 8), // "modified"
QT_MOC_LITERAL(137, 3086, 23), // "on_highlightAll_clicked"
QT_MOC_LITERAL(138, 3110, 27), // "on_dock_dockLocationChanged"
QT_MOC_LITERAL(139, 3138, 18), // "Qt::DockWidgetArea"
QT_MOC_LITERAL(140, 3157, 4), // "area"
QT_MOC_LITERAL(141, 3162, 30), // "on_outline_sectionCountChanged"
QT_MOC_LITERAL(142, 3193, 18), // "on_outline_clicked"
QT_MOC_LITERAL(143, 3212, 11), // "QModelIndex"
QT_MOC_LITERAL(144, 3224, 33), // "on_properties_sectionCountCha..."
QT_MOC_LITERAL(145, 3258, 33), // "on_thumbnails_dockLocationCha..."
QT_MOC_LITERAL(146, 3292, 44), // "on_thumbnails_verticalScrollB..."
QT_MOC_LITERAL(147, 3337, 32), // "on_bookmarks_sectionCountChanged"
QT_MOC_LITERAL(148, 3370, 20), // "on_bookmarks_clicked"
QT_MOC_LITERAL(149, 3391, 33), // "on_bookmarks_contextMenuReque..."
QT_MOC_LITERAL(150, 3425, 29), // "on_search_sectionCountChanged"
QT_MOC_LITERAL(151, 3455, 27), // "on_search_visibilityChanged"
QT_MOC_LITERAL(152, 3483, 7), // "visible"
QT_MOC_LITERAL(153, 3491, 17), // "on_search_clicked"
QT_MOC_LITERAL(154, 3509, 23), // "on_database_tabRestored"
QT_MOC_LITERAL(155, 3533, 23) // "on_saveDatabase_timeout"

    },
    "qpdfview::MainWindow\0open\0\0filePath\0"
    "page\0highlight\0quiet\0openInNewTab\0"
    "jumpToPageOrOpenInNewTab\0refreshBeforeJump\0"
    "startSearch\0text\0on_tabWidget_currentChanged\0"
    "index\0on_tabWidget_tabCloseRequested\0"
    "on_tabWidget_tabContextMenuRequested\0"
    "globalPos\0on_currentTab_documentChanged\0"
    "on_currentTab_numberOfPagesChaned\0"
    "numberOfPages\0on_currentTab_currentPageChanged\0"
    "currentPage\0on_currentTab_canJumpChanged\0"
    "backward\0forward\0on_currentTab_continuousModeChanged\0"
    "continuousMode\0on_currentTab_layoutModeChanged\0"
    "LayoutMode\0layoutMode\0"
    "on_currentTab_rightToLeftModeChanged\0"
    "rightToLeftMode\0on_currentTab_scaleModeChanged\0"
    "ScaleMode\0scaleMode\0"
    "on_currentTab_scaleFactorChanged\0"
    "scaleFactor\0on_currentTab_rotationChanged\0"
    "Rotation\0rotation\0on_currentTab_linkClicked\0"
    "newTab\0on_currentTab_invertColorsChanged\0"
    "invertColors\0on_currentTab_convertToGrayscale\0"
    "convertToGrayscale\0on_currentTab_highlightAllChanged\0"
    "highlightAll\0on_currentTab_rubberBandModeChanged\0"
    "RubberBandMode\0rubberBandMode\0"
    "on_currentTab_searchFinished\0"
    "on_currentTab_searchProgressChanged\0"
    "progress\0on_currentTab_customContextMenuRequested\0"
    "pos\0on_currentPage_editingFinished\0"
    "on_currentPage_returnPressed\0"
    "on_scaleFactor_activated\0"
    "on_scaleFactor_editingFinished\0"
    "on_scaleFactor_returnPressed\0"
    "on_open_triggered\0on_openInNewTab_triggered\0"
    "on_openCopyInNewTab_triggered\0"
    "on_openContainingFolder_triggered\0"
    "on_refresh_triggered\0on_saveCopy_triggered\0"
    "on_saveAs_triggered\0on_print_triggered\0"
    "on_recentlyUsed_openTriggered\0"
    "on_previousPage_triggered\0"
    "on_nextPage_triggered\0on_firstPage_triggered\0"
    "on_lastPage_triggered\0on_setFirstPage_triggered\0"
    "on_jumpToPage_triggered\0"
    "on_jumpBackward_triggered\0"
    "on_jumpForward_triggered\0on_search_triggered\0"
    "on_findPrevious_triggered\0"
    "on_findNext_triggered\0on_cancelSearch_triggered\0"
    "on_copyToClipboardMode_triggered\0"
    "checked\0on_addAnnotationMode_triggered\0"
    "on_settings_triggered\0on_continuousMode_triggered\0"
    "on_twoPagesMode_triggered\0"
    "on_twoPagesWithCoverPageMode_triggered\0"
    "on_multiplePagesMode_triggered\0"
    "on_rightToLeftMode_triggered\0"
    "on_zoomIn_triggered\0on_zoomOut_triggered\0"
    "on_originalSize_triggered\0"
    "on_fitToPageWidthMode_triggered\0"
    "on_fitToPageSizeMode_triggered\0"
    "on_rotateLeft_triggered\0"
    "on_rotateRight_triggered\0"
    "on_invertColors_triggered\0"
    "on_convertToGrayscale_triggered\0"
    "on_fonts_triggered\0on_fullscreen_triggered\0"
    "on_presentation_triggered\0"
    "on_previousTab_triggered\0on_nextTab_triggered\0"
    "on_closeTab_triggered\0on_closeAllTabs_triggered\0"
    "on_closeAllTabsButCurrentTab_triggered\0"
    "on_recentlyClosed_tabActionTriggered\0"
    "QAction*\0tabAction\0on_tabAction_triggered\0"
    "on_tabShortcut_activated\0"
    "on_previousBookmark_triggered\0"
    "on_nextBookmark_triggered\0"
    "on_addBookmark_triggered\0"
    "on_removeBookmark_triggered\0"
    "on_removeAllBookmarks_triggered\0"
    "on_bookmarksMenu_aboutToShow\0"
    "on_bookmark_openTriggered\0absoluteFilePath\0"
    "on_bookmark_openInNewTabTriggered\0"
    "on_bookmark_jumpToPageTriggered\0"
    "on_bookmark_removeBookmarkTriggered\0"
    "on_contents_triggered\0on_about_triggered\0"
    "currentPage_textFromValue\0value\0bool*\0"
    "ok\0currentPage_valueFromText\0"
    "on_focusCurrentPage_activated\0"
    "on_focusScaleFactor_activated\0"
    "on_toggleToolBars_triggered\0"
    "on_toggleMenuBar_triggered\0"
    "on_searchInitiated\0modified\0"
    "on_highlightAll_clicked\0"
    "on_dock_dockLocationChanged\0"
    "Qt::DockWidgetArea\0area\0"
    "on_outline_sectionCountChanged\0"
    "on_outline_clicked\0QModelIndex\0"
    "on_properties_sectionCountChanged\0"
    "on_thumbnails_dockLocationChanged\0"
    "on_thumbnails_verticalScrollBar_valueChanged\0"
    "on_bookmarks_sectionCountChanged\0"
    "on_bookmarks_clicked\0"
    "on_bookmarks_contextMenuRequested\0"
    "on_search_sectionCountChanged\0"
    "on_search_visibilityChanged\0visible\0"
    "on_search_clicked\0on_database_tabRestored\0"
    "on_saveDatabase_timeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qpdfview__MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     124,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,  634,    2, 0x0a /* Public */,
       1,    3,  643,    2, 0x2a /* Public | MethodCloned */,
       1,    2,  650,    2, 0x2a /* Public | MethodCloned */,
       1,    1,  655,    2, 0x2a /* Public | MethodCloned */,
       7,    4,  658,    2, 0x0a /* Public */,
       7,    3,  667,    2, 0x2a /* Public | MethodCloned */,
       7,    2,  674,    2, 0x2a /* Public | MethodCloned */,
       7,    1,  679,    2, 0x2a /* Public | MethodCloned */,
       8,    5,  682,    2, 0x0a /* Public */,
       8,    4,  693,    2, 0x2a /* Public | MethodCloned */,
       8,    3,  702,    2, 0x2a /* Public | MethodCloned */,
       8,    2,  709,    2, 0x2a /* Public | MethodCloned */,
       8,    1,  714,    2, 0x2a /* Public | MethodCloned */,
      10,    1,  717,    2, 0x0a /* Public */,
      12,    1,  720,    2, 0x09 /* Protected */,
      14,    1,  723,    2, 0x09 /* Protected */,
      15,    2,  726,    2, 0x09 /* Protected */,
      17,    0,  731,    2, 0x09 /* Protected */,
      18,    1,  732,    2, 0x09 /* Protected */,
      20,    1,  735,    2, 0x09 /* Protected */,
      22,    2,  738,    2, 0x09 /* Protected */,
      25,    1,  743,    2, 0x09 /* Protected */,
      27,    1,  746,    2, 0x09 /* Protected */,
      30,    1,  749,    2, 0x09 /* Protected */,
      32,    1,  752,    2, 0x09 /* Protected */,
      35,    1,  755,    2, 0x09 /* Protected */,
      37,    1,  758,    2, 0x09 /* Protected */,
      40,    1,  761,    2, 0x09 /* Protected */,
      40,    3,  764,    2, 0x09 /* Protected */,
      42,    1,  771,    2, 0x09 /* Protected */,
      44,    1,  774,    2, 0x09 /* Protected */,
      46,    1,  777,    2, 0x09 /* Protected */,
      48,    1,  780,    2, 0x09 /* Protected */,
      51,    0,  783,    2, 0x09 /* Protected */,
      52,    1,  784,    2, 0x09 /* Protected */,
      54,    1,  787,    2, 0x09 /* Protected */,
      56,    0,  790,    2, 0x09 /* Protected */,
      57,    0,  791,    2, 0x09 /* Protected */,
      58,    1,  792,    2, 0x09 /* Protected */,
      59,    0,  795,    2, 0x09 /* Protected */,
      60,    0,  796,    2, 0x09 /* Protected */,
      61,    0,  797,    2, 0x09 /* Protected */,
      62,    0,  798,    2, 0x09 /* Protected */,
      63,    0,  799,    2, 0x09 /* Protected */,
      64,    0,  800,    2, 0x09 /* Protected */,
      65,    0,  801,    2, 0x09 /* Protected */,
      66,    0,  802,    2, 0x09 /* Protected */,
      67,    0,  803,    2, 0x09 /* Protected */,
      68,    0,  804,    2, 0x09 /* Protected */,
      69,    1,  805,    2, 0x09 /* Protected */,
      70,    0,  808,    2, 0x09 /* Protected */,
      71,    0,  809,    2, 0x09 /* Protected */,
      72,    0,  810,    2, 0x09 /* Protected */,
      73,    0,  811,    2, 0x09 /* Protected */,
      74,    0,  812,    2, 0x09 /* Protected */,
      75,    0,  813,    2, 0x09 /* Protected */,
      76,    0,  814,    2, 0x09 /* Protected */,
      77,    0,  815,    2, 0x09 /* Protected */,
      78,    0,  816,    2, 0x09 /* Protected */,
      79,    0,  817,    2, 0x09 /* Protected */,
      80,    0,  818,    2, 0x09 /* Protected */,
      81,    0,  819,    2, 0x09 /* Protected */,
      82,    1,  820,    2, 0x09 /* Protected */,
      84,    1,  823,    2, 0x09 /* Protected */,
      85,    0,  826,    2, 0x09 /* Protected */,
      86,    1,  827,    2, 0x09 /* Protected */,
      87,    1,  830,    2, 0x09 /* Protected */,
      88,    1,  833,    2, 0x09 /* Protected */,
      89,    1,  836,    2, 0x09 /* Protected */,
      90,    1,  839,    2, 0x09 /* Protected */,
      91,    0,  842,    2, 0x09 /* Protected */,
      92,    0,  843,    2, 0x09 /* Protected */,
      93,    0,  844,    2, 0x09 /* Protected */,
      94,    1,  845,    2, 0x09 /* Protected */,
      95,    1,  848,    2, 0x09 /* Protected */,
      96,    0,  851,    2, 0x09 /* Protected */,
      97,    0,  852,    2, 0x09 /* Protected */,
      98,    1,  853,    2, 0x09 /* Protected */,
      99,    1,  856,    2, 0x09 /* Protected */,
     100,    0,  859,    2, 0x09 /* Protected */,
     101,    1,  860,    2, 0x09 /* Protected */,
     102,    0,  863,    2, 0x09 /* Protected */,
     103,    0,  864,    2, 0x09 /* Protected */,
     104,    0,  865,    2, 0x09 /* Protected */,
     105,    0,  866,    2, 0x09 /* Protected */,
     106,    0,  867,    2, 0x09 /* Protected */,
     107,    0,  868,    2, 0x09 /* Protected */,
     108,    1,  869,    2, 0x09 /* Protected */,
     111,    0,  872,    2, 0x09 /* Protected */,
     112,    0,  873,    2, 0x09 /* Protected */,
     113,    0,  874,    2, 0x09 /* Protected */,
     114,    0,  875,    2, 0x09 /* Protected */,
     115,    0,  876,    2, 0x09 /* Protected */,
     116,    0,  877,    2, 0x09 /* Protected */,
     117,    0,  878,    2, 0x09 /* Protected */,
     118,    0,  879,    2, 0x09 /* Protected */,
     119,    1,  880,    2, 0x09 /* Protected */,
     121,    1,  883,    2, 0x09 /* Protected */,
     122,    2,  886,    2, 0x09 /* Protected */,
     123,    1,  891,    2, 0x09 /* Protected */,
     124,    0,  894,    2, 0x09 /* Protected */,
     125,    0,  895,    2, 0x09 /* Protected */,
     126,    2,  896,    2, 0x09 /* Protected */,
     130,    2,  901,    2, 0x09 /* Protected */,
     131,    0,  906,    2, 0x09 /* Protected */,
     132,    0,  907,    2, 0x09 /* Protected */,
     133,    1,  908,    2, 0x09 /* Protected */,
     134,    1,  911,    2, 0x09 /* Protected */,
     135,    2,  914,    2, 0x09 /* Protected */,
     137,    1,  919,    2, 0x09 /* Protected */,
     138,    1,  922,    2, 0x09 /* Protected */,
     141,    0,  925,    2, 0x09 /* Protected */,
     142,    1,  926,    2, 0x09 /* Protected */,
     144,    0,  929,    2, 0x09 /* Protected */,
     145,    1,  930,    2, 0x09 /* Protected */,
     146,    1,  933,    2, 0x09 /* Protected */,
     147,    0,  936,    2, 0x09 /* Protected */,
     148,    1,  937,    2, 0x09 /* Protected */,
     149,    1,  940,    2, 0x09 /* Protected */,
     150,    0,  943,    2, 0x09 /* Protected */,
     151,    1,  944,    2, 0x09 /* Protected */,
     153,    1,  947,    2, 0x09 /* Protected */,
     154,    8,  950,    2, 0x09 /* Protected */,
     155,    0,  967,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QRectF, QMetaType::Bool,    3,    4,    5,    6,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QRectF,    3,    4,    5,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QRectF, QMetaType::Bool,    3,    4,    5,    6,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QRectF,    3,    4,    5,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::Bool, QMetaType::QRectF, QMetaType::Bool,    3,    4,    9,    5,    6,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::Bool, QMetaType::QRectF,    3,    4,    9,    5,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::Bool,    3,    4,    9,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int,    3,    4,
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::QPoint, QMetaType::Int,   16,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   23,   24,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void, QMetaType::Bool,   31,
    QMetaType::Void, 0x80000000 | 33,   34,
    QMetaType::Void, QMetaType::QReal,   36,
    QMetaType::Void, 0x80000000 | 38,   39,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString, QMetaType::Int,   41,    3,    4,
    QMetaType::Void, QMetaType::Bool,   43,
    QMetaType::Void, QMetaType::Bool,   45,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, 0x80000000 | 49,   50,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   53,
    QMetaType::Void, QMetaType::QPoint,   55,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
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
    QMetaType::Void, QMetaType::QString,    3,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   83,
    QMetaType::Void, QMetaType::Bool,   83,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   83,
    QMetaType::Void, QMetaType::Bool,   83,
    QMetaType::Void, QMetaType::Bool,   83,
    QMetaType::Void, QMetaType::Bool,   83,
    QMetaType::Void, QMetaType::Bool,   83,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   83,
    QMetaType::Void, QMetaType::Bool,   83,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   83,
    QMetaType::Void, QMetaType::Bool,   83,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   83,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 109,  110,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  120,
    QMetaType::Void, QMetaType::QString,  120,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,  120,    4,
    QMetaType::Void, QMetaType::QString,  120,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::Int, 0x80000000 | 128,  127,  129,
    QMetaType::Int, QMetaType::QString, 0x80000000 | 128,   11,  129,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   83,
    QMetaType::Void, QMetaType::Bool,   83,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   11,  136,
    QMetaType::Void, QMetaType::Bool,   83,
    QMetaType::Void, 0x80000000 | 139,  140,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 143,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 139,  140,
    QMetaType::Void, QMetaType::Int,  127,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 143,   13,
    QMetaType::Void, QMetaType::QPoint,   55,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,  152,
    QMetaType::Void, 0x80000000 | 143,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, 0x80000000 | 28, QMetaType::Bool, 0x80000000 | 33, QMetaType::QReal, 0x80000000 | 38, QMetaType::Int,  120,   26,   29,   31,   34,   36,   39,   21,
    QMetaType::Void,

       0        // eod
};

void qpdfview::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { bool _r = _t->open((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QRectF(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->open((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QRectF(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->open((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->open((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->openInNewTab((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QRectF(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->openInNewTab((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QRectF(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->openInNewTab((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->openInNewTab((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->jumpToPageOrOpenInNewTab((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< const QRectF(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->jumpToPageOrOpenInNewTab((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< const QRectF(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->jumpToPageOrOpenInNewTab((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->jumpToPageOrOpenInNewTab((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->jumpToPageOrOpenInNewTab((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->startSearch((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_tabWidget_tabCloseRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_tabWidget_tabContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 17: _t->on_currentTab_documentChanged(); break;
        case 18: _t->on_currentTab_numberOfPagesChaned((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_currentTab_currentPageChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->on_currentTab_canJumpChanged((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 21: _t->on_currentTab_continuousModeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->on_currentTab_layoutModeChanged((*reinterpret_cast< LayoutMode(*)>(_a[1]))); break;
        case 23: _t->on_currentTab_rightToLeftModeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->on_currentTab_scaleModeChanged((*reinterpret_cast< ScaleMode(*)>(_a[1]))); break;
        case 25: _t->on_currentTab_scaleFactorChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 26: _t->on_currentTab_rotationChanged((*reinterpret_cast< Rotation(*)>(_a[1]))); break;
        case 27: _t->on_currentTab_linkClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_currentTab_linkClicked((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 29: _t->on_currentTab_invertColorsChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->on_currentTab_convertToGrayscale((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->on_currentTab_highlightAllChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->on_currentTab_rubberBandModeChanged((*reinterpret_cast< RubberBandMode(*)>(_a[1]))); break;
        case 33: _t->on_currentTab_searchFinished(); break;
        case 34: _t->on_currentTab_searchProgressChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->on_currentTab_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 36: _t->on_currentPage_editingFinished(); break;
        case 37: _t->on_currentPage_returnPressed(); break;
        case 38: _t->on_scaleFactor_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->on_scaleFactor_editingFinished(); break;
        case 40: _t->on_scaleFactor_returnPressed(); break;
        case 41: _t->on_open_triggered(); break;
        case 42: _t->on_openInNewTab_triggered(); break;
        case 43: _t->on_openCopyInNewTab_triggered(); break;
        case 44: _t->on_openContainingFolder_triggered(); break;
        case 45: _t->on_refresh_triggered(); break;
        case 46: _t->on_saveCopy_triggered(); break;
        case 47: _t->on_saveAs_triggered(); break;
        case 48: _t->on_print_triggered(); break;
        case 49: _t->on_recentlyUsed_openTriggered((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 50: _t->on_previousPage_triggered(); break;
        case 51: _t->on_nextPage_triggered(); break;
        case 52: _t->on_firstPage_triggered(); break;
        case 53: _t->on_lastPage_triggered(); break;
        case 54: _t->on_setFirstPage_triggered(); break;
        case 55: _t->on_jumpToPage_triggered(); break;
        case 56: _t->on_jumpBackward_triggered(); break;
        case 57: _t->on_jumpForward_triggered(); break;
        case 58: _t->on_search_triggered(); break;
        case 59: _t->on_findPrevious_triggered(); break;
        case 60: _t->on_findNext_triggered(); break;
        case 61: _t->on_cancelSearch_triggered(); break;
        case 62: _t->on_copyToClipboardMode_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 63: _t->on_addAnnotationMode_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 64: _t->on_settings_triggered(); break;
        case 65: _t->on_continuousMode_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 66: _t->on_twoPagesMode_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 67: _t->on_twoPagesWithCoverPageMode_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 68: _t->on_multiplePagesMode_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 69: _t->on_rightToLeftMode_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 70: _t->on_zoomIn_triggered(); break;
        case 71: _t->on_zoomOut_triggered(); break;
        case 72: _t->on_originalSize_triggered(); break;
        case 73: _t->on_fitToPageWidthMode_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 74: _t->on_fitToPageSizeMode_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 75: _t->on_rotateLeft_triggered(); break;
        case 76: _t->on_rotateRight_triggered(); break;
        case 77: _t->on_invertColors_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 78: _t->on_convertToGrayscale_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 79: _t->on_fonts_triggered(); break;
        case 80: _t->on_fullscreen_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 81: _t->on_presentation_triggered(); break;
        case 82: _t->on_previousTab_triggered(); break;
        case 83: _t->on_nextTab_triggered(); break;
        case 84: _t->on_closeTab_triggered(); break;
        case 85: _t->on_closeAllTabs_triggered(); break;
        case 86: _t->on_closeAllTabsButCurrentTab_triggered(); break;
        case 87: _t->on_recentlyClosed_tabActionTriggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 88: _t->on_tabAction_triggered(); break;
        case 89: _t->on_tabShortcut_activated(); break;
        case 90: _t->on_previousBookmark_triggered(); break;
        case 91: _t->on_nextBookmark_triggered(); break;
        case 92: _t->on_addBookmark_triggered(); break;
        case 93: _t->on_removeBookmark_triggered(); break;
        case 94: _t->on_removeAllBookmarks_triggered(); break;
        case 95: _t->on_bookmarksMenu_aboutToShow(); break;
        case 96: _t->on_bookmark_openTriggered((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 97: _t->on_bookmark_openInNewTabTriggered((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 98: _t->on_bookmark_jumpToPageTriggered((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 99: _t->on_bookmark_removeBookmarkTriggered((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 100: _t->on_contents_triggered(); break;
        case 101: _t->on_about_triggered(); break;
        case 102: { QString _r = _t->currentPage_textFromValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 103: { int _r = _t->currentPage_valueFromText((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 104: _t->on_focusCurrentPage_activated(); break;
        case 105: _t->on_focusScaleFactor_activated(); break;
        case 106: _t->on_toggleToolBars_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 107: _t->on_toggleMenuBar_triggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 108: _t->on_searchInitiated((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 109: _t->on_highlightAll_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 110: _t->on_dock_dockLocationChanged((*reinterpret_cast< Qt::DockWidgetArea(*)>(_a[1]))); break;
        case 111: _t->on_outline_sectionCountChanged(); break;
        case 112: _t->on_outline_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 113: _t->on_properties_sectionCountChanged(); break;
        case 114: _t->on_thumbnails_dockLocationChanged((*reinterpret_cast< Qt::DockWidgetArea(*)>(_a[1]))); break;
        case 115: _t->on_thumbnails_verticalScrollBar_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 116: _t->on_bookmarks_sectionCountChanged(); break;
        case 117: _t->on_bookmarks_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 118: _t->on_bookmarks_contextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 119: _t->on_search_sectionCountChanged(); break;
        case 120: _t->on_search_visibilityChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 121: _t->on_search_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 122: _t->on_database_tabRestored((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< LayoutMode(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< ScaleMode(*)>(_a[5])),(*reinterpret_cast< qreal(*)>(_a[6])),(*reinterpret_cast< Rotation(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 123: _t->on_saveDatabase_timeout(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject qpdfview::MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_qpdfview__MainWindow.data,
    qt_meta_data_qpdfview__MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *qpdfview::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qpdfview::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qpdfview__MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int qpdfview::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 124)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 124;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 124)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 124;
    }
    return _id;
}
struct qt_meta_stringdata_qpdfview__MainWindowAdaptor_t {
    QByteArrayData data[37];
    char stringdata0[562];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qpdfview__MainWindowAdaptor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qpdfview__MainWindowAdaptor_t qt_meta_stringdata_qpdfview__MainWindowAdaptor = {
    {
QT_MOC_LITERAL(0, 0, 27), // "qpdfview::MainWindowAdaptor"
QT_MOC_LITERAL(1, 28, 15), // "D-Bus Interface"
QT_MOC_LITERAL(2, 44, 25), // "local.qpdfview.MainWindow"
QT_MOC_LITERAL(3, 70, 16), // "raiseAndActivate"
QT_MOC_LITERAL(4, 87, 9), // "Q_NOREPLY"
QT_MOC_LITERAL(5, 97, 4), // "open"
QT_MOC_LITERAL(6, 102, 0), // ""
QT_MOC_LITERAL(7, 103, 16), // "absoluteFilePath"
QT_MOC_LITERAL(8, 120, 4), // "page"
QT_MOC_LITERAL(9, 125, 9), // "highlight"
QT_MOC_LITERAL(10, 135, 5), // "quiet"
QT_MOC_LITERAL(11, 141, 12), // "openInNewTab"
QT_MOC_LITERAL(12, 154, 24), // "jumpToPageOrOpenInNewTab"
QT_MOC_LITERAL(13, 179, 17), // "refreshBeforeJump"
QT_MOC_LITERAL(14, 197, 11), // "startSearch"
QT_MOC_LITERAL(15, 209, 4), // "text"
QT_MOC_LITERAL(16, 214, 12), // "previousPage"
QT_MOC_LITERAL(17, 227, 8), // "nextPage"
QT_MOC_LITERAL(18, 236, 9), // "firstPage"
QT_MOC_LITERAL(19, 246, 8), // "lastPage"
QT_MOC_LITERAL(20, 255, 16), // "previousBookmark"
QT_MOC_LITERAL(21, 272, 12), // "nextBookmark"
QT_MOC_LITERAL(22, 285, 14), // "jumpToBookmark"
QT_MOC_LITERAL(23, 300, 5), // "label"
QT_MOC_LITERAL(24, 306, 20), // "continuousModeAction"
QT_MOC_LITERAL(25, 327, 7), // "checked"
QT_MOC_LITERAL(26, 335, 18), // "twoPagesModeAction"
QT_MOC_LITERAL(27, 354, 31), // "twoPagesWithCoverPageModeAction"
QT_MOC_LITERAL(28, 386, 23), // "multiplePagesModeAction"
QT_MOC_LITERAL(29, 410, 24), // "fitToPageWidthModeAction"
QT_MOC_LITERAL(30, 435, 23), // "fitToPageSizeModeAction"
QT_MOC_LITERAL(31, 459, 18), // "invertColorsAction"
QT_MOC_LITERAL(32, 478, 16), // "fullscreenAction"
QT_MOC_LITERAL(33, 495, 18), // "presentationAction"
QT_MOC_LITERAL(34, 514, 8), // "closeTab"
QT_MOC_LITERAL(35, 523, 12), // "closeAllTabs"
QT_MOC_LITERAL(36, 536, 25) // "closeAllTabsButCurrentTab"

    },
    "qpdfview::MainWindowAdaptor\0D-Bus Interface\0"
    "local.qpdfview.MainWindow\0raiseAndActivate\0"
    "Q_NOREPLY\0open\0\0absoluteFilePath\0page\0"
    "highlight\0quiet\0openInNewTab\0"
    "jumpToPageOrOpenInNewTab\0refreshBeforeJump\0"
    "startSearch\0text\0previousPage\0nextPage\0"
    "firstPage\0lastPage\0previousBookmark\0"
    "nextBookmark\0jumpToBookmark\0label\0"
    "continuousModeAction\0checked\0"
    "twoPagesModeAction\0twoPagesWithCoverPageModeAction\0"
    "multiplePagesModeAction\0"
    "fitToPageWidthModeAction\0"
    "fitToPageSizeModeAction\0invertColorsAction\0"
    "fullscreenAction\0presentationAction\0"
    "closeTab\0closeAllTabs\0closeAllTabsButCurrentTab"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qpdfview__MainWindowAdaptor[] = {

 // content:
       8,       // revision
       0,       // classname
       1,   14, // classinfo
      35,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,

 // slots: name, argc, parameters, tag, flags
       3,    0,  191,    4, 0x0a /* Public */,
       5,    4,  192,    6, 0x0a /* Public */,
       5,    3,  201,    6, 0x2a /* Public | MethodCloned */,
       5,    2,  208,    6, 0x2a /* Public | MethodCloned */,
       5,    1,  213,    6, 0x2a /* Public | MethodCloned */,
      11,    4,  216,    6, 0x0a /* Public */,
      11,    3,  225,    6, 0x2a /* Public | MethodCloned */,
      11,    2,  232,    6, 0x2a /* Public | MethodCloned */,
      11,    1,  237,    6, 0x2a /* Public | MethodCloned */,
      12,    5,  240,    6, 0x0a /* Public */,
      12,    4,  251,    6, 0x2a /* Public | MethodCloned */,
      12,    3,  260,    6, 0x2a /* Public | MethodCloned */,
      12,    2,  267,    6, 0x2a /* Public | MethodCloned */,
      12,    1,  272,    6, 0x2a /* Public | MethodCloned */,
      14,    1,  275,    4, 0x0a /* Public */,
      16,    0,  278,    4, 0x0a /* Public */,
      17,    0,  279,    4, 0x0a /* Public */,
      18,    0,  280,    4, 0x0a /* Public */,
      19,    0,  281,    4, 0x0a /* Public */,
      20,    0,  282,    4, 0x0a /* Public */,
      21,    0,  283,    4, 0x0a /* Public */,
      22,    1,  284,    6, 0x0a /* Public */,
      24,    1,  287,    4, 0x0a /* Public */,
      26,    1,  290,    4, 0x0a /* Public */,
      27,    1,  293,    4, 0x0a /* Public */,
      28,    1,  296,    4, 0x0a /* Public */,
      29,    1,  299,    4, 0x0a /* Public */,
      30,    1,  302,    4, 0x0a /* Public */,
      31,    1,  305,    4, 0x0a /* Public */,
      32,    1,  308,    4, 0x0a /* Public */,
      33,    0,  311,    4, 0x0a /* Public */,
      34,    0,  312,    4, 0x0a /* Public */,
      35,    0,  313,    4, 0x0a /* Public */,
      36,    0,  314,    4, 0x0a /* Public */,
      34,    1,  315,    6, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QRectF, QMetaType::Bool,    7,    8,    9,   10,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QRectF,    7,    8,    9,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int,    7,    8,
    QMetaType::Bool, QMetaType::QString,    7,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QRectF, QMetaType::Bool,    7,    8,    9,   10,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::QRectF,    7,    8,    9,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int,    7,    8,
    QMetaType::Bool, QMetaType::QString,    7,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::Bool, QMetaType::QRectF, QMetaType::Bool,    7,    8,   13,    9,   10,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::Bool, QMetaType::QRectF,    7,    8,   13,    9,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int, QMetaType::Bool,    7,    8,   13,
    QMetaType::Bool, QMetaType::QString, QMetaType::Int,    7,    8,
    QMetaType::Bool, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void, QMetaType::Bool,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,    7,

       0        // eod
};

void qpdfview::MainWindowAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindowAdaptor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->raiseAndActivate(); break;
        case 1: { bool _r = _t->open((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QRectF(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->open((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QRectF(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->open((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->open((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->openInNewTab((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QRectF(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->openInNewTab((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QRectF(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->openInNewTab((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->openInNewTab((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->jumpToPageOrOpenInNewTab((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< const QRectF(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->jumpToPageOrOpenInNewTab((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< const QRectF(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->jumpToPageOrOpenInNewTab((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->jumpToPageOrOpenInNewTab((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->jumpToPageOrOpenInNewTab((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->startSearch((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->previousPage(); break;
        case 16: _t->nextPage(); break;
        case 17: _t->firstPage(); break;
        case 18: _t->lastPage(); break;
        case 19: _t->previousBookmark(); break;
        case 20: _t->nextBookmark(); break;
        case 21: { bool _r = _t->jumpToBookmark((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 22: _t->continuousModeAction((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->twoPagesModeAction((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->twoPagesWithCoverPageModeAction((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->multiplePagesModeAction((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->fitToPageWidthModeAction((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->fitToPageSizeModeAction((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->invertColorsAction((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->fullscreenAction((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->presentationAction(); break;
        case 31: _t->closeTab(); break;
        case 32: _t->closeAllTabs(); break;
        case 33: _t->closeAllTabsButCurrentTab(); break;
        case 34: { bool _r = _t->closeTab((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject qpdfview::MainWindowAdaptor::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractAdaptor::staticMetaObject>(),
    qt_meta_stringdata_qpdfview__MainWindowAdaptor.data,
    qt_meta_data_qpdfview__MainWindowAdaptor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *qpdfview::MainWindowAdaptor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qpdfview::MainWindowAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qpdfview__MainWindowAdaptor.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int qpdfview::MainWindowAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 35;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
