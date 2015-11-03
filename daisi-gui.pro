TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS = libs census-tool id-tool image-property-gui reference-gui

census-tool.depends         = libs
id-tool.depends             = libs
image-property-gui.depends  = libs
reference-gui.depends       = libs

#RESOURCES += shared/ui/style.qrc
