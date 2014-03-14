/****************************************************************************
** Meta object code from reading C++ file 'graphicimageelementdetailedwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../graphicimageelementdetailedwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphicimageelementdetailedwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GraphicImageElementDetailedWindow_t {
    QByteArrayData data[7];
    char stringdata[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GraphicImageElementDetailedWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GraphicImageElementDetailedWindow_t qt_meta_stringdata_GraphicImageElementDetailedWindow = {
    {
QT_MOC_LITERAL(0, 0, 33),
QT_MOC_LITERAL(1, 34, 11),
QT_MOC_LITERAL(2, 46, 0),
QT_MOC_LITERAL(3, 47, 3),
QT_MOC_LITERAL(4, 51, 9),
QT_MOC_LITERAL(5, 61, 13),
QT_MOC_LITERAL(6, 75, 14)
    },
    "GraphicImageElementDetailedWindow\0"
    "contextMenu\0\0pos\0saveImage\0onZoomInClick\0"
    "onZoomOutClick\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphicImageElementDetailedWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x09,
       4,    0,   37,    2, 0x09,
       5,    0,   38,    2, 0x09,
       6,    0,   39,    2, 0x09,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GraphicImageElementDetailedWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphicImageElementDetailedWindow *_t = static_cast<GraphicImageElementDetailedWindow *>(_o);
        switch (_id) {
        case 0: _t->contextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->saveImage(); break;
        case 2: _t->onZoomInClick(); break;
        case 3: _t->onZoomOutClick(); break;
        default: ;
        }
    }
}

const QMetaObject GraphicImageElementDetailedWindow::staticMetaObject = {
    { &GraphicElementDetailedWindow::staticMetaObject, qt_meta_stringdata_GraphicImageElementDetailedWindow.data,
      qt_meta_data_GraphicImageElementDetailedWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *GraphicImageElementDetailedWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphicImageElementDetailedWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GraphicImageElementDetailedWindow.stringdata))
        return static_cast<void*>(const_cast< GraphicImageElementDetailedWindow*>(this));
    return GraphicElementDetailedWindow::qt_metacast(_clname);
}

int GraphicImageElementDetailedWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphicElementDetailedWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
