#include "client.h"

Client::Client(QObject *parent)
    : QObject{parent}
{
    socket = new QTcpSocket(this);
    connect( socket, SIGNAL(newConnection()), this, SLOT(readTcpData()) );
    socket->connectToHost("127.0.0.1", 1234);
    if ( socket->waitForConnected() ) {
        socket->write( "hello from snake game client" );
    }
}

void Client::newConnection(){
    QByteArray data = socket->readAll();

    char* msg = data.data();
    int len = data.length();
    for (int i = 0; i < len; i++) {
        qDebug() << msg[i];
    }
}
