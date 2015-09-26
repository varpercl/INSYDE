/****************************************************************************
** Meta object code from reading C++ file 'KDChartDatasetProxyModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDChart/KDChartDatasetProxyModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KDChartDatasetProxyModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDChart__DatasetProxyModel_t {
    QByteArrayData data[9];
    char stringdata[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDChart__DatasetProxyModel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDChart__DatasetProxyModel_t qt_meta_stringdata_KDChart__DatasetProxyModel = {
    {
QT_MOC_LITERAL(0, 0, 26), // "KDChart::DatasetProxyModel"
QT_MOC_LITERAL(1, 27, 24), // "resetDatasetDescriptions"
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 33), // "setDatasetColumnDescriptionVe..."
QT_MOC_LITERAL(4, 87, 24), // "DatasetDescriptionVector"
QT_MOC_LITERAL(5, 112, 12), // "columnConfig"
QT_MOC_LITERAL(6, 125, 30), // "setDatasetRowDescriptionVector"
QT_MOC_LITERAL(7, 156, 9), // "rowConfig"
QT_MOC_LITERAL(8, 166, 28) // "setDatasetDescriptionVectors"

    },
    "KDChart::DatasetProxyModel\0"
    "resetDatasetDescriptions\0\0"
    "setDatasetColumnDescriptionVector\0"
    "DatasetDescriptionVector\0columnConfig\0"
    "setDatasetRowDescriptionVector\0rowConfig\0"
    "setDatasetDescriptionVectors"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDChart__DatasetProxyModel[] = {

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
       1,    0,   34,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x0a /* Public */,
       6,    1,   38,    2, 0x0a /* Public */,
       8,    2,   41,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    7,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    7,    5,

       0        // eod
};

void KDChart::DatasetProxyModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DatasetProxyModel *_t = static_cast<DatasetProxyModel *>(_o);
        switch (_id) {
        case 0: _t->resetDatasetDescriptions(); break;
        case 1: _t->setDatasetColumnDescriptionVector((*reinterpret_cast< const DatasetDescriptionVector(*)>(_a[1]))); break;
        case 2: _t->setDatasetRowDescriptionVector((*reinterpret_cast< const DatasetDescriptionVector(*)>(_a[1]))); break;
        case 3: _t->setDatasetDescriptionVectors((*reinterpret_cast< const DatasetDescriptionVector(*)>(_a[1])),(*reinterpret_cast< const DatasetDescriptionVector(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject KDChart::DatasetProxyModel::staticMetaObject = {
    { &QSortFilterProxyModel::staticMetaObject, qt_meta_stringdata_KDChart__DatasetProxyModel.data,
      qt_meta_data_KDChart__DatasetProxyModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDChart::DatasetProxyModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDChart::DatasetProxyModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDChart__DatasetProxyModel.stringdata))
        return static_cast<void*>(const_cast< DatasetProxyModel*>(this));
    return QSortFilterProxyModel::qt_metacast(_clname);
}

int KDChart::DatasetProxyModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSortFilterProxyModel::qt_metacall(_c, _id, _a);
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
