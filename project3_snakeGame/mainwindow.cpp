#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    menuScreen(nullptr),
    gameBoard(nullptr)
{
    showMenu();
}

MainWindow::~MainWindow()
{
}

void MainWindow::showMenu()
{
    menuScreen = new MenuScreen(this);
    setCentralWidget(menuScreen);

    connect(menuScreen, &MenuScreen::startGame,
            this, &MainWindow::showGame);
}

void MainWindow::showGame(int difficultyIndex)
{
    gameBoard = new GameBoard(this);

    // Convert int to difficulty enum
    Difficulty difficulty = Difficulty::Worm;

    switch (difficultyIndex)
    {
    case 0: difficulty = Difficulty::Slug; break;
    case 1: difficulty = Difficulty::Worm; break;
    case 2: difficulty = Difficulty::Python; break;
    }

    gameBoard->setDifficulty(difficulty);

    // Main container
    QWidget *container = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(container);

    layout->addWidget(gameBoard);

    // buttons
    QPushButton *pauseButton = new QPushButton("Pause");
    QPushButton *resetButton = new QPushButton("Reset");
    QPushButton *menuButton = new QPushButton("Main Menu");

    QHBoxLayout *controls = new QHBoxLayout();
    controls->addWidget(pauseButton);
    controls->addWidget(resetButton);
    controls->addWidget(menuButton);

    layout->addLayout(controls);

    setCentralWidget(container);

    // pause button
    connect(pauseButton, &QPushButton::clicked, [this, pauseButton]()
            {
                gameBoard->togglePause();
                gameBoard->setFocus();

                if (pauseButton->text() == "Pause")
                    pauseButton->setText("Resume");
                else
                    pauseButton->setText("Pause");
            });

    // reset button
    connect(resetButton, &QPushButton::clicked, [this]()
            {
                gameBoard->resetGame();
                gameBoard->setFocus();
            });

    // back to menu
    connect(menuButton, &QPushButton::clicked, [this]()
            {
                showMenu();
            });

    // keyboard focus
    gameBoard->setFocusPolicy(Qt::StrongFocus);
    gameBoard->setFocus();
}
