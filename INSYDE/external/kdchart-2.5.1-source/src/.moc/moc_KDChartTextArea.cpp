/****************************************************************************
** Meta object code from reading C++ file 'KDChartTextArea.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDChart/KDChartTextArea.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KDChartTextArea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDChart__TextArea_t {
    QByteArrayData data[4];
    char stringdata[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDChart__TextArea_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDChart__TextArea_t qt_meta_stringdata_KDChart__TextArea = {
    {
QT_MOC_LITERAL(0, 0, 17), // "KDChart::TextArea"
QT_MOC_LITERAL(1, 18, 15), // "positionChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 9) // "TextArea*"

    },
    "KDChart::TextArea\0positionChanged\0\0"
    "TextArea*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDChart__TextArea[] = {

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
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void KDChart::TextArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TextArea *_t = static_cast<TextArea *>(_o);
        switch (_id) {
        case 0: _t->positionChanged((*reinterpret_cast< TextArea*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< TextArea* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TextArea::*_t)(TextArea * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TextArea::positionChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject KDChart::TextArea::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KDChart__TextArea.data,
      qt_meta_data_KDChart__TextArea,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDChart::TextArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDChart::TextArea::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDChart__TextArea.stringdata))
        return static_cast<void*>(const_cast< TextArea*>(this));
    if (!strcmp(_clname, "AbstractAreaBase"))
        return static_cast< AbstractAreaBase*>(const_cast< TextArea*>(this));
    if (!strcmp(_clname, "TextLayoutItem"))
        return static_cast< TextLayoutItem*>(const_cast< TextArea*>(this));
    return QObject::qt_metacast(_clname);
}

int KDChart::TextArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void KDChart::TextArea::positionChanged(TextArea * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
