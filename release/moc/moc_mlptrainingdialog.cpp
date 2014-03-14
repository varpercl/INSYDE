/****************************************************************************
** Meta object code from reading C++ file 'mlptrainingdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ANNGraphicInterface/mlptrainingdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mlptrainingdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MLPTrainingDialog_t {
    QByteArrayData data[26];
    char stringdata[537];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MLPTrainingDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MLPTrainingDialog_t qt_meta_stringdata_MLPTrainingDialog = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 10),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 16),
QT_MOC_LITERAL(4, 47, 18),
QT_MOC_LITERAL(5, 66, 4),
QT_MOC_LITERAL(6, 71, 22),
QT_MOC_LITERAL(7, 94, 18),
QT_MOC_LITERAL(8, 113, 29),
QT_MOC_LITERAL(9, 143, 42),
QT_MOC_LITERAL(10, 186, 5),
QT_MOC_LITERAL(11, 192, 41),
QT_MOC_LITERAL(12, 234, 19),
QT_MOC_LITERAL(13, 254, 20),
QT_MOC_LITERAL(14, 275, 23),
QT_MOC_LITERAL(15, 299, 22),
QT_MOC_LITERAL(16, 322, 3),
QT_MOC_LITERAL(17, 326, 6),
QT_MOC_LITERAL(18, 333, 32),
QT_MOC_LITERAL(19, 366, 25),
QT_MOC_LITERAL(20, 392, 22),
QT_MOC_LITERAL(21, 415, 25),
QT_MOC_LITERAL(22, 441, 30),
QT_MOC_LITERAL(23, 472, 38),
QT_MOC_LITERAL(24, 511, 16),
QT_MOC_LITERAL(25, 528, 7)
    },
    "MLPTrainingDialog\0exportData\0\0"
    "trainingFinished\0MLPTrainingResult*\0"
    "tres\0multipleTrainingResult\0"
    "updateStatusLabels\0on_btnEditTrainingSet_clicked\0"
    "on_cbTrainingAlgorithm_currentIndexChanged\0"
    "index\0on_cbTrasnferFunction_currentIndexChanged\0"
    "on_btnTrain_clicked\0on_btnCancel_clicked\0"
    "on_btnRandomize_clicked\0onTblLayersCellChanged\0"
    "row\0column\0on_btnEditValidationTest_clicked\0"
    "on_btnEditTestSet_clicked\0"
    "on_btnAddLayer_clicked\0on_btnDeleteLayer_clicked\0"
    "on_btnMultipleTraining_clicked\0"
    "on_cbStopCondition_currentIndexChanged\0"
    "on_chkSA_toggled\0checked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLPTrainingDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x08,
       3,    1,  105,    2, 0x08,
       6,    1,  108,    2, 0x08,
       7,    0,  111,    2, 0x08,
       8,    0,  112,    2, 0x08,
       9,    1,  113,    2, 0x08,
      11,    1,  116,    2, 0x08,
      12,    0,  119,    2, 0x08,
      13,    0,  120,    2, 0x08,
      14,    0,  121,    2, 0x08,
      15,    2,  122,    2, 0x08,
      18,    0,  127,    2, 0x08,
      19,    0,  128,    2, 0x08,
      20,    0,  129,    2, 0x08,
      21,    0,  130,    2, 0x08,
      22,    0,  131,    2, 0x08,
      23,    1,  132,    2, 0x08,
      24,    1,  135,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Bool,   25,

       0        // eod
};

void MLPTrainingDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MLPTrainingDialog *_t = static_cast<MLPTrainingDialog *>(_o);
        switch (_id) {
        case 0: _t->exportData(); break;
        case 1: _t->trainingFinished((*reinterpret_cast< MLPTrainingResult*(*)>(_a[1]))); break;
        case 2: _t->multipleTrainingResult((*reinterpret_cast< MLPTrainingResult*(*)>(_a[1]))); break;
        case 3: _t->updateStatusLabels(); break;
        case 4: _t->on_btnEditTrainingSet_clicked(); break;
        case 5: _t->on_cbTrainingAlgorithm_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_cbTrasnferFunction_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_btnTrain_clicked(); break;
        case 8: _t->on_btnCancel_clicked(); break;
        case 9: _t->on_btnRandomize_clicked(); break;
        case 10: _t->onTblLayersCellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->on_btnEditValidationTest_clicked(); break;
        case 12: _t->on_btnEditTestSet_clicked(); break;
        case 13: _t->on_btnAddLayer_clicked(); break;
        case 14: _t->on_btnDeleteLayer_clicked(); break;
        case 15: _t->on_btnMultipleTraining_clicked(); break;
        case 16: _t->on_cbStopCondition_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->on_chkSA_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MLPTrainingDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MLPTrainingDialog.data,
      qt_meta_data_MLPTrainingDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *MLPTrainingDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLPTrainingDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MLPTrainingDialog.stringdata))
        return static_cast<void*>(const_cast< MLPTrainingDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MLPTrainingDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
