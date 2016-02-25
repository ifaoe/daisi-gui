#ifndef IMAGESERVER_H
#define IMAGESERVER_H

#include <QTcpServer>
#include <QNetworkSession>
#include <QWidget>
#include <QMessageBox>

class ImageServer : public QObject
{
    Q_OBJECT
public:
    ImageServer();
private slots:
    void openSession();
    void getMetaData();
    void sendImage();
private:
    QTcpServer * tcp_server;
    QNetworkSession * network_session;
    QTcpSocket * client_connection;
    quint16 block_size;
};

#endif // IMAGESERVER_H
