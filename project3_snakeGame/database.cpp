#include "database.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

void Database::initialize()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("snake_scores.db");

    if (!db.open())
    {
        qDebug() << "Database failed to open";
        return;
    }

    QSqlQuery query;

    query.exec(
        "CREATE TABLE IF NOT EXISTS scores ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "name TEXT,"
        "score INTEGER,"
        "difficulty TEXT)"
        );
}

void Database::addScore(const QString &name, int score, const QString &difficulty)
{
    QSqlQuery query;

    query.prepare("INSERT INTO scores (name, score, difficulty) VALUES (:name, :score, :difficulty)");
    query.bindValue(":name", name);
    query.bindValue(":score", score);
    query.bindValue(":difficulty", difficulty);

    if(!query.exec())
    {
        qDebug()<<"Database insert failed"<<query.lastError();
    }

    qDebug()<<"addScore inserted";

    // keep only top 5 scores
    query.exec(
        "DELETE FROM scores WHERE id NOT IN "
        "(SELECT id FROM scores ORDER BY score DESC LIMIT 5)");

    qDebug()<<"Delete query complete.";
}

QVector<ScoreEntry> Database::getTopScores()
{
    QVector<ScoreEntry> scores;

    QSqlQuery query;

    query.exec(
        "SELECT name, score, difficulty FROM scores "
        "ORDER BY score DESC LIMIT 5"
        );

    qDebug()<<"select query complete";

    while (query.next())
    {
        ScoreEntry entry;
        entry.name = query.value(0).toString();
        entry.score = query.value(1).toInt();
        entry.difficulty = query.value(2).toString();

        scores.append(entry);
    }

    return scores;
}

