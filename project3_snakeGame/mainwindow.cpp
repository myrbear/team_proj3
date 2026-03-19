#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    menuScreen(nullptr),
    gameBoard(nullptr)
{
<<<<<<< HEAD
    showMenu();
=======
    showModeSelect();
>>>>>>> feb77d24651ab29da91b717402c757459a2d12f8
}

MainWindow::~MainWindow()
{
}

<<<<<<< HEAD
void MainWindow::showMenu()
{
=======
void MainWindow::showMenu(int p)
{
    players = p;
>>>>>>> feb77d24651ab29da91b717402c757459a2d12f8
    menuScreen = new MenuScreen(this);
    setCentralWidget(menuScreen);

    connect(menuScreen, &MenuScreen::startGame,
            this, &MainWindow::showGame);
}
<<<<<<< HEAD
=======
void MainWindow::showModeSelect()
{
    modeScreen = new modeselectscreen(this);
    setCentralWidget(modeScreen);

    connect(modeScreen, &modeselectscreen::startMenu,
            this, &MainWindow::showMenu);
}

>>>>>>> feb77d24651ab29da91b717402c757459a2d12f8

void MainWindow::showGame(QString playerName, int difficultyIndex)
{
    currentPlayer = playerName;
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
    gameBoard->setPlayerName(playerName);
<<<<<<< HEAD
=======
    gameBoard->setPlayers(players);// will still gen 2 snakes, but only process 1's life if needed
>>>>>>> feb77d24651ab29da91b717402c757459a2d12f8

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
<<<<<<< HEAD
                showMenu();
=======
                showModeSelect();
>>>>>>> feb77d24651ab29da91b717402c757459a2d12f8
            });

    // keyboard focus
    gameBoard->setFocusPolicy(Qt::StrongFocus);
    gameBoard->setFocus();

    // game over
    connect(gameBoard, &GameBoard::gameEnded, this, &MainWindow::showGameOver);
}

void MainWindow::showGameOver(int score, bool newHighScore)
{
    GameOverScreen *gameOverScreen = new GameOverScreen(score, newHighScore, this);
    setCentralWidget(gameOverScreen);
<<<<<<< HEAD
    connect(gameOverScreen, &GameOverScreen::returnToMenu, this, &MainWindow::showMenu);
=======
    connect(gameOverScreen, &GameOverScreen::returnToMenu, this, &MainWindow::showModeSelect);
>>>>>>> feb77d24651ab29da91b717402c757459a2d12f8
    qDebug() << "Opening game over screen";
}

