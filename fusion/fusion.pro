# Fusion style plugin
TEMPLATE = lib

QT       += core gui

CONFIG += staticlib

INCLUDEPATH += /usr/include/QtGui

SOURCES += \
    qfusionstyle.cpp \
    qstyleanimation.cpp \
    fusionstyleplugin.cpp \
    qstylehelper.cpp

HEADERS += \
    qfusionstyle.h \
    qfusionstyle_p.h \
    qfusionstylepixmaps_p.h \
    qstyleanimation_p.h \
    fusionstyleplugin.h \
    qstylehelper_p.h

RESOURCES += \
    fusion.qrc
