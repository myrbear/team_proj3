#include "gameboard.h"
#include <QPainter>
#include <QKeyEvent>
#include <QRandomGenerator>

GameBoard::GameBoard(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(gridWidth * cellSize, gridHeight * cellSize);
    setFocusPolicy(Qt::StrongFocus);
    spawnApple();
    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &GameBoard::gameLoop);
    gameTimer->start(150);
}

void GameBoard::gameLoop()
{
    // Predict next head position
    QPoint nextHead = snake.getHead();

    switch (snake.getDirection())
    {
    case Direction::Up:
        nextHead.ry() -= 1;
        break;
    case Direction::Down:
        nextHead.ry() += 1;
        break;
    case Direction::Left:
        nextHead.rx() -= 1;
        break;
    case Direction::Right:
        nextHead.rx() += 1;
        break;
    }

    bool grow = (nextHead == apple.getPosition());

    snake.move(grow);

    if (checkWallCollision() || checkSelfCollision())
    {
        gameOver();
        return;
    }

    if (grow)
        spawnApple();

    update();
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

    // draw apple
    painter.setBrush(Qt::red);
    painter.drawEllipse(apple.getPosition().x() * cellSize, apple.getPosition().y() * cellSize, cellSize, cellSize);

    // Game over pop-up
    if (!gameTimer->isActive())
    {
        painter.setPen(Qt::white);
        painter.setFont(QFont("Arial", 24, QFont::Bold));
        painter.drawText(rect(), Qt::AlignCenter, "GAME OVER");
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

bool GameBoard::checkWallCollision()
{
    QPoint head = snake.getHead();

    if (head.x() < 0 || head.x() >= gridWidth || head.y() < 0 || head.y() >= gridHeight)
    {
        return true;
    }

    return false;
}

bool GameBoard::checkSelfCollision()
{
    QList<QPoint> body = snake.getBody();
    QPoint head = snake.getHead();

    for (int i = 1; i < body.size(); ++i)
    {
        if (head == body[i])
            return true;
    }

    return false;
}

void GameBoard::gameOver()
{
    gameTimer->stop();
    update();
}

void GameBoard::spawnApple()
{
    while (true)
    {
        int x = QRandomGenerator::global()->bounded(gridWidth);
        int y = QRandomGenerator::global()->bounded(gridHeight);

        QPoint newPos(x, y);

        // Make sure apple doesn't spawn on snake
        const QList<QPoint>& body = snake.getBody();
        if (!body.contains(newPos))
        {
            apple.setPosition(newPos);
            return;
        }
    }
}

bool GameBoard::checkAppleCollision()
{
    if (snake.getHead() == apple.getPosition())
    {
        snake.grow();
        spawnApple();
        return true;
    }

    return false;
}
