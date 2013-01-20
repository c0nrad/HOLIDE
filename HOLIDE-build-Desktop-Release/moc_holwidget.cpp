/****************************************************************************
** Meta object code from reading C++ file 'holwidget.h'
**
** Created: Fri Jan 4 19:48:03 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HOLIDE/holwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'holwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HOLWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      31,   10,   10,   10, 0x0a,
      60,   49,   10,   10, 0x0a,
      74,   10,   10,   10, 0x0a,
      84,   10,   10,   10, 0x0a,
      96,   10,   10,   10, 0x0a,
     115,   10,   10,   10, 0x0a,
     133,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_HOLWidget[] = {
    "HOLWidget\0\0readStandardError()\0"
    "readStandardOut()\0exitStatus\0finished(int)\0"
    "restart()\0showTypes()\0showTypesVerbose()\0"
    "showAssumptions()\0showNumericalTypes()\0"
};

void HOLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HOLWidget *_t = static_cast<HOLWidget *>(_o);
        switch (_id) {
        case 0: _t->readStandardError(); break;
        case 1: _t->readStandardOut(); break;
        case 2: _t->finished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->restart(); break;
        case 4: _t->showTypes(); break;
        case 5: _t->showTypesVerbose(); break;
        case 6: _t->showAssumptions(); break;
        case 7: _t->showNumericalTypes(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData HOLWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HOLWidget::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_HOLWidget,
      qt_meta_data_HOLWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HOLWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HOLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HOLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HOLWidget))
        return static_cast<void*>(const_cast< HOLWidget*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int HOLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
