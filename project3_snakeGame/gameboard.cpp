#include "gameboard.h"
#include "database.h"
#include <QPainter>
#include <QKeyEvent>
#include <QRandomGenerator>

GameBoard::GameBoard(QWidget *parent)
    : QWidget(parent)
{
    snake = Snake();
    snake1 = Snake();

    setSnakes(&snake, &snake1);
    setFixedSize(gridWidth * cellSize, gridHeight * cellSize);
    setFocusPolicy(Qt::StrongFocus);
    spawnApple();
    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &GameBoard::gameLoop);
}

void GameBoard::setSnakes(Snake* s0, Snake* s1){

    // Start in center of grid
    (*s0).addBodySeg(QPoint(15, 10));
    (*s0).addBodySeg(QPoint(14, 10));
    (*s0).addBodySeg(QPoint(13, 10));
    (*s0).setDirection(Direction::Right);

    (*s1).addBodySeg(QPoint(20, 10));
    (*s1).addBodySeg(QPoint(19, 10));
    (*s1).addBodySeg(QPoint(18, 10));
    (*s1).setDirection(Direction::Right);
}

void GameBoard::snakeLoop(Snake *s){

    (*s).dropTrigger();

    // Predict next head position
    QPoint nextHead = (*s).getHead();

    bool grow = (nextHead == apple.getPosition());
    (*s).move(grow);

    if (checkWallCollision((*s)) || checkSelfCollision((*s)))
    {
        gameOver();
        return;
    }

    switch ((*s).getDirection())
    {
    case Direction::Up:
        nextHead.ry() -= 1;
        break;
    case Direction::Down:
        nextHead.ry() += 1;
        break;
    case Direction::Left:
        nextHead.rx() -= 1;
        break;
    case Direction::Right:
        nextHead.rx() += 1;
        break;
    }

    if (grow)
    {
        score++;
        spawnApple();
    }
}
void GameBoard::setPlayers(int p){
    players = p;
}
void GameBoard::gameLoop()
{
    snakeLoop(&snake);

    if (players == 2){
        snakeLoop(&snake1);

        if (checkOpponentCollision(snake, snake1)){
            gameOver(); // has a gate called gameOver
            return;
        }
    }

    update();
}

void GameBoard::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    // Background
    painter.fillRect(rect(), QColor(25, 25, 25));

    // Draw grid (optional retro feel)
    painter.setPen(QColor(40, 40, 40));
    for (int x = 0; x < gridWidth; ++x)
        painter.drawLine(x * cellSize, 0, x * cellSize, height());

    for (int y = 0; y < gridHeight; ++y)
        painter.drawLine(0, y * cellSize, width(), y * cellSize);

    // Draw snakes
    painter.setBrush(QColor(0, 200, 0));
    painter.setPen(Qt::NoPen);

    for (const QPoint &segment : snake.getBody())
    {
        painter.drawRect(segment.x() * cellSize,
                         segment.y() * cellSize,
                         cellSize,
                         cellSize);
    }

    if (players == 2){
        for (const QPoint &segment : snake1.getBody())
        {
            painter.drawRect(segment.x() * cellSize,
                             segment.y() * cellSize,
                             cellSize,
                             cellSize);
        }
    }

    // draw apple
    painter.setBrush(Qt::red);
    painter.drawEllipse(apple.getPosition().x() * cellSize, apple.getPosition().y() * cellSize, cellSize, cellSize);

    // draw score
    painter.setPen(Qt::white);
    painter.setFont(QFont("Arial", 14, QFont::Bold));
    painter.drawText(rect().adjusted(0,0,0, -height() + 30), Qt::AlignHCenter, "Score: " + QString::number(score));

    // Paused and game over pop-up
    if (gameState == GameState::Paused)
    {
        painter.setPen(Qt::yellow);
        painter.setFont(QFont("Arial", 24, QFont::Bold));
        painter.drawText(rect(), Qt::AlignCenter, "PAUSED");

        QVector<ScoreEntry> scores = Database::getTopScores();
        int y = 200;
        for (ScoreEntry &s : scores)
        {
            painter.drawText(100, y, s.name + " - " + QString::number(s.score));
            y += 30;
        }
    }else if (gameState == GameState::GameOver)
    {
        painter.setPen(Qt::white);
        painter.setFont(QFont("Arial", 24, QFont::Bold));
        QString gameOverText = "GAME OVER\nFinal Score: " + QString::number(score);
        painter.drawText(rect(), Qt::AlignCenter, gameOverText);
    }

    // pause text
    if (isPaused)
    {
        painter.setPen(Qt::yellow);
        painter.setFont(QFont("Arial", 24, QFont::Bold));
        painter.drawText(rect(), Qt::AlignCenter, "PAUSED");
    }
}

