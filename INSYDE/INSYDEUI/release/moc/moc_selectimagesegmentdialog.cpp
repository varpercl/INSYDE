/****************************************************************************
** Meta object code from reading C++ file 'selectimagesegmentdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../selectimagesegmentdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectimagesegmentdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SelectImageSegmentDialog_t {
    QByteArrayData data[6];
    char stringdata[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SelectImageSegmentDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SelectImageSegmentDialog_t qt_meta_stringdata_SelectImageSegmentDialog = {
    {
QT_MOC_LITERAL(0, 0, 24), // "SelectImageSegmentDialog"
QT_MOC_LITERAL(1, 25, 14), // "onWidthChanged"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 5), // "width"
QT_MOC_LITERAL(4, 47, 15), // "onHeightChanged"
QT_MOC_LITERAL(5, 63, 6) // "height"

    },
    "SelectImageSegmentDialog\0onWidthChanged\0"
    "\0width\0onHeightChanged\0height"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SelectImageSegmentDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       4,    1,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void SelectImageSegmentDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SelectImageSegmentDialog *_t = static_cast<SelectImageSegmentDialog *>(_o);
        switch (_id) {
        case 0: _t->onWidthChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onHeightChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject SelectImageSegmentDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SelectImageSegmentDialog.data,
      qt_meta_data_SelectImageSegmentDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SelectImageSegmentDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SelectImageSegmentDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SelectImageSegmentDialog.stringdata))
        return static_cast<void*>(const_cast< SelectImageSegmentDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SelectImageSegmentDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
