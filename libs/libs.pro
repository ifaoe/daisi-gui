TEMPLATE = lib

QT  +=  xml sql

CONFIG += staticlib

SOURCES +=  QCategoryCheckButton.cpp \
            QSearchDialog.cpp \
            QCollapsibleToolbox.cpp \
            QFrozenRowTableWidget.cpp \
            QgsMapMarker.cpp \
    qsqlsortmodel.cpp

HEADERS +=  QCategoryCheckButton.h \
            QSearchDialog.h \
            QCollapsibleToolbox.h \
            QFrozenRowTableWidget.h \
            QgsMapMarker.h \
    qsqlsortmodel.h

INCLUDEPATH += /usr/include/qgis
DEPENDPATH += /usr/include/qgis

DEFINES += GUI_EXPORT= CORE_EXPORT=

include(../common.pri)
