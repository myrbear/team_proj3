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

    void move();
    void setDirection(Direction dir);

    QList<QPoint> getBody() const;

private:
    QList<QPoint> body;
    Direction currentDirection;
};


#endif // SNAKE_H
