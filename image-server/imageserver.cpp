#include "imageserver.h"
#include <QTcpSocket>
#include <QDebug>

ImageServer::ImageServer()
{
    tcp_server = new QTcpServer(this);
    if (!tcp_server->listen(QHostAddress::Any, 32666)) {
        qWarning("Unable to start the server.");
        exit(1);
    }
    connect(tcp_server, SIGNAL(newConnection()), this, SLOT(openSession()));
    qDebug() << QString("Server Running on port %2").arg(tcp_server->serverPort());
}

void ImageServer::openSession() {
    qDebug() << "New connection";
    client_connection = tcp_server->nextPendingConnection();
    block_size = 0;
    connect(client_connection, SIGNAL(readyRead()), this, SLOT(getMetaData()));
}

void ImageServer::getMetaData() {
    qDebug() << "receiving data";
    QDataStream in(client_connection);
    in.setVersion(QDataStream::Qt_4_0);
    if (block_size == 0) {
        if (client_connection->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> block_size;
    }
    if (client_connection->bytesAvailable() < block_size)
        return;
    QString message;
    in >> message;
    qDebug() << message;
    sendImage();
}

void ImageServer::sendImage() {
    qDebug() << "sending data";
    block_size = 0;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << QString("Hier bin ich!");
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    client_connection->write(block);
}
