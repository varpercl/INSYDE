/****************************************************************************
** Meta object code from reading C++ file 'graphicmlpelement.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ANNGraphicInterface/graphicmlpelement.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphicmlpelement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GraphicMLPElement_t {
    QByteArrayData data[16];
    char stringdata[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GraphicMLPElement_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GraphicMLPElement_t qt_meta_stringdata_GraphicMLPElement = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 13),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 15),
QT_MOC_LITERAL(4, 49, 7),
QT_MOC_LITERAL(5, 57, 13),
QT_MOC_LITERAL(6, 71, 5),
QT_MOC_LITERAL(7, 77, 15),
QT_MOC_LITERAL(8, 93, 11),
QT_MOC_LITERAL(9, 105, 18),
QT_MOC_LITERAL(10, 124, 24),
QT_MOC_LITERAL(11, 149, 12),
QT_MOC_LITERAL(12, 162, 12),
QT_MOC_LITERAL(13, 175, 14),
QT_MOC_LITERAL(14, 190, 17),
QT_MOC_LITERAL(15, 208, 3)
    },
    "GraphicMLPElement\0outputChanged\0\0"
    "QVector<double>\0outputs\0QVector<char>\0"
    "chars\0onPropertyClick\0onOpenClick\0"
    "onAddToTrainingSet\0onDotMatrixStatusChanged\0"
    "QVector<int>\0onTrainClick\0onAnalizeClick\0"
    "updateInputCursor\0pos\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphicMLPElement[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06,
       1,    1,   62,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    0,   65,    2, 0x09,
       8,    0,   66,    2, 0x09,
       9,    0,   67,    2, 0x08,
      10,    1,   68,    2, 0x08,
      12,    0,   71,    2, 0x08,
      13,    0,   72,    2, 0x08,
      14,    1,   73,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,

       0        // eod
};

void GraphicMLPElement::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphicMLPElement *_t = static_cast<GraphicMLPElement *>(_o);
        switch (_id) {
        case 0: _t->outputChanged((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 1: _t->outputChanged((*reinterpret_cast< QVector<char>(*)>(_a[1]))); break;
        case 2: _t->onPropertyClick(); break;
        case 3: _t->onOpenClick(); break;
        case 4: _t->onAddToTrainingSet(); break;
        case 5: _t->onDotMatrixStatusChanged((*reinterpret_cast< QVector<int>(*)>(_a[1]))); break;
        case 6: _t->onTrainClick(); break;
        case 7: _t->onAnalizeClick(); break;
        case 8: _t->updateInputCursor((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<char> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GraphicMLPElement::*_t)(QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicMLPElement::outputChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (GraphicMLPElement::*_t)(QVector<char> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicMLPElement::outputChanged)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject GraphicMLPElement::staticMetaObject = {
    { &GraphicElement::staticMetaObject, qt_meta_stringdata_GraphicMLPElement.data,
      qt_meta_data_GraphicMLPElement,  qt_static_metacall, 0, 0}
};


const QMetaObject *GraphicMLPElement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphicMLPElement::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GraphicMLPElement.stringdata))
        return static_cast<void*>(const_cast< GraphicMLPElement*>(this));
    return GraphicElement::qt_metacast(_clname);
}

int GraphicMLPElement::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphicElement::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void GraphicMLPElement::outputChanged(QVector<double> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GraphicMLPElement::outputChanged(QVector<char> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