void GameBoard::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Up:
        snake.setDirection(Direction::Up);
        break;
    case Qt::Key_Down:
        snake.setDirection(Direction::Down);
        break;
    case Qt::Key_Left:
        snake.setDirection(Direction::Left);
        break;
    case Qt::Key_Right:
        snake.setDirection(Direction::Right);
        break;
    }

    if (players == 2){
        switch (event->key())
        {
        case Qt::Key_W:
            snake1.setDirection(Direction::Up);
            break;
        case Qt::Key_S:
            snake1.setDirection(Direction::Down);
            break;
        case Qt::Key_A:
            snake1.setDirection(Direction::Left);
            break;
        case Qt::Key_D:
            snake1.setDirection(Direction::Right);
            break;
        }
    }
}

bool GameBoard::checkWallCollision(Snake s)
{
    QPoint head = s.getHead();

    if (head.x() < 0 || head.x() >= gridWidth || head.y() < 0 || head.y() >= gridHeight)
    {
        return true;
    }

    return false;
}

bool GameBoard::checkOpponentCollision(Snake s0, Snake s1){
    QList<QPoint> body0 = s0.getBody();
    QList<QPoint> body1 = s1.getBody();

    QPoint head0 = s0.getHead();
    QPoint head1 = s1.getHead();

    for (int i = 1; i < body1.size(); ++i)
    {
        if (head0 == body1[i])
            return true;
    }
    for (int i = 1; i < body0.size(); ++i){
        if (head1 == body0[i]){
            return true;
        }
    }

    return false;
}

bool GameBoard::checkSelfCollision(Snake s)
{
    QList<QPoint> body = s.getBody();
    QPoint head = s.getHead();

    for (int i = 1; i < body.size(); ++i)
    {
        if (head == body[i])
            return true;
    }

    return false;
}

void GameBoard::gameOver()
{
    if (gameIsOver)
    {
        return;
    }
    qDebug() << "Game over reached";
    gameIsOver = true;
    gameTimer->stop();
    Database::addScore(playerName, score, difficultyname);
    bool newHighScore = false;
    QVector<ScoreEntry> scores = Database::getTopScores();

    if(!scores.isEmpty() && scores[0].score == score)
    {
        newHighScore = true;
    }
    qDebug()<<"newHighScore if statement updated";
    int finalScore = score;
    bool finalHighScore = newHighScore;
    QMetaObject::invokeMethod(this, [this, finalScore, finalHighScore]() {
        emit gameEnded(finalScore, finalHighScore);
    }, Qt::QueuedConnection);
    //emit gameEnded(score, newHighScore);
    qDebug() << "Game over scheduled";
}

// reset all logic upon reset
void GameBoard::resetGame()
{
    gameIsOver = false;
    score = 0;
    snake = Snake();
    snake1 = Snake();
    setSnakes(&snake, &snake1);
    spawnApple();
    gameState = GameState::Playing;
    gameTimer->start(gameSpeed);
    update();
}

void GameBoard::setDifficulty(Difficulty difficulty)
{
    switch (difficulty)
    {
    case Difficulty::Slug:
        gameSpeed = 200;
        difficultyname = "Slug";
        break;
    case Difficulty::Worm:
        gameSpeed = 120;
        difficultyname = "Worm";
        break;
    case Difficulty::Python:
        gameSpeed = 70;
        difficultyname = "Python";
        break;
    }

    resetGame();
}

void GameBoard::setPlayerName(QString name)
{
    playerName = name;
}

void GameBoard::spawnApple()
{
    // there is one apple that moves, an illusion of many apples
    int maxAttempts = 100;
    int attempt = 0;

    while (attempt < maxAttempts)
    {
        int x = QRandomGenerator::global()->bounded(gridWidth);
        int y = QRandomGenerator::global()->bounded(gridHeight);

        QPoint newPos(x, y);

        // Make sure apple doesn't spawn on either snake
        const QList<QPoint>& body = snake.getBody();
        const QList<QPoint>& body1 = snake1.getBody();

        if (!body.contains(newPos))
        {
            if (players == 1 || (players == 2 && !body1.contains(newPos))){
                apple.setPosition(newPos);
                return;
            }
        }

        attempt++;
    }

    return;
}

bool GameBoard::checkAppleCollision(Snake s)
{
    if (s.getHead() == apple.getPosition())
    {
        s.grow();
        spawnApple();
        return true;
    }

    return false;
}

void GameBoard::togglePause()
{
    if (gameState == GameState::Playing)
    {
        gameTimer->stop();
        gameState = GameState::Paused;
    }else if (gameState == GameState::Paused)
    {
        gameTimer->start(gameSpeed);
        gameState = GameState::Playing;
    }

    update();
}
