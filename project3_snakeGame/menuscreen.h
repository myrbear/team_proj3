#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>

class MenuScreen : public QWidget
{
    Q_OBJECT
public:
    explicit MenuScreen(QWidget *parent = nullptr);

signals:
    void startGame(int difficultyIndex);

private:
    QComboBox *difficultyBox;
    QPushButton *startButton;
};

#endif // MENUSCREEN_H
