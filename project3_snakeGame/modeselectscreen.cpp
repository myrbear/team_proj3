#include "modeselectscreen.h"

modeselectscreen::modeselectscreen(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *title = new QLabel("Select Game Mode");
    title->setAlignment(Qt::AlignCenter);


    play1Button = new QPushButton("1 Player");
    play2Button = new QPushButton("2 Player");

    layout->addWidget(title);
    layout->addWidget(play1Button);
    layout->addWidget(play2Button);

    setMinimumSize(600, 450);
    adjustSize();

    connect(play1Button,&QPushButton::clicked,[this]()
            {
                emit startMenu(1);
            });
    connect(play2Button,&QPushButton::clicked,[this]()
            {
                emit startMenu(2);
            });
}
