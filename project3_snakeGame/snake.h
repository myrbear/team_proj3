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
    Snake();

    void move(bool grow = false);
    void setDirection(Direction dir);
    Direction getDirection() const;
    QPoint getHead() const;
    QList<QPoint> getBody() const;
    void grow();

private:
    QList<QPoint> body;
    Direction currentDirection;
};


#endif // SNAKE_H
