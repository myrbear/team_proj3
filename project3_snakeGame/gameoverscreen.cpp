#include "gameoverscreen.h"
#include "database.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QHeaderView>

GameOverScreen::GameOverScreen(int score, bool newHighScore, QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *gameOver = new QLabel("GAME OVER");
    gameOver->setAlignment(Qt::AlignCenter);
    gameOver->setStyleSheet("font-size:28px;");

    QLabel *scoreLabel = new QLabel("Your Score: " + QString::number(score));
    scoreLabel->setAlignment(Qt::AlignCenter);

    QPushButton *menuButton = new QPushButton("Return to Menu");

    if(newHighScore)
    {
        QLabel *newHigh = new QLabel("NEW HIGH SCORE!");
        newHigh->setAlignment(Qt::AlignCenter);
        newHigh->setStyleSheet(
            "color:red;"
            "font-size:24px;"
            "font-weight:bold;"
            );

        layout->addWidget(newHigh);
    }

    leaderboard = new QTableWidget(5,3);
    leaderboard->setHorizontalHeaderLabels({"Name","Score","Difficulty"});
    leaderboard->verticalHeader()->setVisible(false);

    QVector<ScoreEntry> scores = Database::getTopScores();

    for(int i=0;i<scores.size();i++)
    {
        leaderboard->setItem(i,0,new QTableWidgetItem(scores[i].name));
        leaderboard->setItem(i,1,new QTableWidgetItem(QString::number(scores[i].score)));
        leaderboard->setItem(i,2,new QTableWidgetItem(scores[i].difficulty));

        if(scores[i].score == score)
        {
            for(int col=0; col<3; col++)
                leaderboard->item(i,col)->setBackground(Qt::yellow);
        }
    }

    layout->addWidget(gameOver);
    layout->addWidget(scoreLabel);
    layout->addWidget(leaderboard);
    layout->addWidget(menuButton);

    connect(menuButton,&QPushButton::clicked,this,&GameOverScreen::returnToMenu);
}
