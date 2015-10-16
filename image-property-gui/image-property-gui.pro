QT += core gui sql

TARGET = daisi-img-prop
TEMPLATE = app

SOURCES += 2015-07-image-properties-gui.cpp \
        MainWindow.cpp \
        ConfigHandler.cpp \
        DatabaseHandler.cpp
		
HEADERS  += MainWindow.h \
        ConfigHandler.h \
        DatabaseHandler.h


FORMS    += main_window.ui
			

INCLUDEPATH += ../libs/


LIBS += -L ../libs -llibs

unix: LIBS += -L/usr/lib/ \
    -lboost_program_options

include(../common.pri)
 
