#include "menuscreen.h"

MenuScreen::MenuScreen(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    difficultyBox = new QComboBox();
    difficultyBox->addItem("Slug");
    difficultyBox->addItem("Worm");
    difficultyBox->addItem("Python");

    startButton = new QPushButton("Start Game");

    layout->addStretch();
    layout->addWidget(difficultyBox);
    layout->addWidget(startButton);
    layout->addStretch();

    QAbstractButton::connect(startButton, &QPushButton::clicked, [this]()
            {
                emit startGame(difficultyBox->currentIndex());
            });
}
