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
<<<<<<< HEAD
=======
    WaitingForPlayers,
>>>>>>> feb77d24651ab29da91b717402c757459a2d12f8
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
<<<<<<< HEAD
=======
    void setPlayers(int p);
>>>>>>> feb77d24651ab29da91b717402c757459a2d12f8

protected:
    void setSnakes(Snake *s0, Snake *s1);
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void gameLoop();
    void snakeLoop(Snake *s);

signals:
    void gameEnded(int score, bool newHighScore);

signals:
    void gameEnded(int score, bool newHighScore);

private:
    QTimer *gameTimer;
    Snake snake;
<<<<<<< HEAD
=======
    Snake snake1;
>>>>>>> feb77d24651ab29da91b717402c757459a2d12f8
    apple apple;

    const int cellSize = 20;
    const int gridWidth = 30;
    const int gridHeight = 20;
    int gameSpeed = 120;
    int score = 0;
<<<<<<< HEAD
    QString playerName;
=======
    int playerIdx = 0;
    QString playerName;
    int players = 1;
>>>>>>> feb77d24651ab29da91b717402c757459a2d12f8

    Difficulty currentDifficulty = Difficulty::Worm;
    GameState gameState = GameState::WaitingForDifficulty;

<<<<<<< HEAD
    bool checkWallCollision();
    bool checkSelfCollision();
    bool checkAppleCollision();
=======
    bool checkOpponentCollision(Snake s0, Snake s1);
    bool checkWallCollision(Snake s);
    bool checkSelfCollision(Snake s);
    bool checkAppleCollision(Snake s);
>>>>>>> feb77d24651ab29da91b717402c757459a2d12f8
    bool isPaused = false;
    bool gameIsOver = false;
    void spawnApple();
    void gameOver();
};

#endif // GAMEBOARD_H
