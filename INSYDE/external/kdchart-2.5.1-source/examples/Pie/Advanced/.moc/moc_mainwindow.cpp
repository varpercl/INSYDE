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
    QByteArrayData data[15];
    char stringdata[246];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 31), // "on_startPositionSB_valueChanged"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 3), // "pos"
QT_MOC_LITERAL(4, 48, 31), // "on_startPositionSL_valueChanged"
QT_MOC_LITERAL(5, 80, 26), // "on_explodeSubmitPB_clicked"
QT_MOC_LITERAL(6, 107, 29), // "on_animateExplosionCB_toggled"
QT_MOC_LITERAL(7, 137, 6), // "toggle"
QT_MOC_LITERAL(8, 144, 16), // "setExplodeFactor"
QT_MOC_LITERAL(9, 161, 6), // "column"
QT_MOC_LITERAL(10, 168, 5), // "value"
QT_MOC_LITERAL(11, 174, 13), // "slotNextFrame"
QT_MOC_LITERAL(12, 188, 19), // "on_threeDGB_toggled"
QT_MOC_LITERAL(13, 208, 30), // "on_threeDFactorSB_valueChanged"
QT_MOC_LITERAL(14, 239, 6) // "factor"

    },
    "MainWindow\0on_startPositionSB_valueChanged\0"
    "\0pos\0on_startPositionSL_valueChanged\0"
    "on_explodeSubmitPB_clicked\0"
    "on_animateExplosionCB_toggled\0toggle\0"
    "setExplodeFactor\0column\0value\0"
    "slotNextFrame\0on_threeDGB_toggled\0"
    "on_threeDFactorSB_valueChanged\0factor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x08 /* Private */,
       4,    1,   57,    2, 0x08 /* Private */,
       5,    0,   60,    2, 0x08 /* Private */,
       6,    1,   61,    2, 0x08 /* Private */,
       8,    2,   64,    2, 0x08 /* Private */,
      11,    0,   69,    2, 0x08 /* Private */,
      12,    1,   70,    2, 0x08 /* Private */,
      13,    1,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::QReal,    9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Int,   14,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_startPositionSB_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->on_startPositionSL_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_explodeSubmitPB_clicked(); break;
        case 3: _t->on_animateExplosionCB_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setExplodeFactor((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< qreal(*)>(_a[2]))); break;
        case 5: _t->slotNextFrame(); break;
        case 6: _t->on_threeDGB_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_threeDFactorSB_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
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
QT_END_MOC_NAMESPACE
