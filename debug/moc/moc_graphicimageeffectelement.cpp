/****************************************************************************
** Meta object code from reading C++ file 'graphicimageeffectelement.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../graphicimageeffectelement.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphicimageeffectelement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GraphicImageEffectElement_t {
    QByteArrayData data[6];
    char stringdata[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GraphicImageEffectElement_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GraphicImageEffectElement_t qt_meta_stringdata_GraphicImageEffectElement = {
    {
QT_MOC_LITERAL(0, 0, 25),
QT_MOC_LITERAL(1, 26, 15),
QT_MOC_LITERAL(2, 42, 0),
QT_MOC_LITERAL(3, 43, 11),
QT_MOC_LITERAL(4, 55, 19),
QT_MOC_LITERAL(5, 75, 3)
    },
    "GraphicImageEffectElement\0onPropertyClick\0"
    "\0onOpenClick\0onInputImageChanged\0img\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphicImageEffectElement[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x09,
       3,    0,   30,    2, 0x09,
       4,    1,   31,    2, 0x09,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    5,

       0        // eod
};

void GraphicImageEffectElement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphicImageEffectElement *_t = static_cast<GraphicImageEffectElement *>(_o);
        switch (_id) {
        case 0: _t->onPropertyClick(); break;
        case 1: _t->onOpenClick(); break;
        case 2: _t->onInputImageChanged((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject GraphicImageEffectElement::staticMetaObject = {
    { &GraphicCursorElement::staticMetaObject, qt_meta_stringdata_GraphicImageEffectElement.data,
      qt_meta_data_GraphicImageEffectElement,  qt_static_metacall, 0, 0}
};


const QMetaObject *GraphicImageEffectElement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphicImageEffectElement::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GraphicImageEffectElement.stringdata))
        return static_cast<void*>(const_cast< GraphicImageEffectElement*>(this));
    return GraphicCursorElement::qt_metacast(_clname);
}

int GraphicImageEffectElement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphicCursorElement::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
