#-------------------------------------------------
#
# Project created by QtCreator 2014-01-28T13:34:45
#
#-------------------------------------------------

QT       += core gui sql xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = daisi-census-tool
TEMPLATE = app

SOURCES += main.cpp\
    mainwindow.cpp \
    cnsmapcanvas.cpp \
    db.cpp \
    ovrmapcanvas.cpp \
    QgsMapMarker.cpp \
    ConfigHandler.cpp \
    sqlreadytablemodel.cpp

HEADERS  += mainwindow.h \
    cnsmapcanvas.h \
    db.h \
    ovrmapcanvas.h \
    QgsMapMarker.h \
    ConfigHandler.h \
    sqlreadytablemodel.h

FORMS    += mainwindow.ui

LIBS += -L ../libs -llibs

unix: LIBS += -L/usr/lib/\
 -lqgis_core \
 -lqgis_gui \
 -lgdal
 
RESOURCES += ui/style.qrc

INCLUDEPATH += /usr/include/qgis
DEPENDPATH += /usr/include/qgis

INCLUDEPATH += ../libs/

INCLUDEPATH += ../fusion/
LIBS += ../fusion/libfusion.a

DEFINES += GUI_EXPORT= CORE_EXPORT=

include(../common.pri)
