/****************************************************************************
** Meta object code from reading C++ file 'statusanimation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../statusanimation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'statusanimation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StatusAnimationControl_t {
    QByteArrayData data[11];
    char stringdata[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StatusAnimationControl_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StatusAnimationControl_t qt_meta_stringdata_StatusAnimationControl = {
    {
QT_MOC_LITERAL(0, 0, 22), // "StatusAnimationControl"
QT_MOC_LITERAL(1, 23, 5), // "pause"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 3), // "run"
QT_MOC_LITERAL(4, 34, 4), // "stop"
QT_MOC_LITERAL(5, 39, 13), // "statusChanged"
QT_MOC_LITERAL(6, 53, 6), // "Status"
QT_MOC_LITERAL(7, 60, 7), // "current"
QT_MOC_LITERAL(8, 68, 6), // "before"
QT_MOC_LITERAL(9, 75, 14), // "playPauseClick"
QT_MOC_LITERAL(10, 90, 9) // "stopClick"

    },
    "StatusAnimationControl\0pause\0\0run\0"
    "stop\0statusChanged\0Status\0current\0"
    "before\0playPauseClick\0stopClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StatusAnimationControl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    2,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   52,    2, 0x09 /* Protected */,
      10,    0,   53,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 6,    7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void StatusAnimationControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StatusAnimationControl *_t = static_cast<StatusAnimationControl *>(_o);
        switch (_id) {
        case 0: _t->pause(); break;
        case 1: _t->run(); break;
        case 2: _t->stop(); break;
        case 3: _t->statusChanged((*reinterpret_cast< Status(*)>(_a[1])),(*reinterpret_cast< Status(*)>(_a[2]))); break;
        case 4: _t->playPauseClick(); break;
        case 5: _t->stopClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (StatusAnimationControl::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StatusAnimationControl::pause)) {
                *result = 0;
            }
        }
        {
            typedef void (StatusAnimationControl::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StatusAnimationControl::run)) {
                *result = 1;
            }
        }
        {
            typedef void (StatusAnimationControl::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StatusAnimationControl::stop)) {
                *result = 2;
            }
        }
        {
            typedef void (StatusAnimationControl::*_t)(Status , Status );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StatusAnimationControl::statusChanged)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject StatusAnimationControl::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_StatusAnimationControl.data,
      qt_meta_data_StatusAnimationControl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StatusAnimationControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StatusAnimationControl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StatusAnimationControl.stringdata))
        return static_cast<void*>(const_cast< StatusAnimationControl*>(this));
    return QFrame::qt_metacast(_clname);
}

int StatusAnimationControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void StatusAnimationControl::pause()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void StatusAnimationControl::run()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void StatusAnimationControl::stop()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void StatusAnimationControl::statusChanged(Status _t1, Status _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
