#include "snake.h"

Snake::Snake()
{
    // Start in center of grid
    body.append(QPoint(15, 10));
    body.append(QPoint(14, 10));
    body.append(QPoint(13, 10));

    currentDirection = Direction::Right;
}

void Snake::move()
{
    QPoint head = body.first();

    switch (currentDirection)
    {
    case Direction::Up:
        head.ry() -= 1;
        break;
    case Direction::Down:
        head.ry() += 1;
        break;
    case Direction::Left:
        head.rx() -= 1;
        break;
    case Direction::Right:
        head.rx() += 1;
        break;
    }

    body.prepend(head);     // add new head
    body.removeLast();      // remove tail (no growth yet)
}

void Snake::setDirection(Direction dir)
{
    currentDirection = dir;
}

QList<QPoint> Snake::getBody() const
{
    return body;
}
