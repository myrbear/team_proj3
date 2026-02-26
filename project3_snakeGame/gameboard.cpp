#include "gameboard.h"
#include <QPainter>
#include <QKeyEvent>

GameBoard::GameBoard(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(gridWidth * cellSize, gridHeight * cellSize);
    setFocusPolicy(Qt::StrongFocus);

    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &GameBoard::gameLoop);
    gameTimer->start(150);   // Speed (we’ll hook difficulty later)
}

void GameBoard::gameLoop()
{
    snake.move();
    update();  // triggers repaint
}

void GameBoard::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    // Background
    painter.fillRect(rect(), QColor(25, 25, 25));

    // Draw grid (optional retro feel)
    painter.setPen(QColor(40, 40, 40));
    for (int x = 0; x < gridWidth; ++x)
        painter.drawLine(x * cellSize, 0, x * cellSize, height());

    for (int y = 0; y < gridHeight; ++y)
        painter.drawLine(0, y * cellSize, width(), y * cellSize);

    // Draw snake
    painter.setBrush(QColor(0, 200, 0));
    painter.setPen(Qt::NoPen);

    for (const QPoint &segment : snake.getBody())
    {
        painter.drawRect(segment.x() * cellSize,
                         segment.y() * cellSize,
                         cellSize,
                         cellSize);
    }
}

void GameBoard::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Up:
        snake.setDirection(Direction::Up);
        break;
    case Qt::Key_Down:
        snake.setDirection(Direction::Down);
        break;
    case Qt::Key_Left:
        snake.setDirection(Direction::Left);
        break;
    case Qt::Key_Right:
        snake.setDirection(Direction::Right);
        break;
    }
}
