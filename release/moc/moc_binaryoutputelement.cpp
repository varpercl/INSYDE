/****************************************************************************
** Meta object code from reading C++ file 'binaryoutputelement.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../binaryoutputelement.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'binaryoutputelement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BinaryOutputElement_t {
    QByteArrayData data[7];
    char stringdata[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_BinaryOutputElement_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_BinaryOutputElement_t qt_meta_stringdata_BinaryOutputElement = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 14),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 15),
QT_MOC_LITERAL(4, 52, 5),
QT_MOC_LITERAL(5, 58, 15),
QT_MOC_LITERAL(6, 74, 11)
    },
    "BinaryOutputElement\0onInputChanged\0\0"
    "QVector<double>\0input\0onPropertyClick\0"
    "onOpenClick\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BinaryOutputElement[] = {

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
       1,    1,   29,    2, 0x09,
       5,    0,   32,    2, 0x09,
       6,    0,   33,    2, 0x09,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BinaryOutputElement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BinaryOutputElement *_t = static_cast<BinaryOutputElement *>(_o);
        switch (_id) {
        case 0: _t->onInputChanged((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 1: _t->onPropertyClick(); break;
        case 2: _t->onOpenClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    }
}

const QMetaObject BinaryOutputElement::staticMetaObject = {
    { &GraphicElement::staticMetaObject, qt_meta_stringdata_BinaryOutputElement.data,
      qt_meta_data_BinaryOutputElement,  qt_static_metacall, 0, 0}
};


const QMetaObject *BinaryOutputElement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BinaryOutputElement::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BinaryOutputElement.stringdata))
        return static_cast<void*>(const_cast< BinaryOutputElement*>(this));
    return GraphicElement::qt_metacast(_clname);
}

int BinaryOutputElement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphicElement::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
