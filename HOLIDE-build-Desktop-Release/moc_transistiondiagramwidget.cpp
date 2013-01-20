/****************************************************************************
** Meta object code from reading C++ file 'transistiondiagramwidget.h'
**
** Created: Fri Jan 4 19:48:06 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HOLIDE/transistiondiagramwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'transistiondiagramwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TransistionDiagramWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   25,   25,   25, 0x0a,
      42,   37,   25,   25, 0x0a,
      60,   25,   25,   25, 0x0a,
      83,   77,   25,   25, 0x0a,
     119,  114,   25,   25, 0x0a,
     137,   25,   25,   25, 0x0a,
     147,   25,   25,   25, 0x0a,
     158,   25,   25,   25, 0x0a,
     176,   25,   25,   25, 0x0a,
     189,   25,   25,   25, 0x0a,
     198,   25,   25,   25, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TransistionDiagramWidget[] = {
    "TransistionDiagramWidget\0\0addState()\0"
    "name\0addState(QString)\0removeSelected()\0"
    "state\0removeState(TransistionState*)\0"
    "link\0removeLink(Link*)\0addLink()\0"
    "drawDots()\0updatePositions()\0saveStates()\0"
    "zoomIn()\0zoomOut()\0"
};

void TransistionDiagramWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TransistionDiagramWidget *_t = static_cast<TransistionDiagramWidget *>(_o);
        switch (_id) {
        case 0: _t->addState(); break;
        case 1: _t->addState((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->removeSelected(); break;
        case 3: _t->removeState((*reinterpret_cast< TransistionState*(*)>(_a[1]))); break;
        case 4: _t->removeLink((*reinterpret_cast< Link*(*)>(_a[1]))); break;
        case 5: _t->addLink(); break;
        case 6: _t->drawDots(); break;
        case 7: _t->updatePositions(); break;
        case 8: _t->saveStates(); break;
        case 9: _t->zoomIn(); break;
        case 10: _t->zoomOut(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TransistionDiagramWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TransistionDiagramWidget::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_TransistionDiagramWidget,
      qt_meta_data_TransistionDiagramWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TransistionDiagramWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TransistionDiagramWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TransistionDiagramWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TransistionDiagramWidget))
        return static_cast<void*>(const_cast< TransistionDiagramWidget*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int TransistionDiagramWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
