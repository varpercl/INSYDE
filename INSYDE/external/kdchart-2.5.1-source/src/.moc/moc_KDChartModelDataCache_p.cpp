/****************************************************************************
** Meta object code from reading C++ file 'KDChartModelDataCache_p.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDChart/KDChartModelDataCache_p.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KDChartModelDataCache_p.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDChart__ModelDataCachePrivate__ModelSignalMapperConnector_t {
    QByteArrayData data[10];
    char stringdata[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDChart__ModelDataCachePrivate__ModelSignalMapperConnector_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDChart__ModelDataCachePrivate__ModelSignalMapperConnector_t qt_meta_stringdata_KDChart__ModelDataCachePrivate__ModelSignalMapperConnector = {
    {
QT_MOC_LITERAL(0, 0, 58), // "KDChart::ModelDataCachePrivat..."
QT_MOC_LITERAL(1, 59, 10), // "resetModel"
QT_MOC_LITERAL(2, 70, 0), // ""
QT_MOC_LITERAL(3, 71, 15), // "columnsInserted"
QT_MOC_LITERAL(4, 87, 14), // "columnsRemoved"
QT_MOC_LITERAL(5, 102, 11), // "dataChanged"
QT_MOC_LITERAL(6, 114, 13), // "layoutChanged"
QT_MOC_LITERAL(7, 128, 10), // "modelReset"
QT_MOC_LITERAL(8, 139, 12), // "rowsInserted"
QT_MOC_LITERAL(9, 152, 11) // "rowsRemoved"

    },
    "KDChart::ModelDataCachePrivate::ModelSignalMapperConnector\0"
    "resetModel\0\0columnsInserted\0columnsRemoved\0"
    "dataChanged\0layoutChanged\0modelReset\0"
    "rowsInserted\0rowsRemoved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDChart__ModelDataCachePrivate__ModelSignalMapperConnector[] = {

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
       1,    0,   54,    2, 0x09 /* Protected */,
       3,    3,   55,    2, 0x09 /* Protected */,
       4,    3,   62,    2, 0x09 /* Protected */,
       5,    2,   69,    2, 0x09 /* Protected */,
       6,    0,   74,    2, 0x09 /* Protected */,
       7,    0,   75,    2, 0x09 /* Protected */,
       8,    3,   76,    2, 0x09 /* Protected */,
       9,    3,   83,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::Int, QMetaType::Int,    2,    2,    2,

       0        // eod
};

void KDChart::ModelDataCachePrivate::ModelSignalMapperConnector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ModelSignalMapperConnector *_t = static_cast<ModelSignalMapperConnector *>(_o);
        switch (_id) {
        case 0: _t->resetModel(); break;
        case 1: _t->columnsInserted((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->columnsRemoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->dataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 4: _t->layoutChanged(); break;
        case 5: _t->modelReset(); break;
        case 6: _t->rowsInserted((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->rowsRemoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject KDChart::ModelDataCachePrivate::ModelSignalMapperConnector::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KDChart__ModelDataCachePrivate__ModelSignalMapperConnector.data,
      qt_meta_data_KDChart__ModelDataCachePrivate__ModelSignalMapperConnector,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDChart::ModelDataCachePrivate::ModelSignalMapperConnector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDChart::ModelDataCachePrivate::ModelSignalMapperConnector::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDChart__ModelDataCachePrivate__ModelSignalMapperConnector.stringdata))
        return static_cast<void*>(const_cast< ModelSignalMapperConnector*>(this));
    return QObject::qt_metacast(_clname);
}

int KDChart::ModelDataCachePrivate::ModelSignalMapperConnector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
