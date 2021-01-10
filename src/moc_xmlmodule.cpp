/****************************************************************************
** Meta object code from reading C++ file 'xmlmodule.h'
**
** Created: Sun Jul 26 17:46:29 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "xmlmodule.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xmlmodule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_XMLModule[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      20,   11,   10,   10, 0x05,
      54,   46,   10,   10, 0x05,
      69,   10,   10,   10, 0x05,
      82,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     102,   97,   10,   10, 0x08,
     155,  146,   10,   10, 0x08,
     181,   10,   10,   10, 0x08,
     200,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_XMLModule[] = {
    "XMLModule\0\0settings\0settingsReady(AjSettings)\0"
    "message\0error(QString)\0gotSession()\0"
    "modifiedDone()\0resp\0"
    "responseHeaderReceived(QHttpResponseHeader)\0"
    "id,error\0requestFinished(int,bool)\0"
    "networkErrorSlot()\0httpErrorSlot()\0"
};

const QMetaObject XMLModule::staticMetaObject = {
    { &QHttp::staticMetaObject, qt_meta_stringdata_XMLModule,
      qt_meta_data_XMLModule, 0 }
};

const QMetaObject *XMLModule::metaObject() const
{
    return &staticMetaObject;
}

void *XMLModule::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_XMLModule))
        return static_cast<void*>(const_cast< XMLModule*>(this));
    return QHttp::qt_metacast(_clname);
}

int XMLModule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QHttp::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: settingsReady((*reinterpret_cast< const AjSettings(*)>(_a[1]))); break;
        case 1: error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: gotSession(); break;
        case 3: modifiedDone(); break;
        case 4: responseHeaderReceived((*reinterpret_cast< const QHttpResponseHeader(*)>(_a[1]))); break;
        case 5: requestFinished((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: networkErrorSlot(); break;
        case 7: httpErrorSlot(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void XMLModule::settingsReady(const AjSettings & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void XMLModule::error(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void XMLModule::gotSession()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void XMLModule::modifiedDone()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
