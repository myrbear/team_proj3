#include <QCoreApplication>
#include "myserver.h"

int main(int argc, char *argv[])
{
    // server tutorial https://www.youtube.com/watch?v=BSdKkZNEKlQ
    // server docs https://doc.qt.io/qt-6/qtcpserver.html
    // fix: undefined ref vtable for class https://stackoverflow.com/questions/1552069/undefined-reference-to-vtable-trying-to-compile-a-qt-project
    // fix: terminal won't open https://stackoverflow.com/questions/38811319/qtcreator-does-not-open-terminal-for-building
    QCoreApplication a(argc, argv);

    myserver serv; // create an instance of my server

    // install telnet dism /online /Disable-Feature /FeatureName:TelnetClient https://www.windowsdigitals.com/install-telnet-cmd-powershell-windows-11/
    // open 127.0.0.1 1234
    // open localhost on port hardcoded to interact with server

    return a.exec();
}
