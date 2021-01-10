/****************************************************************************
** Meta object code from reading C++ file 'application.h'
**
** Created: Sun Jul 26 18:02:45 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "application.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'application.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Application[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      27,   21,   12,   12, 0x0a,
      49,   12,   12,   12, 0x2a,

       0        // eod
};

static const char qt_meta_stringdata_Application[] = {
    "Application\0\0start()\0force\0"
    "setAjfspHandler(bool)\0setAjfspHandler()\0"
};

const QMetaObject Application::staticMetaObject = {
    { &QApplication::staticMetaObject, qt_meta_stringdata_Application,
      qt_meta_data_Application, 0 }
};

const QMetaObject *Application::metaObject() const
{
    return &staticMetaObject;
}

void *Application::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Application))
        return static_cast<void*>(const_cast< Application*>(this));
    return QApplication::qt_metacast(_clname);
}

int Application::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QApplication::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: start(); break;
        case 1: setAjfspHandler((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: setAjfspHandler(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
