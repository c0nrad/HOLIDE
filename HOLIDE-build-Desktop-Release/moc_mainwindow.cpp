/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon Jan 7 17:59:32 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HOLIDE/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      38,   33,   27,   11, 0x08,
      55,   11,   11,   11, 0x08,
      66,   11,   11,   11, 0x08,
      76,   11,   11,   11, 0x08,
      89,   11,   11,   11, 0x08,
      97,   11,   11,   11, 0x08,
     104,   11,   11,   11, 0x08,
     111,   11,   11,   11, 0x08,
     117,   11,   11,   11, 0x08,
     124,   11,   11,   11, 0x08,
     132,   11,   11,   11, 0x08,
     144,   11,   11,   11, 0x08,
     164,  158,   11,   11, 0x08,
     195,  178,   11,   11, 0x08,
     241,   11,   11,   11, 0x08,
     254,   11,   11,   11, 0x08,
     267,   11,   11,   11, 0x08,
     281,   11,   11,   11, 0x08,
     295,   11,   11,   11, 0x08,
     311,   11,   11,   11, 0x08,
     336,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0newBlankPage()\0Page*\0name\0"
    "addPage(QString)\0openPage()\0saveTab()\0"
    "savePageAs()\0close()\0undo()\0redo()\0"
    "cut()\0copy()\0paste()\0selectAll()\0"
    "findReplace()\0index\0closeTab(int)\0"
    "current,previous\0"
    "fileViewItemSelected(QModelIndex,QModelIndex)\0"
    "runHolmake()\0newProject()\0openProject()\0"
    "saveProject()\0saveProjectAs()\0"
    "showTransistionDiagram()\0showProjectView()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->newBlankPage(); break;
        case 1: { Page* _r = _t->addPage((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Page**>(_a[0]) = _r; }  break;
        case 2: _t->openPage(); break;
        case 3: _t->saveTab(); break;
        case 4: _t->savePageAs(); break;
        case 5: _t->close(); break;
        case 6: _t->undo(); break;
        case 7: _t->redo(); break;
        case 8: _t->cut(); break;
        case 9: _t->copy(); break;
        case 10: _t->paste(); break;
        case 11: _t->selectAll(); break;
        case 12: _t->findReplace(); break;
        case 13: _t->closeTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->fileViewItemSelected((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 15: _t->runHolmake(); break;
        case 16: _t->newProject(); break;
        case 17: _t->openProject(); break;
        case 18: _t->saveProject(); break;
        case 19: _t->saveProjectAs(); break;
        case 20: _t->showTransistionDiagram(); break;
        case 21: _t->showProjectView(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
