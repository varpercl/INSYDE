/****************************************************************************
** Meta object code from reading C++ file 'KDChartAttributesModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDChart/KDChartAttributesModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KDChartAttributesModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDChart__AttributesModel_t {
    QByteArrayData data[17];
    char stringdata[277];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDChart__AttributesModel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDChart__AttributesModel_t qt_meta_stringdata_KDChart__AttributesModel = {
    {
QT_MOC_LITERAL(0, 0, 24), // "KDChart::AttributesModel"
QT_MOC_LITERAL(1, 25, 17), // "attributesChanged"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 25), // "slotRowsAboutToBeInserted"
QT_MOC_LITERAL(4, 70, 6), // "parent"
QT_MOC_LITERAL(5, 77, 5), // "start"
QT_MOC_LITERAL(6, 83, 3), // "end"
QT_MOC_LITERAL(7, 87, 28), // "slotColumnsAboutToBeInserted"
QT_MOC_LITERAL(8, 116, 16), // "slotRowsInserted"
QT_MOC_LITERAL(9, 133, 19), // "slotColumnsInserted"
QT_MOC_LITERAL(10, 153, 24), // "slotRowsAboutToBeRemoved"
QT_MOC_LITERAL(11, 178, 27), // "slotColumnsAboutToBeRemoved"
QT_MOC_LITERAL(12, 206, 15), // "slotRowsRemoved"
QT_MOC_LITERAL(13, 222, 18), // "slotColumnsRemoved"
QT_MOC_LITERAL(14, 241, 15), // "slotDataChanged"
QT_MOC_LITERAL(15, 257, 7), // "topLeft"
QT_MOC_LITERAL(16, 265, 11) // "bottomRight"

    },
    "KDChart::AttributesModel\0attributesChanged\0"
    "\0slotRowsAboutToBeInserted\0parent\0"
    "start\0end\0slotColumnsAboutToBeInserted\0"
    "slotRowsInserted\0slotColumnsInserted\0"
    "slotRowsAboutToBeRemoved\0"
    "slotColumnsAboutToBeRemoved\0slotRowsRemoved\0"
    "slotColumnsRemoved\0slotDataChanged\0"
    "topLeft\0bottomRight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDChart__AttributesModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    3,   69,    2, 0x08 /* Private */,
       7,    3,   76,    2, 0x08 /* Private */,
       8,    3,   83,    2, 0x08 /* Private */,
       9,    3,   90,    2, 0x08 /* Private */,
      10,    3,   97,    2, 0x08 /* Private */,
      11,    3,  104,    2, 0x08 /* Private */,
      12,    3,  111,    2, 0x08 /* Private */,
      13,    3,  118,    2, 0x08 /* Private */,
      14,    2,  125,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,   15,   16,

       0        // eod
};

void KDChart::AttributesModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AttributesModel *_t = static_cast<AttributesModel *>(_o);
        switch (_id) {
        case 0: _t->attributesChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 1: _t->slotRowsAboutToBeInserted((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->slotColumnsAboutToBeInserted((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->slotRowsInserted((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->slotColumnsInserted((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: _t->slotRowsAboutToBeRemoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->slotColumnsAboutToBeRemoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->slotRowsRemoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->slotColumnsRemoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 9: _t->slotDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AttributesModel::*_t)(const QModelIndex & , const QModelIndex & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AttributesModel::attributesChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject KDChart::AttributesModel::staticMetaObject = {
    { &AbstractProxyModel::staticMetaObject, qt_meta_stringdata_KDChart__AttributesModel.data,
      qt_meta_data_KDChart__AttributesModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDChart::AttributesModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDChart::AttributesModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDChart__AttributesModel.stringdata))
        return static_cast<void*>(const_cast< AttributesModel*>(this));
    return AbstractProxyModel::qt_metacast(_clname);
}

int KDChart::AttributesModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractProxyModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void KDChart::AttributesModel::attributesChanged(const QModelIndex & _t1, const QModelIndex & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
