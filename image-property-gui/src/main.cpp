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
    QCoreApplication::setOrganizationName("ifaoe");
    QCoreApplication::setOrganizationDomain("ifaoe.de");
    QCoreApplication::setApplicationName("daisi-images-gui");

    QIcon::setThemeName("breeze-dark");
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
    ConfigHandler *config = new ConfigHandler;
    config->InitSettings();

    DatabaseHandler * db = new DatabaseHandler(config);
    db->OpenDatabase();

    MainWindow main_window(config, db);
    if (config->getAppMaximized())
        main_window.showMaximized();
    else
        main_window.show();

	return app.exec();
}
