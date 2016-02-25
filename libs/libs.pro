TEMPLATE = lib

QT  +=  xml sql

CONFIG += staticlib

SOURCES +=  QCategoryCheckButton.cpp \
            QSearchDialog.cpp \
            QCollapsibleToolbox.cpp \
            QFrozenRowTableWidget.cpp \
            qsqlsortmodel.cpp \
            daisimapcanvas.cpp \
    qsqlextendedtablemodel.cpp \
    mapmarker.cpp \
    mapgeometry.cpp

HEADERS +=  QCategoryCheckButton.h \
            QSearchDialog.h \
            QCollapsibleToolbox.h \
            QFrozenRowTableWidget.h \
            qsqlsortmodel.h \
            daisimapcanvas.h \
    qsqlextendedtablemodel.h \
    mapmarker.h \
    mapgeometry.h

INCLUDEPATH += /usr/include/qgis
DEPENDPATH += /usr/include/qgis

DEFINES += GUI_EXPORT= CORE_EXPORT=

include(../common.pri)
