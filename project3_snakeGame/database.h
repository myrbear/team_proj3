#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include <QSqlDatabase.h>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class database;
}

class database : public QMainWindow
{
    Q_OBJECT

public:
    explicit database(QWidget *parent = nullptr);
    ~database();
    void login();

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::database *ui;
    QSqlDatabase db;
};

#endif // DATABASE_H
