/****************************************************************************
** Meta object code from reading C++ file 'ftp.h'
**
** Created: Sun Jul 26 17:46:27 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ftp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ftp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FTP[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x05,
      20,   12,    4,    4, 0x05,
      51,   42,    4,    4, 0x05,
      93,   81,    4,    4, 0x05,

 // slots: signature, parameters, type, tag, flags
     122,  116,    4,    4, 0x08,
     153,  144,    4,    4, 0x08,
     194,  183,    4,    4, 0x0a,
     234,    4,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FTP[] = {
    "FTP\0\0done()\0message\0errorOccured(QString)\0"
    "file,ftp\0downloadFinished(QFile*,FTP*)\0"
    "dstFile,ftp\0readyRead(QFile*,FTP*)\0"
    "state\0stateChangedSlot(int)\0id,error\0"
    "commandFinishedSlot(int,bool)\0done,total\0"
    "dataTransferProgressSlot(qint64,qint64)\0"
    "abort()\0"
};

const QMetaObject FTP::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_FTP,
      qt_meta_data_FTP, 0 }
};

const QMetaObject *FTP::metaObject() const
{
    return &staticMetaObject;
}

void *FTP::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FTP))
        return static_cast<void*>(const_cast< FTP*>(this));
    return QThread::qt_metacast(_clname);
}

int FTP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: done(); break;
        case 1: errorOccured((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: downloadFinished((*reinterpret_cast< QFile*(*)>(_a[1])),(*reinterpret_cast< FTP*(*)>(_a[2]))); break;
        case 3: readyRead((*reinterpret_cast< QFile*(*)>(_a[1])),(*reinterpret_cast< FTP*(*)>(_a[2]))); break;
        case 4: stateChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: commandFinishedSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: dataTransferProgressSlot((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 7: abort(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void FTP::done()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void FTP::errorOccured(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FTP::downloadFinished(QFile * _t1, FTP * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FTP::readyRead(QFile * _t1, FTP * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
