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
    QByteArrayData data[16];
    char stringdata[325];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 32), // "on_barTypeCB_currentIndexChanged"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 4), // "text"
QT_MOC_LITERAL(4, 50, 39), // "on_barOrientationCB_currentIn..."
QT_MOC_LITERAL(5, 90, 24), // "on_paintValuesCB_toggled"
QT_MOC_LITERAL(6, 115, 7), // "checked"
QT_MOC_LITERAL(7, 123, 28), // "on_paintThreeDBarsCB_toggled"
QT_MOC_LITERAL(8, 152, 23), // "on_markColumnCB_toggled"
QT_MOC_LITERAL(9, 176, 28), // "on_markColumnSB_valueChanged"
QT_MOC_LITERAL(10, 205, 1), // "i"
QT_MOC_LITERAL(11, 207, 24), // "on_threeDDepthCB_toggled"
QT_MOC_LITERAL(12, 232, 23), // "on_depthSB_valueChanged"
QT_MOC_LITERAL(13, 256, 18), // "on_widthCB_toggled"
QT_MOC_LITERAL(14, 275, 23), // "on_widthSB_valueChanged"
QT_MOC_LITERAL(15, 299, 25) // "on_fixPlaneSizeCB_toggled"

    },
    "MainWindow\0on_barTypeCB_currentIndexChanged\0"
    "\0text\0on_barOrientationCB_currentIndexChanged\0"
    "on_paintValuesCB_toggled\0checked\0"
    "on_paintThreeDBarsCB_toggled\0"
    "on_markColumnCB_toggled\0"
    "on_markColumnSB_valueChanged\0i\0"
    "on_threeDDepthCB_toggled\0"
    "on_depthSB_valueChanged\0on_widthCB_toggled\0"
    "on_widthSB_valueChanged\0"
    "on_fixPlaneSizeCB_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x08 /* Private */,
       4,    1,   72,    2, 0x08 /* Private */,
       5,    1,   75,    2, 0x08 /* Private */,
       7,    1,   78,    2, 0x08 /* Private */,
       8,    1,   81,    2, 0x08 /* Private */,
       9,    1,   84,    2, 0x08 /* Private */,
      11,    1,   87,    2, 0x08 /* Private */,
      12,    1,   90,    2, 0x08 /* Private */,
      13,    1,   93,    2, 0x08 /* Private */,
      14,    1,   96,    2, 0x08 /* Private */,
      15,    1,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Bool,    6,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_barTypeCB_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_barOrientationCB_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_paintValuesCB_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_paintThreeDBarsCB_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_markColumnCB_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_markColumnSB_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_threeDDepthCB_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_depthSB_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_widthCB_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_widthSB_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_fixPlaneSizeCB_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
