#-------------------------------------------------
#
# Project created by QtCreator 2014-01-28T13:34:45
#
#-------------------------------------------------

QT       += core sql xml webkit

CONFIG += console

TARGET = daisi-reference
TEMPLATE = app

SOURCES += main.cpp \
        MainWindow.cpp \
        DatabaseHandler.cpp \
        UserSettings.cpp \
        ImageCanvas.cpp \
        ImagePopup.cpp \
        ColumnChooser.cpp
        
HEADERS += MainWindow.h \
        DatabaseHandler.h \
        UserSettings.h \
        ImageCanvas.h \
        ImagePopup.h \
        ColumnChooser.h

FORMS    += mainwindow.ui \
            image_popup.ui

unix: LIBS += -L/usr/lib/ \
            -lqgis_core\
            -lqgis_gui \
            -lgdal
            
RESOURCES += ui/style.qrc
            
LIBS += -L ../libs -llibs
INCLUDEPATH += ../libs/

INCLUDEPATH += ../fusion/
LIBS += -L../fusion -lfusion

INCLUDEPATH += /usr/include/qgis
DEPENDPATH += /usr/include/qgis

DEFINES += GUI_EXPORT= CORE_EXPORT=

include(../common.pri)
