/****************************************************************************
** Meta object code from reading C++ file 'KDChartAbstractDiagram.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../KDChart/KDChartAbstractDiagram.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KDChartAbstractDiagram.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KDChart__AbstractDiagram_t {
    QByteArrayData data[12];
    char stringdata[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDChart__AbstractDiagram_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDChart__AbstractDiagram_t qt_meta_stringdata_KDChart__AbstractDiagram = {
    {
QT_MOC_LITERAL(0, 0, 24), // "KDChart::AbstractDiagram"
QT_MOC_LITERAL(1, 25, 13), // "layoutChanged"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 16), // "AbstractDiagram*"
QT_MOC_LITERAL(4, 57, 18), // "aboutToBeDestroyed"
QT_MOC_LITERAL(5, 76, 13), // "modelsChanged"
QT_MOC_LITERAL(6, 90, 16), // "modelDataChanged"
QT_MOC_LITERAL(7, 107, 10), // "dataHidden"
QT_MOC_LITERAL(8, 118, 17), // "propertiesChanged"
QT_MOC_LITERAL(9, 136, 17), // "boundariesChanged"
QT_MOC_LITERAL(10, 154, 31), // "viewportCoordinateSystemChanged"
QT_MOC_LITERAL(11, 186, 22) // "setDataBoundariesDirty"

    },
    "KDChart::AbstractDiagram\0layoutChanged\0"
    "\0AbstractDiagram*\0aboutToBeDestroyed\0"
    "modelsChanged\0modelDataChanged\0"
    "dataHidden\0propertiesChanged\0"
    "boundariesChanged\0viewportCoordinateSystemChanged\0"
    "setDataBoundariesDirty"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDChart__AbstractDiagram[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    0,   62,    2, 0x06 /* Public */,
       5,    0,   63,    2, 0x06 /* Public */,
       6,    0,   64,    2, 0x06 /* Public */,
       7,    0,   65,    2, 0x06 /* Public */,
       8,    0,   66,    2, 0x06 /* Public */,
       9,    0,   67,    2, 0x06 /* Public */,
      10,    0,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   69,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void KDChart::AbstractDiagram::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AbstractDiagram *_t = static_cast<AbstractDiagram *>(_o);
        switch (_id) {
        case 0: _t->layoutChanged((*reinterpret_cast< AbstractDiagram*(*)>(_a[1]))); break;
        case 1: _t->aboutToBeDestroyed(); break;
        case 2: _t->modelsChanged(); break;
        case 3: _t->modelDataChanged(); break;
        case 4: _t->dataHidden(); break;
        case 5: _t->propertiesChanged(); break;
        case 6: _t->boundariesChanged(); break;
        case 7: _t->viewportCoordinateSystemChanged(); break;
        case 8: _t->setDataBoundariesDirty(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AbstractDiagram* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AbstractDiagram::*_t)(AbstractDiagram * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractDiagram::layoutChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (AbstractDiagram::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractDiagram::aboutToBeDestroyed)) {
                *result = 1;
            }
        }
        {
            typedef void (AbstractDiagram::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractDiagram::modelsChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (AbstractDiagram::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractDiagram::modelDataChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (AbstractDiagram::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractDiagram::dataHidden)) {
                *result = 4;
            }
        }
        {
            typedef void (AbstractDiagram::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractDiagram::propertiesChanged)) {
                *result = 5;
            }
        }
        {
            typedef void (AbstractDiagram::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractDiagram::boundariesChanged)) {
                *result = 6;
            }
        }
        {
            typedef void (AbstractDiagram::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AbstractDiagram::viewportCoordinateSystemChanged)) {
                *result = 7;
            }
        }
    }
}

const QMetaObject KDChart::AbstractDiagram::staticMetaObject = {
    { &QAbstractItemView::staticMetaObject, qt_meta_stringdata_KDChart__AbstractDiagram.data,
      qt_meta_data_KDChart__AbstractDiagram,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDChart::AbstractDiagram::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDChart::AbstractDiagram::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDChart__AbstractDiagram.stringdata))
        return static_cast<void*>(const_cast< AbstractDiagram*>(this));
    return QAbstractItemView::qt_metacast(_clname);
}

int KDChart::AbstractDiagram::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void KDChart::AbstractDiagram::layoutChanged(AbstractDiagram * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KDChart::AbstractDiagram::aboutToBeDestroyed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void KDChart::AbstractDiagram::modelsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void KDChart::AbstractDiagram::modelDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void KDChart::AbstractDiagram::dataHidden()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void KDChart::AbstractDiagram::propertiesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void KDChart::AbstractDiagram::boundariesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void KDChart::AbstractDiagram::viewportCoordinateSystemChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}
struct qt_meta_stringdata_KDChart__PrivateAttributesModel_t {
    QByteArrayData data[1];
    char stringdata[32];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KDChart__PrivateAttributesModel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KDChart__PrivateAttributesModel_t qt_meta_stringdata_KDChart__PrivateAttributesModel = {
    {
QT_MOC_LITERAL(0, 0, 31) // "KDChart::PrivateAttributesModel"

    },
    "KDChart::PrivateAttributesModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KDChart__PrivateAttributesModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void KDChart::PrivateAttributesModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject KDChart::PrivateAttributesModel::staticMetaObject = {
    { &AttributesModel::staticMetaObject, qt_meta_stringdata_KDChart__PrivateAttributesModel.data,
      qt_meta_data_KDChart__PrivateAttributesModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KDChart::PrivateAttributesModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KDChart::PrivateAttributesModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KDChart__PrivateAttributesModel.stringdata))
        return static_cast<void*>(const_cast< PrivateAttributesModel*>(this));
    return AttributesModel::qt_metacast(_clname);
}

int KDChart::PrivateAttributesModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AttributesModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
