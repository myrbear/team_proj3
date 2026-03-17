#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QTimer>
#include <snake.h>
#include "apple.h"

enum class Difficulty
{
    Slug,
    Worm,
    Python
};

enum class GameState
{
    WaitingForDifficulty,
    Playing,
    Paused,
    GameOver
};

class GameBoard : public QWidget
{
    Q_OBJECT

public:
    explicit GameBoard(QWidget *parent = nullptr);
    void setDifficulty(Difficulty difficulty);
    void resetGame();
    void togglePause();
    void setPlayerName(QString name);
    QString difficultyname;

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void gameLoop();

signals:
    void gameEnded(int score, bool newHighScore);

private:
    QTimer *gameTimer;
    Snake snake;
    apple apple;

    const int cellSize = 20;
    const int gridWidth = 30;
    const int gridHeight = 20;
    int gameSpeed = 120;
    int score = 0;
    QString playerName;

    Difficulty currentDifficulty = Difficulty::Worm;
    GameState gameState = GameState::WaitingForDifficulty;

    bool checkWallCollision();
    bool checkSelfCollision();
    bool checkAppleCollision();
    bool isPaused = false;
    bool gameIsOver = false;
    void spawnApple();
    void gameOver();
};

#endif // GAMEBOARD_H
