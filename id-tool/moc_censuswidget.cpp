/****************************************************************************
** Meta object code from reading C++ file 'censuswidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/censuswidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'censuswidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CensusWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      34,   28,   13,   13, 0x05,
      56,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      69,   13,   13,   13, 0x0a,
      85,   13,   13,   13, 0x0a,
      98,   13,   13,   13, 0x0a,
     112,   13,   13,   13, 0x0a,
     135,   13,   13,   13, 0x0a,
     156,   13,   13,   13, 0x0a,
     174,   13,   13,   13, 0x0a,
     203,   13,   13,   13, 0x0a,
     216,   13,   13,   13, 0x0a,
     238,  231,   13,   13, 0x0a,
     269,  262,   13,   13, 0x0a,
     299,  293,   13,   13, 0x0a,
     322,   13,   13,   13, 0x08,
     342,   13,   13,   13, 0x08,
     371,  361,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CensusWidget[] = {
    "CensusWidget\0\0dataChanged()\0angle\0"
    "directionChanged(int)\0nextObject()\0"
    "userSelection()\0userSwitch()\0userDefault()\0"
    "associationSelection()\0behaviourSelection()\0"
    "familySelection()\0chooseActiveCensusElements()\0"
    "saveObject()\0deleteObject()\0object\0"
    "loadObjectData(census*)\0length\0"
    "setObjectLength(double)\0width\0"
    "setObjectWidth(double)\0passMeasureLength()\0"
    "passMeasureWidth()\0type,size\0"
    "receiveMeasurement(int,double)\0"
};

void CensusWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CensusWidget *_t = static_cast<CensusWidget *>(_o);
        switch (_id) {
        case 0: _t->dataChanged(); break;
        case 1: _t->directionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->nextObject(); break;
        case 3: _t->userSelection(); break;
        case 4: _t->userSwitch(); break;
        case 5: _t->userDefault(); break;
        case 6: _t->associationSelection(); break;
        case 7: _t->behaviourSelection(); break;
        case 8: _t->familySelection(); break;
        case 9: _t->chooseActiveCensusElements(); break;
        case 10: _t->saveObject(); break;
        case 11: _t->deleteObject(); break;
        case 12: _t->loadObjectData((*reinterpret_cast< census*(*)>(_a[1]))); break;
        case 13: _t->setObjectLength((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: _t->setObjectWidth((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->passMeasureLength(); break;
        case 16: _t->passMeasureWidth(); break;
        case 17: _t->receiveMeasurement((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CensusWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CensusWidget::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_CensusWidget,
      qt_meta_data_CensusWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CensusWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CensusWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CensusWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CensusWidget))
        return static_cast<void*>(const_cast< CensusWidget*>(this));
    return QFrame::qt_metacast(_clname);
}

int CensusWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void CensusWidget::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CensusWidget::directionChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CensusWidget::nextObject()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
