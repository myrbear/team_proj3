#include "apple.h"

apple::apple() {
    position = QPoint(0,0);
}

QPoint apple::getPosition() const {
    return position;
}

void apple::setPosition(const QPoint &pos)
{
    position = pos;
}
