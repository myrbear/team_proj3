#include "mainwindow.h"
#include "database.h"
#include "client.h"
#include <QApplication>
#include <QTcpSocket>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Database::initialize();

    MainWindow w;
    Client c;
    w.show();
    return a.exec();
}
