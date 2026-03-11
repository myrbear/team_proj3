#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "menuscreen.h"
#include "gameboard.h"
#include "gameoverscreen.h"

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
    GameBoard *gameBoard;
    QString currentPlayer;
    GameOverScreen *gameOverScreen;

    void showMenu();
    void showGame(QString playerName, int difficultyIndex);
    void showGameOver(int score, bool newHighScore);

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
