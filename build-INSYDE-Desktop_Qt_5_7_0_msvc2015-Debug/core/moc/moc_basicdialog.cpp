/****************************************************************************
** Meta object code from reading C++ file 'basicdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../INSYDE/core/basicdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'basicdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BasicDialog_t {
    QByteArrayData data[19];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BasicDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BasicDialog_t qt_meta_stringdata_BasicDialog = {
    {
QT_MOC_LITERAL(0, 0, 11), // "BasicDialog"
QT_MOC_LITERAL(1, 12, 8), // "newClick"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 9), // "openClick"
QT_MOC_LITERAL(4, 32, 9), // "saveClick"
QT_MOC_LITERAL(5, 42, 11), // "saveAsClick"
QT_MOC_LITERAL(6, 54, 11), // "importClick"
QT_MOC_LITERAL(7, 66, 11), // "exportClick"
QT_MOC_LITERAL(8, 78, 16), // "preferencesClick"
QT_MOC_LITERAL(9, 95, 10), // "aboutClick"
QT_MOC_LITERAL(10, 106, 9), // "helpClick"
QT_MOC_LITERAL(11, 116, 9), // "undoClick"
QT_MOC_LITERAL(12, 126, 9), // "redoClick"
QT_MOC_LITERAL(13, 136, 9), // "copyClick"
QT_MOC_LITERAL(14, 146, 8), // "cutClick"
QT_MOC_LITERAL(15, 155, 10), // "pasteClick"
QT_MOC_LITERAL(16, 166, 20), // "onAlwaysOnTopClicked"
QT_MOC_LITERAL(17, 187, 7), // "checked"
QT_MOC_LITERAL(18, 195, 14) // "onApplyClicked"

    },
    "BasicDialog\0newClick\0\0openClick\0"
    "saveClick\0saveAsClick\0importClick\0"
    "exportClick\0preferencesClick\0aboutClick\0"
    "helpClick\0undoClick\0redoClick\0copyClick\0"
    "cutClick\0pasteClick\0onAlwaysOnTopClicked\0"
    "checked\0onApplyClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BasicDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x0a /* Public */,
       3,    0,   95,    2, 0x0a /* Public */,
       4,    0,   96,    2, 0x0a /* Public */,
       5,    0,   97,    2, 0x0a /* Public */,
       6,    0,   98,    2, 0x0a /* Public */,
       7,    0,   99,    2, 0x0a /* Public */,
       8,    0,  100,    2, 0x0a /* Public */,
       9,    0,  101,    2, 0x0a /* Public */,
      10,    0,  102,    2, 0x0a /* Public */,
      11,    0,  103,    2, 0x0a /* Public */,
      12,    0,  104,    2, 0x0a /* Public */,
      13,    0,  105,    2, 0x0a /* Public */,
      14,    0,  106,    2, 0x0a /* Public */,
      15,    0,  107,    2, 0x0a /* Public */,
      16,    1,  108,    2, 0x0a /* Public */,
      18,    0,  111,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void,

       0        // eod
};

void BasicDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BasicDialog *_t = static_cast<BasicDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newClick(); break;
        case 1: _t->openClick(); break;
        case 2: _t->saveClick(); break;
        case 3: _t->saveAsClick(); break;
        case 4: _t->importClick(); break;
        case 5: _t->exportClick(); break;
        case 6: _t->preferencesClick(); break;
        case 7: _t->aboutClick(); break;
        case 8: _t->helpClick(); break;
        case 9: _t->undoClick(); break;
        case 10: _t->redoClick(); break;
        case 11: _t->copyClick(); break;
        case 12: _t->cutClick(); break;
        case 13: _t->pasteClick(); break;
        case 14: _t->onAlwaysOnTopClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->onApplyClicked(); break;
        default: ;
        }
    }
}

const QMetaObject BasicDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_BasicDialog.data,
      qt_meta_data_BasicDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BasicDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BasicDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BasicDialog.stringdata0))
        return static_cast<void*>(const_cast< BasicDialog*>(this));
    if (!strcmp(_clname, "ClipboardInterface"))
        return static_cast< ClipboardInterface*>(const_cast< BasicDialog*>(this));
    if (!strcmp(_clname, "UnDoInterface"))
        return static_cast< UnDoInterface*>(const_cast< BasicDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int BasicDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
