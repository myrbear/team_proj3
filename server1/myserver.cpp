#include "myserver.h"
myserver::myserver(QObject *parent):QObject(parent) {
    // qtcp structure
    // setup signals and slots
    // new connection, get next pending connection

    server=new QTcpServer(this);
    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));
    if(!server->listen(QHostAddress::Any,1234)){
        qDebug()<<"server fail";
    }
    else{
        qDebug()<<"server success";
    }
}
void myserver::newConnection(){

    // write info, flush to make sure it's written
    // can write to hard drive
    // read from client
    // returns next pending conn as QTcpSocket
    // socket is child of server
    // deleted when QTcpServer is destroyed
    // should still delete socket
    // returns nullptr if no connections available
    QTcpSocket *socket=server->nextPendingConnection();

    // do the thing on connection

    // write actually comes from QUODevice::write(const char *data)
    socket->write("message coming from server");
    socket->flush();
    socket->waitForBytesWritten(3000);
    socket->close();


}
