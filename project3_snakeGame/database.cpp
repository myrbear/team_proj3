#include "database.h"

database::database() {}

void database::databaseLoop() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL"); // a default connection
    db.setDatabaseName("fighterdb");
    db.setUserName("mzlaf");
    db.setPassword("asdf");
    bool ok = db.open();
}
