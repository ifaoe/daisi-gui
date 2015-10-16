#-------------------------------------------------
#
# Project created by QtCreator 2014-10-09T15:45:54
#
#-------------------------------------------------

QT += core gui sql webkit network xml

TARGET = daisi-id-tool
TEMPLATE = app

SOURCES +=  main.cpp\
            mainwindow.cpp\
            ImgCanvas.cpp \
            QgsLayerStack.cpp \
            ConfigHandler.cpp \
            DatabaseHandler.cpp \
            CensorSqlTableModel.cpp \
            IdSelectionDialog.cpp \
            ObjectSelectionDialog.cpp \
            MeasurementDialog.cpp 
		
HEADERS  += mainwindow.h\
            ImgCanvas.h \
            QgsLayerStack.h \
            ConfigHandler.h \
            DatabaseHandler.h \
            CensorSqlTableModel.h \
            census.hpp \
            IdSelectionDialog.h \
            ObjectSelectionDialog.h \
            MeasurementDialog.h
        
FORMS    += mainwindow.ui \
            sessiondialog.ui \
            widget_sessions.ui\
            widget_census.ui\
            widget_objects.ui \
            widget_graphics.ui \
            dialog_idselection.ui \
            dialog_object_selection.ui \
            dialog_measurement.ui \
            widget_census_shared.ui

INCLUDEPATH += /usr/include/qgis
DEPENDPATH += /usr/include/qgis

INCLUDEPATH += ../libs/

DEFINES += GUI_EXPORT= CORE_EXPORT=

LIBS += -L ../libs -llibs

unix: LIBS += -L/usr/lib/\
 -lgdal \
 -lqgis_core\
 -lqgis_gui
 
RESOURCES += ui/style.qrc

include(../common.pri)
