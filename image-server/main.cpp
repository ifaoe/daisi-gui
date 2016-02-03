#include <QCoreApplication>
#include <qgis/qgsapplication.h>
#include <imageserver.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // Applikation initialisieren
    QCoreApplication::setOrganizationName("ifaoe");
    QCoreApplication::setOrganizationDomain("ifaoe.de");
    QCoreApplication::setApplicationName("daisi-image-server");

    // Qgis Pfad setzen und Provider laden
    QgsApplication::setPrefixPath("/usr", true);
    QgsApplication::initQgis();

    ImageServer server;

    return a.exec();
}
