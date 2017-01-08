/****************************************************************************
** Meta object code from reading C++ file 'graphiccursorelement.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../INSYDE/core/graphiccursorelement.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphiccursorelement.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_core__Cursor_t {
    QByteArrayData data[4];
    char stringdata0[39];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_core__Cursor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_core__Cursor_t qt_meta_stringdata_core__Cursor = {
    {
QT_MOC_LITERAL(0, 0, 12), // "core::Cursor"
QT_MOC_LITERAL(1, 13, 21), // "cursorPositionChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 2) // "pt"

    },
    "core::Cursor\0cursorPositionChanged\0\0"
    "pt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_core__Cursor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    3,

       0        // eod
};

void core::Cursor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Cursor *_t = static_cast<Cursor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cursorPositionChanged((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Cursor::*_t)(QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cursor::cursorPositionChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject core::Cursor::staticMetaObject = {
    { &GraphicObject::staticMetaObject, qt_meta_stringdata_core__Cursor.data,
      qt_meta_data_core__Cursor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *core::Cursor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *core::Cursor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_core__Cursor.stringdata0))
        return static_cast<void*>(const_cast< Cursor*>(this));
    return GraphicObject::qt_metacast(_clname);
}

int core::Cursor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GraphicObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void core::Cursor::cursorPositionChanged(QPoint _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
