#ifndef IMAGECLIENT_H
#define IMAGECLIENT_H

#include <QTcpSocket>

class ImageClient : public QObject
{
    Q_OBJECT
public:
    ImageClient();
private slots:
    void getImage();
    void sendMetaData();
private:
    void connectToHost(QString ip, int port);
    QTcpSocket * tcp_socket;
    quint16 block_size;
};

#endif // IMAGECLIENT_H
