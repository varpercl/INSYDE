/****************************************************************************
** Meta object code from reading C++ file 'timechartmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../timechartmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timechartmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TimeChartModel_t {
    QByteArrayData data[10];
    char stringdata[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimeChartModel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimeChartModel_t qt_meta_stringdata_TimeChartModel = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TimeChartModel"
QT_MOC_LITERAL(1, 15, 15), // "setVisibleRange"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "start"
QT_MOC_LITERAL(4, 38, 3), // "end"
QT_MOC_LITERAL(5, 42, 15), // "setVisibleStart"
QT_MOC_LITERAL(6, 58, 13), // "setVisibleEnd"
QT_MOC_LITERAL(7, 72, 4), // "data"
QT_MOC_LITERAL(8, 77, 5), // "index"
QT_MOC_LITERAL(9, 83, 4) // "role"

    },
    "TimeChartModel\0setVisibleRange\0\0start\0"
    "end\0setVisibleStart\0setVisibleEnd\0"
    "data\0index\0role"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimeChartModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x0a /* Public */,
       5,    1,   44,    2, 0x0a /* Public */,
       6,    1,   47,    2, 0x0a /* Public */,
       7,    2,   50,    2, 0x0a /* Public */,
       7,    1,   55,    2, 0x2a /* Public | MethodCloned */,

 // slots: parameters
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QDateTime,    3,    4,
    QMetaType::Void, QMetaType::QDateTime,    3,
    QMetaType::Void, QMetaType::QDateTime,    4,
    QMetaType::QVariant, QMetaType::QModelIndex, QMetaType::Int,    8,    9,
    QMetaType::QVariant, QMetaType::QModelIndex,    8,

       0        // eod
};

void TimeChartModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimeChartModel *_t = static_cast<TimeChartModel *>(_o);
        switch (_id) {
        case 0: _t->setVisibleRange((*reinterpret_cast< const QDateTime(*)>(_a[1])),(*reinterpret_cast< const QDateTime(*)>(_a[2]))); break;
        case 1: _t->setVisibleStart((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 2: _t->setVisibleEnd((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 3: { QVariant _r = _t->data((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 4: { QVariant _r = _t->data((*reinterpret_cast< const QModelIndex(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject TimeChartModel::staticMetaObject = {
    { &QSortFilterProxyModel::staticMetaObject, qt_meta_stringdata_TimeChartModel.data,
      qt_meta_data_TimeChartModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimeChartModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimeChartModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimeChartModel.stringdata))
        return static_cast<void*>(const_cast< TimeChartModel*>(this));
    return QSortFilterProxyModel::qt_metacast(_clname);
}

int TimeChartModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSortFilterProxyModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
