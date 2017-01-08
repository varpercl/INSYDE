/****************************************************************************
** Meta object code from reading C++ file 'imagepropertydialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../INSYDE/core/imagepropertydialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagepropertydialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_core__ImagePropertyDialog_t {
    QByteArrayData data[6];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_core__ImagePropertyDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_core__ImagePropertyDialog_t qt_meta_stringdata_core__ImagePropertyDialog = {
    {
QT_MOC_LITERAL(0, 0, 25), // "core::ImagePropertyDialog"
QT_MOC_LITERAL(1, 26, 6), // "accept"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 14), // "onApplyClicked"
QT_MOC_LITERAL(4, 49, 17), // "onFilePathChanged"
QT_MOC_LITERAL(5, 67, 4) // "path"

    },
    "core::ImagePropertyDialog\0accept\0\0"
    "onApplyClicked\0onFilePathChanged\0path"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_core__ImagePropertyDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    1,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void core::ImagePropertyDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImagePropertyDialog *_t = static_cast<ImagePropertyDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->accept(); break;
        case 1: _t->onApplyClicked(); break;
        case 2: _t->onFilePathChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject core::ImagePropertyDialog::staticMetaObject = {
    { &GraphicObjectPropertyDialog::staticMetaObject, qt_meta_stringdata_core__ImagePropertyDialog.data,
      qt_meta_data_core__ImagePropertyDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *core::ImagePropertyDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *core::ImagePropertyDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_core__ImagePropertyDialog.stringdata0))
        return static_cast<void*>(const_cast< ImagePropertyDialog*>(this));
    return GraphicObjectPropertyDialog::qt_metacast(_clname);
}

int core::ImagePropertyDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphicObjectPropertyDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
