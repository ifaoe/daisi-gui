TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS = libs census-tool id-tool image-property-gui

census-tool.depends         = libs
id-tool.depends             = libs
image-property-gui.depends  = libs

