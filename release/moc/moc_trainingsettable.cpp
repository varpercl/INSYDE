/****************************************************************************
** Meta object code from reading C++ file 'trainingsettable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ANNGraphicInterface/trainingsettable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trainingsettable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TrainingSetTable_t {
    QByteArrayData data[31];
    char stringdata[340];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_TrainingSetTable_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_TrainingSetTable_t qt_meta_stringdata_TrainingSetTable = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 18),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 18),
QT_MOC_LITERAL(4, 56, 2),
QT_MOC_LITERAL(5, 59, 15),
QT_MOC_LITERAL(6, 75, 23),
QT_MOC_LITERAL(7, 99, 2),
QT_MOC_LITERAL(8, 102, 2),
QT_MOC_LITERAL(9, 105, 16),
QT_MOC_LITERAL(10, 122, 2),
QT_MOC_LITERAL(11, 125, 2),
QT_MOC_LITERAL(12, 128, 18),
QT_MOC_LITERAL(13, 147, 2),
QT_MOC_LITERAL(14, 150, 2),
QT_MOC_LITERAL(15, 153, 19),
QT_MOC_LITERAL(16, 173, 14),
QT_MOC_LITERAL(17, 188, 14),
QT_MOC_LITERAL(18, 203, 6),
QT_MOC_LITERAL(19, 210, 7),
QT_MOC_LITERAL(20, 218, 16),
QT_MOC_LITERAL(21, 235, 5),
QT_MOC_LITERAL(22, 241, 17),
QT_MOC_LITERAL(23, 259, 14),
QT_MOC_LITERAL(24, 274, 3),
QT_MOC_LITERAL(25, 278, 5),
QT_MOC_LITERAL(26, 284, 15),
QT_MOC_LITERAL(27, 300, 16),
QT_MOC_LITERAL(28, 317, 13),
QT_MOC_LITERAL(29, 331, 3),
QT_MOC_LITERAL(30, 335, 3)
    },
    "TrainingSetTable\0trainingSetChanged\0"
    "\0const TrainingSet*\0ts\0onInputsChanged\0"
    "vector<vector<double> >\0li\0ni\0"
    "onTargetsChanged\0lt\0nt\0onInputSizeChanged\0"
    "ls\0ns\0onTargetSizeChanged\0onPatternAdded\0"
    "vector<double>\0inputs\0targets\0"
    "onPatternDeleted\0index\0onPatternInserted\0"
    "onInputChanged\0pat\0value\0onTargetChanged\0"
    "onPatternChanged\0onCellChanged\0row\0"
    "col\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrainingSetTable[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    2,   77,    2, 0x08,
       9,    2,   82,    2, 0x08,
      12,    2,   87,    2, 0x08,
      15,    2,   92,    2, 0x08,
      16,    2,   97,    2, 0x08,
      20,    3,  102,    2, 0x08,
      22,    3,  109,    2, 0x08,
      23,    3,  116,    2, 0x08,
      26,    3,  123,    2, 0x08,
      27,    3,  130,    2, 0x08,
      28,    2,  137,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,   10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   13,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   13,   14,
    QMetaType::Void, 0x80000000 | 17, 0x80000000 | 17,   18,   19,
    QMetaType::Void, 0x80000000 | 17, 0x80000000 | 17, QMetaType::Int,   18,   19,   21,
    QMetaType::Void, 0x80000000 | 17, 0x80000000 | 17, QMetaType::Int,   18,   19,   21,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Double,   24,   21,   25,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Double,   24,   21,   25,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 17, 0x80000000 | 17,   21,   18,   19,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   29,   30,

       0        // eod
};

void TrainingSetTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TrainingSetTable *_t = static_cast<TrainingSetTable *>(_o);
        switch (_id) {
        case 0: _t->trainingSetChanged((*reinterpret_cast< const TrainingSet*(*)>(_a[1]))); break;
        case 1: _t->onInputsChanged((*reinterpret_cast< const vector<vector<double> >(*)>(_a[1])),(*reinterpret_cast< const vector<vector<double> >(*)>(_a[2]))); break;
        case 2: _t->onTargetsChanged((*reinterpret_cast< const vector<vector<double> >(*)>(_a[1])),(*reinterpret_cast< const vector<vector<double> >(*)>(_a[2]))); break;
        case 3: _t->onInputSizeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->onTargetSizeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->onPatternAdded((*reinterpret_cast< const vector<double>(*)>(_a[1])),(*reinterpret_cast< const vector<double>(*)>(_a[2]))); break;
        case 6: _t->onPatternDeleted((*reinterpret_cast< const vector<double>(*)>(_a[1])),(*reinterpret_cast< const vector<double>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->onPatternInserted((*reinterpret_cast< const vector<double>(*)>(_a[1])),(*reinterpret_cast< const vector<double>(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->onInputChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 9: _t->onTargetChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 10: _t->onPatternChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const vector<double>(*)>(_a[2])),(*reinterpret_cast< const vector<double>(*)>(_a[3]))); break;
        case 11: _t->onCellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TrainingSetTable::*_t)(const TrainingSet * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TrainingSetTable::trainingSetChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject TrainingSetTable::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_TrainingSetTable.data,
      qt_meta_data_TrainingSetTable,  qt_static_metacall, 0, 0}
};


const QMetaObject *TrainingSetTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrainingSetTable::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TrainingSetTable.stringdata))
        return static_cast<void*>(const_cast< TrainingSetTable*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int TrainingSetTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void TrainingSetTable::trainingSetChanged(const TrainingSet * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
