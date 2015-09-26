/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata[418];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 33), // "on_lineTypeCB_currentIndexCha..."
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 4), // "text"
QT_MOC_LITERAL(4, 51, 24), // "on_paintLegendCB_toggled"
QT_MOC_LITERAL(5, 76, 7), // "checked"
QT_MOC_LITERAL(6, 84, 24), // "on_paintValuesCB_toggled"
QT_MOC_LITERAL(7, 109, 25), // "on_paintMarkersCB_toggled"
QT_MOC_LITERAL(8, 135, 37), // "on_markersStyleCB_currentInde..."
QT_MOC_LITERAL(9, 173, 30), // "on_markersWidthSB_valueChanged"
QT_MOC_LITERAL(10, 204, 1), // "i"
QT_MOC_LITERAL(11, 206, 31), // "on_markersHeightSB_valueChanged"
QT_MOC_LITERAL(12, 238, 25), // "on_displayAreasCB_toggled"
QT_MOC_LITERAL(13, 264, 30), // "on_transparencySB_valueChanged"
QT_MOC_LITERAL(14, 295, 28), // "on_zoomFactorSB_valueChanged"
QT_MOC_LITERAL(15, 324, 6), // "factor"
QT_MOC_LITERAL(16, 331, 21), // "on_hSBar_valueChanged"
QT_MOC_LITERAL(17, 353, 5), // "value"
QT_MOC_LITERAL(18, 359, 21), // "on_vSBar_valueChanged"
QT_MOC_LITERAL(19, 381, 17), // "on_savePB_clicked"
QT_MOC_LITERAL(20, 399, 18) // "on_savePDF_clicked"

    },
    "MainWindow\0on_lineTypeCB_currentIndexChanged\0"
    "\0text\0on_paintLegendCB_toggled\0checked\0"
    "on_paintValuesCB_toggled\0"
    "on_paintMarkersCB_toggled\0"
    "on_markersStyleCB_currentIndexChanged\0"
    "on_markersWidthSB_valueChanged\0i\0"
    "on_markersHeightSB_valueChanged\0"
    "on_displayAreasCB_toggled\0"
    "on_transparencySB_valueChanged\0"
    "on_zoomFactorSB_valueChanged\0factor\0"
    "on_hSBar_valueChanged\0value\0"
    "on_vSBar_valueChanged\0on_savePB_clicked\0"
    "on_savePDF_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x08 /* Private */,
       4,    1,   87,    2, 0x08 /* Private */,
       6,    1,   90,    2, 0x08 /* Private */,
       7,    1,   93,    2, 0x08 /* Private */,
       8,    1,   96,    2, 0x08 /* Private */,
       9,    1,   99,    2, 0x08 /* Private */,
      11,    1,  102,    2, 0x08 /* Private */,
      12,    1,  105,    2, 0x08 /* Private */,
      13,    1,  108,    2, 0x08 /* Private */,
      14,    1,  111,    2, 0x08 /* Private */,
      16,    1,  114,    2, 0x08 /* Private */,
      18,    1,  117,    2, 0x08 /* Private */,
      19,    0,  120,    2, 0x08 /* Private */,
      20,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Double,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_lineTypeCB_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_paintLegendCB_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_paintValuesCB_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_paintMarkersCB_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_markersStyleCB_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_markersWidthSB_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_markersHeightSB_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_displayAreasCB_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_transparencySB_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_zoomFactorSB_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->on_hSBar_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_vSBar_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_savePB_clicked(); break;
        case 13: _t->on_savePDF_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
