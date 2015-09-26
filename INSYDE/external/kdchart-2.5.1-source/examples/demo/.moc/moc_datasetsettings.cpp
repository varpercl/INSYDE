/****************************************************************************
** Meta object code from reading C++ file 'datasetsettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../datasetsettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datasetsettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DatasetSettings_t {
    QByteArrayData data[9];
    char stringdata[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DatasetSettings_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DatasetSettings_t qt_meta_stringdata_DatasetSettings = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DatasetSettings"
QT_MOC_LITERAL(1, 16, 19), // "datasetCountChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 15), // "setDatasetCount"
QT_MOC_LITERAL(4, 53, 5), // "value"
QT_MOC_LITERAL(5, 59, 12), // "indexChanged"
QT_MOC_LITERAL(6, 72, 5), // "index"
QT_MOC_LITERAL(7, 78, 18), // "diagramTypeChanged"
QT_MOC_LITERAL(8, 97, 12) // "datasetCount"

    },
    "DatasetSettings\0datasetCountChanged\0"
    "\0setDatasetCount\0value\0indexChanged\0"
    "index\0diagramTypeChanged\0datasetCount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DatasetSettings[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       1,   42, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   35,    2, 0x0a /* Public */,
       5,    1,   38,    2, 0x0a /* Public */,
       7,    0,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,

 // properties: name, type, flags
       8, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void DatasetSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DatasetSettings *_t = static_cast<DatasetSettings *>(_o);
        switch (_id) {
        case 0: _t->datasetCountChanged(); break;
        case 1: _t->setDatasetCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->indexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->diagramTypeChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DatasetSettings::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DatasetSettings::datasetCountChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject DatasetSettings::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DatasetSettings.data,
      qt_meta_data_DatasetSettings,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DatasetSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DatasetSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DatasetSettings.stringdata))
        return static_cast<void*>(const_cast< DatasetSettings*>(this));
    return QWidget::qt_metacast(_clname);
}

int DatasetSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = datasetCount(); break;
        default: break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setDatasetCount(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void DatasetSettings::datasetCountChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
