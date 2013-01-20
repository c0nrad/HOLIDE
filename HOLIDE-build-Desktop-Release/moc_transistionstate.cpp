/****************************************************************************
** Meta object code from reading C++ file 'transistionstate.h'
**
** Created: Fri Jan 4 19:48:59 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HOLIDE/transistionstate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'transistionstate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TransistionState[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      32,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   17,   17,   17, 0x0a,
      52,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TransistionState[] = {
    "TransistionState\0\0doubleClick()\0"
    "pieceMoved()\0save()\0read()\0"
};

void TransistionState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TransistionState *_t = static_cast<TransistionState *>(_o);
        switch (_id) {
        case 0: _t->doubleClick(); break;
        case 1: _t->pieceMoved(); break;
        case 2: _t->save(); break;
        case 3: _t->read(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData TransistionState::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TransistionState::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TransistionState,
      qt_meta_data_TransistionState, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TransistionState::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TransistionState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TransistionState::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TransistionState))
        return static_cast<void*>(const_cast< TransistionState*>(this));
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(const_cast< TransistionState*>(this));
    return QObject::qt_metacast(_clname);
}

int TransistionState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void TransistionState::doubleClick()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void TransistionState::pieceMoved()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
