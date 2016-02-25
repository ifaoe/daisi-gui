TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS = libs fusion census-tool id-tool image-property-gui reference-gui \
    image-server \
    test-client

census-tool.depends         = libs fusion
id-tool.depends             = libs fusion
image-property-gui.depends  = libs fusion
reference-gui.depends       = libs fusion


#RESOURCES += shared/ui/style.qrc
