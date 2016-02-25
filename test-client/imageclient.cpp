#include "imageclient.h"

ImageClient::ImageClient()
{
    tcp_socket = new QTcpSocket(this);
    connect(tcp_socket, SIGNAL(readyRead()), this, SLOT(getImage()));
    connectToHost("127.0.0.1",32666);
}

void ImageClient::sendMetaData() {
    qDebug() << "sending meta data";
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << QString("Hallo!");
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    tcp_socket->write(block);
}

void ImageClient::connectToHost(QString ip, int port) {
    qDebug() << "connecting to host";
    tcp_socket->connectToHost(ip, port);
    connect(tcp_socket, SIGNAL(connected()), this, SLOT(sendMetaData()));
    block_size=0;
}

void ImageClient::getImage() {
    qDebug() << "receiving data";
    QDataStream in(tcp_socket);
    in.setVersion(QDataStream::Qt_4_0);
    if (block_size == 0) {
        if (tcp_socket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> block_size;
    }
    if (tcp_socket->bytesAvailable() < block_size)
        return;
    QString message;
    in >> message;
    qDebug() << message;
}

