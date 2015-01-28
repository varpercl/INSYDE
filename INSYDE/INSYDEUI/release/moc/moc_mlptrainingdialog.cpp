/****************************************************************************
** Meta object code from reading C++ file 'mlptrainingdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ANNGraphicInterface/mlptrainingdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mlptrainingdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MLPTrainingDialog_t {
    QByteArrayData data[28];
    char stringdata[571];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MLPTrainingDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MLPTrainingDialog_t qt_meta_stringdata_MLPTrainingDialog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "MLPTrainingDialog"
QT_MOC_LITERAL(1, 18, 10), // "exportData"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 18), // "onTrainingFinished"
QT_MOC_LITERAL(4, 49, 17), // "MLPTrainingResult"
QT_MOC_LITERAL(5, 67, 4), // "tres"
QT_MOC_LITERAL(6, 72, 22), // "multipleTrainingResult"
QT_MOC_LITERAL(7, 95, 18), // "MLPTrainingResult*"
QT_MOC_LITERAL(8, 114, 18), // "updateStatusLabels"
QT_MOC_LITERAL(9, 133, 29), // "on_btnEditTrainingSet_clicked"
QT_MOC_LITERAL(10, 163, 42), // "on_cbTrainingAlgorithm_curren..."
QT_MOC_LITERAL(11, 206, 5), // "index"
QT_MOC_LITERAL(12, 212, 41), // "on_cbTrasnferFunction_current..."
QT_MOC_LITERAL(13, 254, 19), // "on_btnTrain_clicked"
QT_MOC_LITERAL(14, 274, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(15, 295, 23), // "on_btnRandomize_clicked"
QT_MOC_LITERAL(16, 319, 22), // "onTblLayersCellChanged"
QT_MOC_LITERAL(17, 342, 3), // "row"
QT_MOC_LITERAL(18, 346, 6), // "column"
QT_MOC_LITERAL(19, 353, 32), // "on_btnEditValidationTest_clicked"
QT_MOC_LITERAL(20, 386, 25), // "on_btnEditTestSet_clicked"
QT_MOC_LITERAL(21, 412, 22), // "on_btnAddLayer_clicked"
QT_MOC_LITERAL(22, 435, 25), // "on_btnDeleteLayer_clicked"
QT_MOC_LITERAL(23, 461, 30), // "on_btnMultipleTraining_clicked"
QT_MOC_LITERAL(24, 492, 38), // "on_cbStopCondition_currentInd..."
QT_MOC_LITERAL(25, 531, 16), // "on_chkSA_toggled"
QT_MOC_LITERAL(26, 548, 7), // "checked"
QT_MOC_LITERAL(27, 556, 14) // "generateReport"

    },
    "MLPTrainingDialog\0exportData\0\0"
    "onTrainingFinished\0MLPTrainingResult\0"
    "tres\0multipleTrainingResult\0"
    "MLPTrainingResult*\0updateStatusLabels\0"
    "on_btnEditTrainingSet_clicked\0"
    "on_cbTrainingAlgorithm_currentIndexChanged\0"
    "index\0on_cbTrasnferFunction_currentIndexChanged\0"
    "on_btnTrain_clicked\0on_btnCancel_clicked\0"
    "on_btnRandomize_clicked\0onTblLayersCellChanged\0"
    "row\0column\0on_btnEditValidationTest_clicked\0"
    "on_btnEditTestSet_clicked\0"
    "on_btnAddLayer_clicked\0on_btnDeleteLayer_clicked\0"
    "on_btnMultipleTraining_clicked\0"
    "on_cbStopCondition_currentIndexChanged\0"
    "on_chkSA_toggled\0checked\0generateReport"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MLPTrainingDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x08 /* Private */,
       3,    1,  110,    2, 0x08 /* Private */,
       6,    1,  113,    2, 0x08 /* Private */,
       8,    1,  116,    2, 0x08 /* Private */,
       9,    0,  119,    2, 0x08 /* Private */,
      10,    1,  120,    2, 0x08 /* Private */,
      12,    1,  123,    2, 0x08 /* Private */,
      13,    0,  126,    2, 0x08 /* Private */,
      14,    0,  127,    2, 0x08 /* Private */,
      15,    0,  128,    2, 0x08 /* Private */,
      16,    2,  129,    2, 0x08 /* Private */,
      19,    0,  134,    2, 0x08 /* Private */,
      20,    0,  135,    2, 0x08 /* Private */,
      21,    0,  136,    2, 0x08 /* Private */,
      22,    0,  137,    2, 0x08 /* Private */,
      23,    0,  138,    2, 0x08 /* Private */,
      24,    1,  139,    2, 0x08 /* Private */,
      25,    1,  142,    2, 0x08 /* Private */,
      27,    0,  145,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void,

       0        // eod
};

void MLPTrainingDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MLPTrainingDialog *_t = static_cast<MLPTrainingDialog *>(_o);
        switch (_id) {
        case 0: _t->exportData(); break;
        case 1: _t->onTrainingFinished((*reinterpret_cast< MLPTrainingResult(*)>(_a[1]))); break;
        case 2: _t->multipleTrainingResult((*reinterpret_cast< MLPTrainingResult*(*)>(_a[1]))); break;
        case 3: _t->updateStatusLabels((*reinterpret_cast< const MLPTrainingResult(*)>(_a[1]))); break;
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
        case 18: _t->generateReport(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MLPTrainingResult* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MLPTrainingDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MLPTrainingDialog.data,
      qt_meta_data_MLPTrainingDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MLPTrainingDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MLPTrainingDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
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
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
