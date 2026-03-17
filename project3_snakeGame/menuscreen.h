#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTableWidget>

class MenuScreen : public QWidget
{
    Q_OBJECT
public:
    explicit MenuScreen(QWidget *parent = nullptr);

signals:
    void startGame(QString playerName, int difficultyIndex);

private:
    QLineEdit *nameInput;
    QComboBox *difficultyBox;
    QPushButton *startButton;
    QTableWidget *leaderboard;

    void loadLeaderboard();
};

#endif // MENUSCREEN_H
