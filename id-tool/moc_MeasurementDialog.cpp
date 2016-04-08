/****************************************************************************
** Meta object code from reading C++ file 'MeasurementDialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/MeasurementDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MeasurementDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MeasurementDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      39,   18,   18,   18, 0x08,
      54,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MeasurementDialog[] = {
    "MeasurementDialog\0\0acceptMeasurement()\0"
    "handleAccept()\0handleReject()\0"
};

void MeasurementDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MeasurementDialog *_t = static_cast<MeasurementDialog *>(_o);
        switch (_id) {
        case 0: _t->acceptMeasurement(); break;
        case 1: _t->handleAccept(); break;
        case 2: _t->handleReject(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MeasurementDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MeasurementDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MeasurementDialog,
      qt_meta_data_MeasurementDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MeasurementDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MeasurementDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MeasurementDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MeasurementDialog))
        return static_cast<void*>(const_cast< MeasurementDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int MeasurementDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MeasurementDialog::acceptMeasurement()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
