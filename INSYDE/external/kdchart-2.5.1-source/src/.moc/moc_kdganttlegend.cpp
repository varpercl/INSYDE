/****************************************************************************
** Meta object code from reading C++ file 'kdganttlegend.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDGantt/kdganttlegend.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kdganttlegend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDGantt__Legend_t {
    QByteArrayData data[3];
    char stringdata[34];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDGantt__Legend_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDGantt__Legend_t qt_meta_stringdata_KDGantt__Legend = {
    {
QT_MOC_LITERAL(0, 0, 15), // "KDGantt::Legend"
QT_MOC_LITERAL(1, 16, 16), // "modelDataChanged"
QT_MOC_LITERAL(2, 33, 0) // ""

    },
    "KDGantt::Legend\0modelDataChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDGantt__Legend[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void KDGantt::Legend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Legend *_t = static_cast<Legend *>(_o);
        switch (_id) {
        case 0: _t->modelDataChanged(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject KDGantt::Legend::staticMetaObject = {
    { &QAbstractItemView::staticMetaObject, qt_meta_stringdata_KDGantt__Legend.data,
      qt_meta_data_KDGantt__Legend,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDGantt::Legend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDGantt::Legend::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDGantt__Legend.stringdata))
        return static_cast<void*>(const_cast< Legend*>(this));
    return QAbstractItemView::qt_metacast(_clname);
}

int KDGantt::Legend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
