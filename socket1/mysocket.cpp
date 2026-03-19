#include "mysocket.h"

mysocket::mysocket(QObject *parent)
    : QObject{parent}
{}

void mysocket::connect(){
    // similar to telnet open

    // connect

    //	port 1234 manage sql connections?

    socket = new QTcpSocket(this);
    //127.0.0.1 1234
    // reading 0, no response
    // "agar.io", 80
    socket->connectToHost("127.0.0.1", 1234);

    if (socket->waitForConnected(3000)){
        qDebug() << "connected";

        // send

        socket->write("hello server/r/n/r/n/r/n/r/n");

        // receive

        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        qDebug() << "Reading: " << socket->bytesAvailable();
        qDebug() << socket->readAll();
        socket->close();

        //QByteArray data = socket->readAll();

        //char* msg = data.data();
        //int len = data.length();
        //for (int i = 0; i < len; i++) {
        //    qDebug() << msg[i];
        //}
    }
    else{
        qDebug() << "failed to connect";
    }

    // close
}
