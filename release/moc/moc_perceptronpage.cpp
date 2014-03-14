/****************************************************************************
** Meta object code from reading C++ file 'perceptronpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ANNGraphicInterface/perceptronpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'perceptronpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PerceptronPage_t {
    QByteArrayData data[11];
    char stringdata[234];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PerceptronPage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PerceptronPage_t qt_meta_stringdata_PerceptronPage = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 16),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 24),
QT_MOC_LITERAL(4, 58, 4),
QT_MOC_LITERAL(5, 63, 27),
QT_MOC_LITERAL(6, 91, 41),
QT_MOC_LITERAL(7, 133, 5),
QT_MOC_LITERAL(8, 139, 37),
QT_MOC_LITERAL(9, 177, 25),
QT_MOC_LITERAL(10, 203, 29)
    },
    "PerceptronPage\0updatePerceptron\0\0"
    "on_sbInputs_valueChanged\0arg1\0"
    "on_sbInputs_editingFinished\0"
    "on_cbTransferFunction_currentIndexChanged\0"
    "index\0on_cbLearningRule_currentIndexChanged\0"
    "on_btnEditWeights_clicked\0"
    "on_btnEditTrainingSet_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PerceptronPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a,
       3,    1,   50,    2, 0x08,
       5,    0,   53,    2, 0x08,
       6,    1,   54,    2, 0x08,
       8,    1,   57,    2, 0x08,
       9,    0,   60,    2, 0x08,
      10,    0,   61,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PerceptronPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PerceptronPage *_t = static_cast<PerceptronPage *>(_o);
        switch (_id) {
        case 0: _t->updatePerceptron(); break;
        case 1: _t->on_sbInputs_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_sbInputs_editingFinished(); break;
        case 3: _t->on_cbTransferFunction_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_cbLearningRule_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_btnEditWeights_clicked(); break;
        case 6: _t->on_btnEditTrainingSet_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject PerceptronPage::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_PerceptronPage.data,
      qt_meta_data_PerceptronPage,  qt_static_metacall, 0, 0}
};


const QMetaObject *PerceptronPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PerceptronPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PerceptronPage.stringdata))
        return static_cast<void*>(const_cast< PerceptronPage*>(this));
    return QWizardPage::qt_metacast(_clname);
}

int PerceptronPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
