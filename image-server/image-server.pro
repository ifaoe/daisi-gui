QT += core network gui

CONFIG += c++11

TARGET = image-server
#CONFIG += console
#CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += /usr/include/qgis
DEPENDPATH += /usr/include/qgis

DEFINES += GUI_EXPORT= CORE_EXPORT=

unix: LIBS += -L/usr/lib/\
 -lgdal \
 -lqgis_core\
 -lqgis_gui

SOURCES += main.cpp \
    imageserver.cpp

HEADERS += \
    imageserver.h
