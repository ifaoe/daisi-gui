TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS = libs fusion census-tool id-tool image-property-gui reference-gui

census-tool.depends         = libs fusion
id-tool.depends             = libs fusion
image-property-gui.depends  = libs fusion
reference-gui.depends       = libs fusion


#RESOURCES += shared/ui/style.qrc
