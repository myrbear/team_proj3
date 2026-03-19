#ifndef SNAKE_H
#define SNAKE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QList>
#include <QPoint>

enum class Direction
{
    Up,
    Down,
    Left,
    Right
};

class Snake
{
public:
    Snake(int p);
    Snake();

    void move(bool grow = false);
    void setDirection(Direction dir);
    Direction getDirection() const;
    QPoint getHead() const;
    QList<QPoint> getBody() const;
<<<<<<< HEAD
    void grow();
=======
    void addBodySeg(QPoint pos);
    void grow();
    void raiseTrigger();
    void dropTrigger();
>>>>>>> feb77d24651ab29da91b717402c757459a2d12f8

private:
    int moveTrigger = 0;
    QList<QPoint> body;
    Direction currentDirection;
};


#endif // SNAKE_H
