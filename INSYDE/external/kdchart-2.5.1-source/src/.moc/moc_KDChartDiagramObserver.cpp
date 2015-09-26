/****************************************************************************
** Meta object code from reading C++ file 'KDChartDiagramObserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDChart/KDChartDiagramObserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KDChartDiagramObserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDChart__DiagramObserver_t {
    QByteArrayData data[17];
    char stringdata[302];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDChart__DiagramObserver_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDChart__DiagramObserver_t qt_meta_stringdata_KDChart__DiagramObserver = {
    {
QT_MOC_LITERAL(0, 0, 24), // "KDChart::DiagramObserver"
QT_MOC_LITERAL(1, 25, 16), // "diagramDestroyed"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 16), // "AbstractDiagram*"
QT_MOC_LITERAL(4, 60, 7), // "diagram"
QT_MOC_LITERAL(5, 68, 25), // "diagramAboutToBeDestroyed"
QT_MOC_LITERAL(6, 94, 18), // "diagramDataChanged"
QT_MOC_LITERAL(7, 113, 17), // "diagramDataHidden"
QT_MOC_LITERAL(8, 131, 24), // "diagramAttributesChanged"
QT_MOC_LITERAL(9, 156, 13), // "slotDestroyed"
QT_MOC_LITERAL(10, 170, 22), // "slotAboutToBeDestroyed"
QT_MOC_LITERAL(11, 193, 21), // "slotHeaderDataChanged"
QT_MOC_LITERAL(12, 215, 15), // "Qt::Orientation"
QT_MOC_LITERAL(13, 231, 15), // "slotDataChanged"
QT_MOC_LITERAL(14, 247, 14), // "slotDataHidden"
QT_MOC_LITERAL(15, 262, 21), // "slotAttributesChanged"
QT_MOC_LITERAL(16, 284, 17) // "slotModelsChanged"

    },
    "KDChart::DiagramObserver\0diagramDestroyed\0"
    "\0AbstractDiagram*\0diagram\0"
    "diagramAboutToBeDestroyed\0diagramDataChanged\0"
    "diagramDataHidden\0diagramAttributesChanged\0"
    "slotDestroyed\0slotAboutToBeDestroyed\0"
    "slotHeaderDataChanged\0Qt::Orientation\0"
    "slotDataChanged\0slotDataHidden\0"
    "slotAttributesChanged\0slotModelsChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDChart__DiagramObserver[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       5,    1,   87,    2, 0x06 /* Public */,
       6,    1,   90,    2, 0x06 /* Public */,
       7,    1,   93,    2, 0x06 /* Public */,
       8,    1,   96,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   99,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    3,  103,    2, 0x08 /* Private */,
      13,    2,  110,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      15,    2,  118,    2, 0x08 /* Private */,
      16,    0,  123,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QObjectStar,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex, QMetaType::QModelIndex,    2,    2,
    QMetaType::Void,

       0        // eod
};

void KDChart::DiagramObserver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DiagramObserver *_t = static_cast<DiagramObserver *>(_o);
        switch (_id) {
        case 0: _t->diagramDestroyed((*reinterpret_cast< AbstractDiagram*(*)>(_a[1]))); break;
        case 1: _t->diagramAboutToBeDestroyed((*reinterpret_cast< AbstractDiagram*(*)>(_a[1]))); break;
        case 2: _t->diagramDataChanged((*reinterpret_cast< AbstractDiagram*(*)>(_a[1]))); break;
        case 3: _t->diagramDataHidden((*reinterpret_cast< AbstractDiagram*(*)>(_a[1]))); break;
        case 4: _t->diagramAttributesChanged((*reinterpret_cast< AbstractDiagram*(*)>(_a[1]))); break;
        case 5: _t->slotDestroyed((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 6: _t->slotAboutToBeDestroyed(); break;
        case 7: _t->slotHeaderDataChanged((*reinterpret_cast< Qt::Orientation(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->slotDataChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 9: _t->slotDataChanged(); break;
        case 10: _t->slotDataHidden(); break;
        case 11: _t->slotAttributesChanged(); break;
        case 12: _t->slotAttributesChanged((*reinterpret_cast< QModelIndex(*)>(_a[1])),(*reinterpret_cast< QModelIndex(*)>(_a[2]))); break;
        case 13: _t->slotModelsChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DiagramObserver::*_t)(AbstractDiagram * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DiagramObserver::diagramDestroyed)) {
                *result = 0;
            }
        }
        {
            typedef void (DiagramObserver::*_t)(AbstractDiagram * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DiagramObserver::diagramAboutToBeDestroyed)) {
                *result = 1;
            }
        }
        {
            typedef void (DiagramObserver::*_t)(AbstractDiagram * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DiagramObserver::diagramDataChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (DiagramObserver::*_t)(AbstractDiagram * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DiagramObserver::diagramDataHidden)) {
                *result = 3;
            }
        }
        {
            typedef void (DiagramObserver::*_t)(AbstractDiagram * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DiagramObserver::diagramAttributesChanged)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject KDChart::DiagramObserver::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_KDChart__DiagramObserver.data,
      qt_meta_data_KDChart__DiagramObserver,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDChart::DiagramObserver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDChart::DiagramObserver::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDChart__DiagramObserver.stringdata))
        return static_cast<void*>(const_cast< DiagramObserver*>(this));
    return QObject::qt_metacast(_clname);
}

int KDChart::DiagramObserver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void KDChart::DiagramObserver::diagramDestroyed(AbstractDiagram * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KDChart::DiagramObserver::diagramAboutToBeDestroyed(AbstractDiagram * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KDChart::DiagramObserver::diagramDataChanged(AbstractDiagram * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void KDChart::DiagramObserver::diagramDataHidden(AbstractDiagram * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void KDChart::DiagramObserver::diagramAttributesChanged(AbstractDiagram * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
