//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <QApplication>
#include <QMessageBox>
#include <qgsapplication.h>
#include "ConfigHandler.h"
#include "mainwindow.h"
#include "DatabaseHandler.h"
#include "qfusionstyle.h"

int main(int argc, char *argv[])
{
	QCoreApplication::setOrganizationName("ifaoe");
	QCoreApplication::setOrganizationDomain("ifaoe.de");
	QCoreApplication::setApplicationName("daisi-bird-view");
    QIcon::setThemeName("breeze-dark");
	QStringList theme_paths;
	theme_paths << "/usr/share/icons/";
	QIcon::setThemeSearchPaths(theme_paths);
    QApplication app(argc, argv);

    QFusionStyle * fusion_style = new QFusionStyle;
    app.setStyle(fusion_style);

    QPalette palette;
    palette.setColor(QPalette::Window, QColor(53,53,53));
    palette.setColor(QPalette::WindowText, Qt::white);
    palette.setColor(QPalette::Base, QColor(15,15,15));
    palette.setColor(QPalette::AlternateBase, QColor(53,53,53));
    palette.setColor(QPalette::ToolTipBase, QColor(53,53,53));
    palette.setColor(QPalette::ToolTipText, Qt::white);
    palette.setColor(QPalette::Text, Qt::white);
    palette.setColor(QPalette::Button, QColor(53,53,53));
    palette.setColor(QPalette::Disabled, QPalette::ButtonText, QColor(53,53,53).lighter());
    palette.setColor(QPalette::Active, QPalette::ButtonText, Qt::white);
    palette.setColor(QPalette::Disabled, QPalette::Button, QColor(53,53,53).darker());
//    palette.setColor(QPalette::Inactive, QPalette::ButtonText, Qt::white);
    palette.setColor(QPalette::BrightText, Qt::red);

    palette.setColor(QPalette::Highlight, QColor(142,45,197).lighter());
    palette.setColor(QPalette::HighlightedText, Qt::black);
    app.setPalette(palette);

//    app.setStyle("breeze");
//    QFile file(":qdarkstyle/style.qss");
//     if(file.open(QIODevice::ReadOnly | QIODevice::Text))
//     {
//         app.setStyleSheet(file.readAll());
//         file.close();
//     }
//    QApplication::setDesktopSettingsAware(false);
//    QApplication::setStyle("breeze-dark");
    ConfigHandler *config = new ConfigHandler;
    config->InitSettings();

    // Qgis Pfad setzen und Provider laden
    QgsApplication::setPrefixPath("/usr", true);
    QgsApplication::initQgis();

    DatabaseHandler *db = new DatabaseHandler(config);
    db->OpenDatabase();

    MainWindow main_window(config, db);
    if (config->getAppMaximized())
    	main_window.showMaximized();
    else
    	main_window.show();
    int return_signal = app.exec();
    QgsApplication::exitQgis();
    return return_signal;
}
