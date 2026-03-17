#include "snake.h"

Snake::Snake()
{
    // Start in center of grid
    body.append(QPoint(15, 10));
    body.append(QPoint(14, 10));
    body.append(QPoint(13, 10));

    currentDirection = Direction::Right;
}

void Snake::move(bool grow)
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
    if (!grow) {
        body.removeLast();
    }
}

Direction Snake::getDirection() const
{
    return currentDirection;
}

void Snake::setDirection(Direction dir)
{
    // prevent 180 degree turns
    if ((currentDirection == Direction::Up && dir == Direction::Down) ||
        (currentDirection == Direction::Down && dir == Direction::Up) ||
        (currentDirection == Direction::Left && dir == Direction::Right) ||
        (currentDirection == Direction::Right && dir == Direction::Left))
    {
        return;
    }

    currentDirection = dir;
}


QList<QPoint> Snake::getBody() const
{
    return body;
}

QPoint Snake::getHead() const
{
    return body.first();
}

void Snake::grow()
{
    // duplicate last segment
    body.append(body.last());
}
