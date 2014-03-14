/****************************************************************************
** Meta object code from reading C++ file 'dotmatrix.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dotmatrix.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dotmatrix.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DotMatrix_t {
    QByteArrayData data[11];
    char stringdata[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_DotMatrix_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_DotMatrix_t qt_meta_stringdata_DotMatrix = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 13),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 22),
QT_MOC_LITERAL(4, 48, 6),
QT_MOC_LITERAL(5, 55, 12),
QT_MOC_LITERAL(6, 68, 15),
QT_MOC_LITERAL(7, 84, 11),
QT_MOC_LITERAL(8, 96, 18),
QT_MOC_LITERAL(9, 115, 15),
QT_MOC_LITERAL(10, 131, 6)
    },
    "DotMatrix\0statusChanged\0\0"
    "QVector<QVector<int> >\0matrix\0"
    "QVector<int>\0onPropertyClick\0onOpenClick\0"
    "onMLPOutputChanged\0QVector<double>\0"
    "inputs\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DotMatrix[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06,
       1,    1,   42,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       6,    0,   45,    2, 0x09,
       7,    0,   46,    2, 0x09,
       8,    1,   47,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 5,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void DotMatrix::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DotMatrix *_t = static_cast<DotMatrix *>(_o);
        switch (_id) {
        case 0: _t->statusChanged((*reinterpret_cast< QVector<QVector<int> >(*)>(_a[1]))); break;
        case 1: _t->statusChanged((*reinterpret_cast< QVector<int>(*)>(_a[1]))); break;
        case 2: _t->onPropertyClick(); break;
        case 3: _t->onOpenClick(); break;
        case 4: _t->onMLPOutputChanged((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QVector<int> > >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DotMatrix::*_t)(QVector<QVector<int> > );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DotMatrix::statusChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (DotMatrix::*_t)(QVector<int> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DotMatrix::statusChanged)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject DotMatrix::staticMetaObject = {
    { &GraphicElement::staticMetaObject, qt_meta_stringdata_DotMatrix.data,
      qt_meta_data_DotMatrix,  qt_static_metacall, 0, 0}
};


const QMetaObject *DotMatrix::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DotMatrix::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DotMatrix.stringdata))
        return static_cast<void*>(const_cast< DotMatrix*>(this));
    return GraphicElement::qt_metacast(_clname);
}

int DotMatrix::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphicElement::qt_metacall(_c, _id, _a);
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
void DotMatrix::statusChanged(QVector<QVector<int> > _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DotMatrix::statusChanged(QVector<int> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
