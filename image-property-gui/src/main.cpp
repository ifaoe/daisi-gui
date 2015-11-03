//============================================================================
// Name        : 2015-07-image-properties-gui.cpp
// Author      : Axel Wegener
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <QApplication>
#include "MainWindow.h"
#include "ConfigHandler.h"
#include "DatabaseHandler.h"

int main(int argc, char * argv[]) {
    QIcon::setThemeName("breeze");
    QStringList theme_paths;
    theme_paths << "/usr/share/icons/";
    QIcon::setThemeSearchPaths(theme_paths);
//    QApplication::setDesktopSettingsAware(false);
//    QApplication::setStyle("GTK+");
	QApplication app(argc,argv);
    QFile file(":qdarkstyle/style.qss");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
     app.setStyleSheet(file.readAll());
     file.close();
    }
	ConfigHandler * cfg = new ConfigHandler(argc, argv);
	DatabaseHandler * db = new DatabaseHandler(cfg);
	MainWindow window(cfg,db);
	window.showMaximized();

	return app.exec();
}
