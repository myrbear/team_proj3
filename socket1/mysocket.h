#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class mysocket : public QObject
{
    Q_OBJECT
public:
    explicit mysocket(QObject *parent = nullptr);
    void connect();
    QTcpSocket *socket;
public slots:

signals:
};

#endif // MYSOCKET_H
