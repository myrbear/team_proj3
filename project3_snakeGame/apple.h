#ifndef APPLE_H
#define APPLE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class apple
{
public:
    apple();

    QPoint getPosition() const;
    void setPosition(const QPoint &pos);

private:
    QPoint position;
};

#endif // APPLE_H
