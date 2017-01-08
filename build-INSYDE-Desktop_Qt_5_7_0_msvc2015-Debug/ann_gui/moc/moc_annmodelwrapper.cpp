/****************************************************************************
** Meta object code from reading C++ file 'annmodelwrapper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../INSYDE/ann_gui/annmodelwrapper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'annmodelwrapper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ANNModelWrapper_t {
    QByteArrayData data[12];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ANNModelWrapper_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ANNModelWrapper_t qt_meta_stringdata_ANNModelWrapper = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ANNModelWrapper"
QT_MOC_LITERAL(1, 16, 16), // "onWeightsChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 19), // "onLayerCountChanged"
QT_MOC_LITERAL(4, 54, 9), // "lastCount"
QT_MOC_LITERAL(5, 64, 8), // "newCount"
QT_MOC_LITERAL(6, 73, 14), // "onLayerRemoved"
QT_MOC_LITERAL(7, 88, 5), // "index"
QT_MOC_LITERAL(8, 94, 18), // "onLayerSizeChanged"
QT_MOC_LITERAL(9, 113, 5), // "layer"
QT_MOC_LITERAL(10, 119, 8), // "lastSize"
QT_MOC_LITERAL(11, 128, 7) // "newSize"

    },
    "ANNModelWrapper\0onWeightsChanged\0\0"
    "onLayerCountChanged\0lastCount\0newCount\0"
    "onLayerRemoved\0index\0onLayerSizeChanged\0"
    "layer\0lastSize\0newSize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ANNModelWrapper[] = {

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
       1,    0,   34,    2, 0x08 /* Private */,
       3,    2,   35,    2, 0x08 /* Private */,
       6,    1,   40,    2, 0x08 /* Private */,
       8,    3,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    9,   10,   11,

       0        // eod
};

void ANNModelWrapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ANNModelWrapper *_t = static_cast<ANNModelWrapper *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onWeightsChanged(); break;
        case 1: _t->onLayerCountChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->onLayerRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onLayerSizeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject ANNModelWrapper::staticMetaObject = {
    { &QAbstractItemModel::staticMetaObject, qt_meta_stringdata_ANNModelWrapper.data,
      qt_meta_data_ANNModelWrapper,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ANNModelWrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ANNModelWrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ANNModelWrapper.stringdata0))
        return static_cast<void*>(const_cast< ANNModelWrapper*>(this));
    return QAbstractItemModel::qt_metacast(_clname);
}

int ANNModelWrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
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
