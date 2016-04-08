/****************************************************************************
** Meta object code from reading C++ file 'ovrmapcanvas.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/ovrmapcanvas.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ovrmapcanvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OvrMapCanvas[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   14,   13,   13, 0x0a,
      69,   13,   13,   13, 0x0a,
      89,   13,   13,   13, 0x0a,
     108,   13,   13,   13, 0x0a,
     131,  127,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_OvrMapCanvas[] = {
    "OvrMapCanvas\0\0point,button\0"
    "doCanvasClicked(QgsPoint,Qt::MouseButton)\0"
    "doSelectFirstTile()\0doSelectNextTile()\0"
    "doSelectPrevTile()\0num\0doSelectTile(int)\0"
};

void OvrMapCanvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OvrMapCanvas *_t = static_cast<OvrMapCanvas *>(_o);
        switch (_id) {
        case 0: _t->doCanvasClicked((*reinterpret_cast< const QgsPoint(*)>(_a[1])),(*reinterpret_cast< Qt::MouseButton(*)>(_a[2]))); break;
        case 1: _t->doSelectFirstTile(); break;
        case 2: _t->doSelectNextTile(); break;
        case 3: _t->doSelectPrevTile(); break;
        case 4: _t->doSelectTile((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData OvrMapCanvas::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OvrMapCanvas::staticMetaObject = {
    { &QgsMapCanvas::staticMetaObject, qt_meta_stringdata_OvrMapCanvas,
      qt_meta_data_OvrMapCanvas, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OvrMapCanvas::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OvrMapCanvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OvrMapCanvas::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OvrMapCanvas))
        return static_cast<void*>(const_cast< OvrMapCanvas*>(this));
    return QgsMapCanvas::qt_metacast(_clname);
}

int OvrMapCanvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QgsMapCanvas::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
