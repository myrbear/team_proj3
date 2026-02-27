#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QTimer>
#include <snake.h>
#include "apple.h"

class GameBoard : public QWidget
{
    Q_OBJECT

public:
    explicit GameBoard(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void gameLoop();

private:
    QTimer *gameTimer;
    Snake snake;
    apple apple;

    const int cellSize = 20;
    const int gridWidth = 30;
    const int gridHeight = 20;

    bool checkWallCollision();
    bool checkSelfCollision();
    bool checkAppleCollision();
    void spawnApple();
    void gameOver();
};

#endif // GAMEBOARD_H
