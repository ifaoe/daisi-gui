/****************************************************************************
** Meta object code from reading C++ file 'ImgCanvas.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/ImgCanvas.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImgCanvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImgCanvas[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      55,   49,   10,   10, 0x08,
      85,   10,   10,   10, 0x08,
     111,   10,   10,   10, 0x08,
     126,   10,   10,   10, 0x08,
     142,   10,   10,   10, 0x08,
     172,  165,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ImgCanvas[] = {
    "ImgCanvas\0\0type,size\0measurementDone(int,double)\0"
    "point\0handleCanvasClicked(QgsPoint)\0"
    "handleHideObjectMarkers()\0HandleZoomIn()\0"
    "HandleZoomOut()\0HandleZoomFullExtent()\0"
    "button\0endMeasurement(QAbstractButton*)\0"
};

void ImgCanvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ImgCanvas *_t = static_cast<ImgCanvas *>(_o);
        switch (_id) {
        case 0: _t->measurementDone((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->handleCanvasClicked((*reinterpret_cast< const QgsPoint(*)>(_a[1]))); break;
        case 2: _t->handleHideObjectMarkers(); break;
        case 3: _t->HandleZoomIn(); break;
        case 4: _t->HandleZoomOut(); break;
        case 5: _t->HandleZoomFullExtent(); break;
        case 6: _t->endMeasurement((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ImgCanvas::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ImgCanvas::staticMetaObject = {
    { &QgsMapCanvas::staticMetaObject, qt_meta_stringdata_ImgCanvas,
      qt_meta_data_ImgCanvas, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImgCanvas::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImgCanvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImgCanvas::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImgCanvas))
        return static_cast<void*>(const_cast< ImgCanvas*>(this));
    return QgsMapCanvas::qt_metacast(_clname);
}

int ImgCanvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QgsMapCanvas::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ImgCanvas::measurementDone(int _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
