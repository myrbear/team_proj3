#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <QWidget>
#include <QTableWidget>

class GameOverScreen : public QWidget
{
    Q_OBJECT

public:
    GameOverScreen(int score, bool newHighScore, QWidget *parent = nullptr);

signals:
    void returnToMenu();

private:
    QTableWidget *leaderboard;
};

#endif
