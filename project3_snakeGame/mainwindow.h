#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "menuscreen.h"
#include "gameboard.h"
#include "gameoverscreen.h"
<<<<<<< HEAD
=======
#include "modeselectscreen.h"
>>>>>>> feb77d24651ab29da91b717402c757459a2d12f8

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    MenuScreen *menuScreen;
<<<<<<< HEAD
    GameBoard *gameBoard;
    QString currentPlayer;
    GameOverScreen *gameOverScreen;

    void showMenu();
    void showGame(QString playerName, int difficultyIndex);
    void showGameOver(int score, bool newHighScore);
=======
    modeselectscreen *modeScreen;
    GameBoard *gameBoard;
    QString currentPlayer;
    GameOverScreen *gameOverScreen;
    int players;

    void showMenu(int players);
    void showGame(QString playerName, int difficultyIndex);
    void showGameOver(int score, bool newHighScore);
    void showModeSelect();
>>>>>>> feb77d24651ab29da91b717402c757459a2d12f8

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
