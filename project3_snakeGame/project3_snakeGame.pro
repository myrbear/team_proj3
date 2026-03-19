QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += widgets sql
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    apple.cpp \
    database.cpp \
    gameboard.cpp \
    gameoverscreen.cpp \
    main.cpp \
    mainwindow.cpp \
    menuscreen.cpp \
<<<<<<< HEAD
=======
    modeselectscreen.cpp \
>>>>>>> feb77d24651ab29da91b717402c757459a2d12f8
    snake.cpp

HEADERS += \
    apple.h \
    database.h \
    gameboard.h \
    gameoverscreen.h \
    mainwindow.h \
    menuscreen.h \
<<<<<<< HEAD
=======
    modeselectscreen.h \
>>>>>>> feb77d24651ab29da91b717402c757459a2d12f8
    snake.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
