/****************************************************************************
** Meta object code from reading C++ file 'graphicmlpelement.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
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
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GraphicMLPElement_t {
    QByteArrayData data[17];
    char stringdata[224];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GraphicMLPElement_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GraphicMLPElement_t qt_meta_stringdata_GraphicMLPElement = {
    {
QT_MOC_LITERAL(0, 0, 17), // "GraphicMLPElement"
QT_MOC_LITERAL(1, 18, 13), // "outputChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 15), // "QVector<double>"
QT_MOC_LITERAL(4, 49, 7), // "outputs"
QT_MOC_LITERAL(5, 57, 13), // "QVector<char>"
QT_MOC_LITERAL(6, 71, 5), // "chars"
QT_MOC_LITERAL(7, 77, 15), // "onPropertyClick"
QT_MOC_LITERAL(8, 93, 11), // "onOpenClick"
QT_MOC_LITERAL(9, 105, 18), // "onAddToTrainingSet"
QT_MOC_LITERAL(10, 124, 24), // "onDotMatrixStatusChanged"
QT_MOC_LITERAL(11, 149, 12), // "QVector<int>"
QT_MOC_LITERAL(12, 162, 11), // "vector<int>"
QT_MOC_LITERAL(13, 174, 12), // "onTrainClick"
QT_MOC_LITERAL(14, 187, 14), // "onAnalizeClick"
QT_MOC_LITERAL(15, 202, 17), // "updateInputCursor"
QT_MOC_LITERAL(16, 220, 3) // "pos"

    },
    "GraphicMLPElement\0outputChanged\0\0"
    "QVector<double>\0outputs\0QVector<char>\0"
    "chars\0onPropertyClick\0onOpenClick\0"
    "onAddToTrainingSet\0onDotMatrixStatusChanged\0"
    "QVector<int>\0vector<int>\0onTrainClick\0"
    "onAnalizeClick\0updateInputCursor\0pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphicMLPElement[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       1,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   70,    2, 0x09 /* Protected */,
       8,    0,   71,    2, 0x09 /* Protected */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    1,   73,    2, 0x08 /* Private */,
      10,    1,   76,    2, 0x08 /* Private */,
      13,    0,   79,    2, 0x08 /* Private */,
      14,    0,   80,    2, 0x08 /* Private */,
      15,    1,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    4,
    QMetaType::Void, 0x80000000 | 12,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,

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
        case 6: _t->onDotMatrixStatusChanged((*reinterpret_cast< vector<int>(*)>(_a[1]))); break;
        case 7: _t->onTrainClick(); break;
        case 8: _t->onAnalizeClick(); break;
        case 9: _t->updateInputCursor((*reinterpret_cast< int(*)>(_a[1]))); break;
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
      qt_meta_data_GraphicMLPElement,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GraphicMLPElement::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphicMLPElement::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void GraphicMLPElement::outputChanged(QVector<double> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GraphicMLPElement::outputChanged(QVector<char> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
