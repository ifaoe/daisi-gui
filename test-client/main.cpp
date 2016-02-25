#include <QCoreApplication>
#include <imageclient.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ImageClient client;
    return a.exec();
}
