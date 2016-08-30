#include <QApplication>
#include <qgsapplication.h>
#include "mainwindow.h"
#include "ConfigHandler.h"
#include <QInputDialog>
#include "qfusionstyle.h"

int main(int argc, char *argv[])
{
    // Applikation initialisieren
   	QCoreApplication::setOrganizationName("ifaoe");
   	QCoreApplication::setOrganizationDomain("ifaoe.de");
   	QCoreApplication::setApplicationName("daisi-bird-census");
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
    palette.setColor(QPalette::ButtonText, Qt::white);
    palette.setColor(QPalette::BrightText, Qt::red);

    palette.setColor(QPalette::Highlight, QColor(142,45,197).lighter());
    palette.setColor(QPalette::HighlightedText, Qt::black);
    app.setPalette(palette);

//    QFile file(":qdarkstyle/style.qss");
//    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        app.setStyleSheet(file.readAll());
//        file.close();
//    }

    ConfigHandler* config = new ConfigHandler();

    // Einlesen der Datenbankparameter
    Database * db = new Database(config);

    db->OpenDatabase();


    bool confirm = true;
    QString user;
    while (confirm) {
        user = QInputDialog::getText(0, "Nutzername", "Bitte Nutzernamen eingeben.", QLineEdit::Normal, "", &confirm);
        if (!confirm)
            exit(0);
        if (!db->checkUsername(user)) {
            QMessageBox::warning(0, "Fehler", "Nutzer existiert nicht oder hat keine Berechtigung für das ID-Tool.");
        } else {
            break;
        }
    }
    config->setUser(user);


    QString password;
    confirm = true;
    while (confirm) {
        password = QInputDialog::getText(0, "Passwort", QString::fromUtf8("Bitte Passwort für Nutzer: %1 angeben.").arg(config->getUser()), QLineEdit::Password,
                                         "", &confirm);
        if (!confirm)
            exit(0);
        if (!db->checkPassword(config->getUser(), password)) {
            QMessageBox::warning(0, "Fehler", "Falsches Passwort.");
        } else {
            break;
        }
    }

    // Qgis Pfad setzen und Provider laden
    QgsApplication::setPrefixPath(config->getQGisPrefixPath(), true);
    QgsApplication::initQgis();

    // Applikation starten
    MainWindow win(config, db);
    if(config->getAppMaximized())
    	win.showMaximized();
	else
    	win.show();
    int result = app.exec();
    win.saveData();

    // Qgis Bibliotheken freigeben
    QgsApplication::exitQgis();

    // Konfiguration freigeben
    delete config;
    delete db;


    // Beenden
    return result;
}
