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
#include "qfusionstyle.h"

int main(int argc, char * argv[]) {
    QIcon::setThemeName("breeze");
    QStringList theme_paths;
    theme_paths << "/usr/share/icons/";
    QIcon::setThemeSearchPaths(theme_paths);
//    QApplication::setDesktopSettingsAware(false);
//    QApplication::setStyle("GTK+");
	QApplication app(argc,argv);

    QFusionStyle * fusion_style = new QFusionStyle;
    app.setStyle(fusion_style);

    QPalette palette;
    palette.setColor(QPalette::Window, QColor(53,53,53));
    palette.setColor(QPalette::WindowText, Qt::white);
    palette.setColor(QPalette::Base, QColor(15,15,15));
    palette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    palette.setColor(QPalette::ToolTipBase, Qt::white);
    palette.setColor(QPalette::ToolTipText, Qt::white);
    palette.setColor(QPalette::Text, Qt::white);
    palette.setColor(QPalette::Button, QColor(53,53,53));
    palette.setColor(QPalette::ButtonText, Qt::white);
    palette.setColor(QPalette::BrightText, Qt::red);

    palette.setColor(QPalette::Highlight, QColor(142,45,197).lighter());
    palette.setColor(QPalette::HighlightedText, Qt::black);
    app.setPalette(palette);

//    QFile file(":qdarkstyle/style.qss");
//    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//     app.setStyleSheet(file.readAll());
//     file.close();
//    }
	ConfigHandler * cfg = new ConfigHandler(argc, argv);
	DatabaseHandler * db = new DatabaseHandler(cfg);
	MainWindow window(cfg,db);
	window.showMaximized();

	return app.exec();
}
