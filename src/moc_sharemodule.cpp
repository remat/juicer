/****************************************************************************
** Meta object code from reading C++ file 'sharemodule.h'
**
** Created: Sun Jul 26 17:46:29 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sharemodule.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sharemodule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ShareModule[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      26,   12,   12,   12, 0x0a,
      45,   12,   12,   12, 0x0a,
      58,   12,   12,   12, 0x08,
      71,   12,   12,   12, 0x08,
      84,   12,   12,   12, 0x08,
     100,   95,   12,   12, 0x08,
     120,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ShareModule[] = {
    "ShareModule\0\0commitSlot()\0selectionChanged()\0"
    "reloadSlot()\0insertSlot()\0removeSlot()\0"
    "linkSlot()\0prio\0setTmpPriority(int)\0"
    "setPriority()\0"
};

const QMetaObject ShareModule::staticMetaObject = {
    { &ModuleBase::staticMetaObject, qt_meta_stringdata_ShareModule,
      qt_meta_data_ShareModule, 0 }
};

const QMetaObject *ShareModule::metaObject() const
{
    return &staticMetaObject;
}

void *ShareModule::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ShareModule))
        return static_cast<void*>(const_cast< ShareModule*>(this));
    return ModuleBase::qt_metacast(_clname);
}

int ShareModule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModuleBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: commitSlot(); break;
        case 1: selectionChanged(); break;
        case 2: reloadSlot(); break;
        case 3: insertSlot(); break;
        case 4: removeSlot(); break;
        case 5: linkSlot(); break;
        case 6: setTmpPriority((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: setPriority(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
