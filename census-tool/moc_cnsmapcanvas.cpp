/****************************************************************************
** Meta object code from reading C++ file 'cnsmapcanvas.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/cnsmapcanvas.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cnsmapcanvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CnsMapCanvas[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      29,   13,   13,   13, 0x0a,
      56,   47,   42,   13, 0x0a,
      91,   13,   13,   13, 0x0a,
     103,   13,   13,   13, 0x0a,
     120,   13,   13,   13, 0x0a,
     148,  135,   13,   13, 0x0a,
     196,  190,   42,   13, 0x0a,
     230,  221,   13,   13, 0x0a,
     261,  221,   13,   13, 0x0a,
     293,   13,   13,   13, 0x0a,
     315,  310,   13,   13, 0x0a,
     332,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CnsMapCanvas[] = {
    "CnsMapCanvas\0\0doZoomExtent()\0doZoom1by1()\0"
    "bool\0cam,file\0doOpenRasterLayer(QString,QString)\0"
    "doModePan()\0doModeDigitize()\0"
    "doModeSelect()\0point,button\0"
    "doCanvasClicked(QgsPoint,Qt::MouseButton)\0"
    "point\0doHandleCoords(QgsPoint)\0keyEvent\0"
    "doHandleKeyPressed(QKeyEvent*)\0"
    "doHandleKeyReleased(QKeyEvent*)\0"
    "doUpdateStatus()\0hide\0hideMarker(bool)\0"
    "closeCanvas()\0"
};

void CnsMapCanvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CnsMapCanvas *_t = static_cast<CnsMapCanvas *>(_o);
        switch (_id) {
        case 0: _t->doZoomExtent(); break;
        case 1: _t->doZoom1by1(); break;
        case 2: { bool _r = _t->doOpenRasterLayer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->doModePan(); break;
        case 4: _t->doModeDigitize(); break;
        case 5: _t->doModeSelect(); break;
        case 6: _t->doCanvasClicked((*reinterpret_cast< const QgsPoint(*)>(_a[1])),(*reinterpret_cast< Qt::MouseButton(*)>(_a[2]))); break;
        case 7: { bool _r = _t->doHandleCoords((*reinterpret_cast< const QgsPoint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: _t->doHandleKeyPressed((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 9: _t->doHandleKeyReleased((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 10: _t->doUpdateStatus(); break;
        case 11: _t->hideMarker((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->closeCanvas(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CnsMapCanvas::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CnsMapCanvas::staticMetaObject = {
    { &QgsMapCanvas::staticMetaObject, qt_meta_stringdata_CnsMapCanvas,
      qt_meta_data_CnsMapCanvas, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CnsMapCanvas::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CnsMapCanvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CnsMapCanvas::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CnsMapCanvas))
        return static_cast<void*>(const_cast< CnsMapCanvas*>(this));
    return QgsMapCanvas::qt_metacast(_clname);
}

int CnsMapCanvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QgsMapCanvas::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
