/****************************************************************************
** Meta object code from reading C++ file 'uploadmodule.h'
**
** Created: Sun Jul 26 17:09:49 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "uploadmodule.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uploadmodule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UploadModule[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      36,   13,   13,   13, 0x0a,
      63,   55,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_UploadModule[] = {
    "UploadModule\0\0adjustSizeOfColumns()\0"
    "selectionChanged()\0checked\0"
    "hideQueuedSlot(bool)\0"
};

const QMetaObject UploadModule::staticMetaObject = {
    { &ModuleBase::staticMetaObject, qt_meta_stringdata_UploadModule,
      qt_meta_data_UploadModule, 0 }
};

const QMetaObject *UploadModule::metaObject() const
{
    return &staticMetaObject;
}

void *UploadModule::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UploadModule))
        return static_cast<void*>(const_cast< UploadModule*>(this));
    return ModuleBase::qt_metacast(_clname);
}

int UploadModule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModuleBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: adjustSizeOfColumns(); break;
        case 1: selectionChanged(); break;
        case 2: hideQueuedSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
