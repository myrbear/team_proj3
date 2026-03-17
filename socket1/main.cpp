#include <QCoreApplication>
#include "mysocket.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    mysocket s;
    s.connect();

    return a.exec();
}
