/****************************************************************************
** Meta object code from reading C++ file 'QSearchDialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "QSearchDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QSearchDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QSearchDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      26,   14,   14,   14, 0x08,
      42,   37,   14,   14, 0x08,
      71,   66,   14,   14, 0x08,
     113,  105,   14,   14, 0x08,
     136,  105,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QSearchDialog[] = {
    "QSearchDialog\0\0onAccept()\0onReject()\0"
    "text\0onFilterChange(QString)\0item\0"
    "onItemSelection(QListWidgetItem*)\0"
    "checked\0handleSortAscend(bool)\0"
    "handleSortDescend(bool)\0"
};

void QSearchDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QSearchDialog *_t = static_cast<QSearchDialog *>(_o);
        switch (_id) {
        case 0: _t->onAccept(); break;
        case 1: _t->onReject(); break;
        case 2: _t->onFilterChange((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onItemSelection((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->handleSortAscend((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->handleSortDescend((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QSearchDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QSearchDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QSearchDialog,
      qt_meta_data_QSearchDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QSearchDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QSearchDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QSearchDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QSearchDialog))
        return static_cast<void*>(const_cast< QSearchDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int QSearchDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
