/****************************************************************************
** Meta object code from reading C++ file 'downloadmodule.h'
**
** Created: Sun Jul 26 17:46:28 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "downloadmodule.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'downloadmodule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DownloadModule[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      26,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      66,   15,   15,   15, 0x0a,
      79,   15,   15,   15, 0x0a,
      94,   15,   15,   15, 0x09,
     107,   15,   15,   15, 0x09,
     119,   15,   15,   15, 0x09,
     132,   15,   15,   15, 0x09,
     144,   15,   15,   15, 0x09,
     157,   15,   15,   15, 0x09,
     174,   15,   15,   15, 0x09,
     185,   15,   15,   15, 0x09,
     196,   15,   15,   15, 0x09,
     220,   15,   15,   15, 0x09,
     250,  241,   15,   15, 0x09,
     285,   15,   15,   15, 0x09,
     304,   15,   15,   15, 0x09,
     323,   15,   15,   15, 0x09,
     350,  342,   15,   15, 0x09,
     371,   15,   15,   15, 0x09,
     392,   15,   15,   15, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_DownloadModule[] = {
    "DownloadModule\0\0downloads\0"
    "downloadsFinished(QList<DownloadItem*>)\0"
    "updateView()\0partListSlot()\0cancelSlot()\0"
    "cleanSlot()\0resumeSlot()\0pauseSlot()\0"
    "renameSlot()\0renamePlusSlot()\0openSlot()\0"
    "linkSlot()\0setMultiPowerDownload()\0"
    "applyPowerDownload()\0id,value\0"
    "applyPowerDownload(QString,double)\0"
    "maxPowerDownload()\0selectionChanged()\0"
    "storeDownloadFtp()\0checked\0"
    "hidePausedSlot(bool)\0partListWidgetSlot()\0"
    "targetFolder()\0"
};

const QMetaObject DownloadModule::staticMetaObject = {
    { &ModuleBase::staticMetaObject, qt_meta_stringdata_DownloadModule,
      qt_meta_data_DownloadModule, 0 }
};

const QMetaObject *DownloadModule::metaObject() const
{
    return &staticMetaObject;
}

void *DownloadModule::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DownloadModule))
        return static_cast<void*>(const_cast< DownloadModule*>(this));
    return ModuleBase::qt_metacast(_clname);
}

int DownloadModule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ModuleBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: downloadsFinished((*reinterpret_cast< const QList<DownloadItem*>(*)>(_a[1]))); break;
        case 1: updateView(); break;
        case 2: partListSlot(); break;
        case 3: cancelSlot(); break;
        case 4: cleanSlot(); break;
        case 5: resumeSlot(); break;
        case 6: pauseSlot(); break;
        case 7: renameSlot(); break;
        case 8: renamePlusSlot(); break;
        case 9: openSlot(); break;
        case 10: linkSlot(); break;
        case 11: setMultiPowerDownload(); break;
        case 12: applyPowerDownload(); break;
        case 13: applyPowerDownload((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 14: maxPowerDownload(); break;
        case 15: selectionChanged(); break;
        case 16: storeDownloadFtp(); break;
        case 17: hidePausedSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: partListWidgetSlot(); break;
        case 19: targetFolder(); break;
        default: ;
        }
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void DownloadModule::downloadsFinished(const QList<DownloadItem*> & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
