/****************************************************************************
** Meta object code from reading C++ file 'KDChartDatasetSelector.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDChart/KDChartDatasetSelector.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KDChartDatasetSelector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDChart__DatasetSelectorWidget_t {
    QByteArrayData data[18];
    char stringdata[380];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDChart__DatasetSelectorWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDChart__DatasetSelectorWidget_t qt_meta_stringdata_KDChart__DatasetSelectorWidget = {
    {
QT_MOC_LITERAL(0, 0, 30), // "KDChart::DatasetSelectorWidget"
QT_MOC_LITERAL(1, 31, 26), // "configureDatasetProxyModel"
QT_MOC_LITERAL(2, 58, 0), // ""
QT_MOC_LITERAL(3, 59, 24), // "DatasetDescriptionVector"
QT_MOC_LITERAL(4, 84, 9), // "rowConfig"
QT_MOC_LITERAL(5, 94, 12), // "columnConfig"
QT_MOC_LITERAL(6, 107, 15), // "mappingDisabled"
QT_MOC_LITERAL(7, 123, 17), // "setSourceRowCount"
QT_MOC_LITERAL(8, 141, 8), // "rowCount"
QT_MOC_LITERAL(9, 150, 20), // "setSourceColumnCount"
QT_MOC_LITERAL(10, 171, 11), // "columnCount"
QT_MOC_LITERAL(11, 183, 29), // "on_sbStartColumn_valueChanged"
QT_MOC_LITERAL(12, 213, 26), // "on_sbStartRow_valueChanged"
QT_MOC_LITERAL(13, 240, 29), // "on_sbColumnCount_valueChanged"
QT_MOC_LITERAL(14, 270, 26), // "on_sbRowCount_valueChanged"
QT_MOC_LITERAL(15, 297, 29), // "on_cbReverseRows_stateChanged"
QT_MOC_LITERAL(16, 327, 32), // "on_cbReverseColumns_stateChanged"
QT_MOC_LITERAL(17, 360, 19) // "on_groupBox_toggled"

    },
    "KDChart::DatasetSelectorWidget\0"
    "configureDatasetProxyModel\0\0"
    "DatasetDescriptionVector\0rowConfig\0"
    "columnConfig\0mappingDisabled\0"
    "setSourceRowCount\0rowCount\0"
    "setSourceColumnCount\0columnCount\0"
    "on_sbStartColumn_valueChanged\0"
    "on_sbStartRow_valueChanged\0"
    "on_sbColumnCount_valueChanged\0"
    "on_sbRowCount_valueChanged\0"
    "on_cbReverseRows_stateChanged\0"
    "on_cbReverseColumns_stateChanged\0"
    "on_groupBox_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDChart__DatasetSelectorWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       6,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   75,    2, 0x0a /* Public */,
       9,    1,   78,    2, 0x0a /* Public */,
      11,    1,   81,    2, 0x08 /* Private */,
      12,    1,   84,    2, 0x08 /* Private */,
      13,    1,   87,    2, 0x08 /* Private */,
      14,    1,   90,    2, 0x08 /* Private */,
      15,    1,   93,    2, 0x08 /* Private */,
      16,    1,   96,    2, 0x08 /* Private */,
      17,    1,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void KDChart::DatasetSelectorWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DatasetSelectorWidget *_t = static_cast<DatasetSelectorWidget *>(_o);
        switch (_id) {
        case 0: _t->configureDatasetProxyModel((*reinterpret_cast< const DatasetDescriptionVector(*)>(_a[1])),(*reinterpret_cast< const DatasetDescriptionVector(*)>(_a[2]))); break;
        case 1: _t->mappingDisabled(); break;
        case 2: _t->setSourceRowCount((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: _t->setSourceColumnCount((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 4: _t->on_sbStartColumn_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_sbStartRow_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_sbColumnCount_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_sbRowCount_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_cbReverseRows_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_cbReverseColumns_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_groupBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DatasetSelectorWidget::*_t)(const DatasetDescriptionVector & , const DatasetDescriptionVector & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DatasetSelectorWidget::configureDatasetProxyModel)) {
                *result = 0;
            }
        }
        {
            typedef void (DatasetSelectorWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DatasetSelectorWidget::mappingDisabled)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject KDChart::DatasetSelectorWidget::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_KDChart__DatasetSelectorWidget.data,
      qt_meta_data_KDChart__DatasetSelectorWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDChart::DatasetSelectorWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDChart::DatasetSelectorWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDChart__DatasetSelectorWidget.stringdata))
        return static_cast<void*>(const_cast< DatasetSelectorWidget*>(this));
    return QFrame::qt_metacast(_clname);
}

int KDChart::DatasetSelectorWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void KDChart::DatasetSelectorWidget::configureDatasetProxyModel(const DatasetDescriptionVector & _t1, const DatasetDescriptionVector & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KDChart::DatasetSelectorWidget::mappingDisabled()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
