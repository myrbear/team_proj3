#include "database.h"
#include "ui_database.h"
#include "mainWindow.h"

database::database(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::database)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE"); // a default connection

    db.setDatabaseName("C:/users/myrbear/Documents/proj/team_proj3/db/game.db");



    //db.setUserName("mzlaf");
    //db.setPassword("asdf");
}

void database::login() {

}

database::~database()
{
    delete ui;
}

void database::on_pushButton_login_clicked()
{
    QString username;
    QString password;

    username = ui->lineEdit_user->text();
    password = ui->lineEdit_pass->text();

    if (!db.open()) {
        ui->label_status->setText("Failed to open db");
    }
    else{
        ui->label_status->setText("Connected to db");

        QSqlQuery qry;

        if (qry.exec("select * from user where username='"+username+"' and passhash='"+password+"'")){

            int count = 0;

            while (qry.next()) {
                count++;
            }
            if (count == 1) {
                ui->label_status->setText("login successful");
                MainWindow *w = new MainWindow();
                w->show();
                hide();
            }
            if (count > 1) {
                ui->label_status->setText("duplicate user found");
            }
            if (count < 1) {
                ui->label_status->setText("no user found");
            }
        }
    }
}

