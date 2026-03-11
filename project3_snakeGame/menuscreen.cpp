#include "menuscreen.h"
#include "database.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QHeaderView>

MenuScreen::MenuScreen(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *title = new QLabel("Snake Leaderboard");
    title->setAlignment(Qt::AlignCenter);

    nameInput = new QLineEdit();
    nameInput->setPlaceholderText("Enter your name");

    difficultyBox = new QComboBox();
    difficultyBox->addItem("Slug");
    difficultyBox->addItem("Worm");
    difficultyBox->addItem("Python");

    startButton = new QPushButton("Start Game");

    leaderboard = new QTableWidget(5,3);
    leaderboard->setHorizontalHeaderLabels({"Name","Score","Difficulty"});
    leaderboard->verticalHeader()->setVisible(false);

    layout->addWidget(title);
    layout->addWidget(leaderboard);
    layout->addWidget(nameInput);
    layout->addWidget(difficultyBox);
    layout->addWidget(startButton);

    loadLeaderboard();

    connect(startButton,&QPushButton::clicked,[this]()
            {
                QString name = nameInput->text().trimmed();

                if(name.isEmpty())
                {
                    nameInput->setPlaceholderText("Please enter a name!");
                    return;
                }

                emit startGame(name, difficultyBox->currentIndex());
            });
}

void MenuScreen::loadLeaderboard()
{
    QVector<ScoreEntry> scores = Database::getTopScores();

    for(int i=0;i<scores.size();i++)
    {
        leaderboard->setItem(i,0,new QTableWidgetItem(scores[i].name));
        leaderboard->setItem(i,1,new QTableWidgetItem(QString::number(scores[i].score)));
        leaderboard->setItem(i,2,new QTableWidgetItem(scores[i].difficulty));
    }
}
