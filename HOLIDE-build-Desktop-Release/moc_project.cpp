/****************************************************************************
** Meta object code from reading C++ file 'project.h'
**
** Created: Mon Jan 7 17:59:32 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HOLIDE/project.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'project.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Project[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      36,   27,    8,    8, 0x0a,
      62,   57,    8,    8, 0x0a,
      98,   86,    8,    8, 0x0a,
     141,  133,    8,    8, 0x0a,
     173,  165,    8,    8, 0x0a,
     208,  197,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Project[] = {
    "Project\0\0saveProjectFile()\0fileName\0"
    "openProject(QString)\0name\0"
    "setProjectName(QString)\0description\0"
    "setProjectDescription(QStringList)\0"
    "authors\0setAuthors(QStringList)\0actions\0"
    "setActions(QStringList)\0principals\0"
    "setPrincipals(QStringList)\0"
};

void Project::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Project *_t = static_cast<Project *>(_o);
        switch (_id) {
        case 0: _t->saveProjectFile(); break;
        case 1: _t->openProject((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setProjectName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->setProjectDescription((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 4: _t->setAuthors((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 5: _t->setActions((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 6: _t->setPrincipals((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Project::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Project::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Project,
      qt_meta_data_Project, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Project::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Project::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Project::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Project))
        return static_cast<void*>(const_cast< Project*>(this));
    return QObject::qt_metacast(_clname);
}

int Project::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
