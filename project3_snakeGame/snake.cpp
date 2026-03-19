#include "snake.h"


Snake::Snake(){
}

<<<<<<< HEAD
=======
void Snake::addBodySeg(QPoint pos){
    body.append(pos);
}

>>>>>>> feb77d24651ab29da91b717402c757459a2d12f8
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
<<<<<<< HEAD
=======
}

void Snake::dropTrigger(){
    moveTrigger = 0;
}
void Snake::raiseTrigger(){
    moveTrigger = 1;
>>>>>>> feb77d24651ab29da91b717402c757459a2d12f8
}

void Snake::setDirection(Direction dir)
{
<<<<<<< HEAD
=======
    if (moveTrigger == 1){
        return;
    }
    raiseTrigger();
>>>>>>> feb77d24651ab29da91b717402c757459a2d12f8
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
