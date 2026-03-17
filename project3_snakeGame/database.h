#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QVector>

struct ScoreEntry
{
    QString name;
    int score;
    QString difficulty;
};

class Database
{
public:
    static void initialize();
    static void addScore(const QString &name, int score, const QString &difficulty);
    static QVector<ScoreEntry> getTopScores();
};

#endif // DATABASE_H
