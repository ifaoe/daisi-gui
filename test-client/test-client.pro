QT += core network gui
#QT -= gui

CONFIG += c++11

TARGET = test-client
#CONFIG += console
#CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    imageclient.cpp

HEADERS += \
    imageclient.h
