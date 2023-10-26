#include "database.h"

Database::Database()
    :db(QSqlDatabase::addDatabase("QSQLITE"))
{

    db.setDatabaseName("C:\\Users\\isymo\\Documents\\build-Tic-Tak-Toe-Desktop_Qt_6_5_1_MinGW_64_bit-Debug\\ACCOUNTS.sqlite");
    if(!db.open())
    {
        qDebug() << db.lastError().text();
    }
    QSqlQuery *query = new QSqlQuery(db);
    if(!query->exec( "CREATE TABLE IF NOT EXISTS ACCOUNTS("
                     "UserName VARCHAR(255),"
                     "PassWord VARCHAR(255)"
                     " )"
                     ))
    {
        qDebug() << query->lastError().text();
    }
    delete query;
}


void Database::Record(const QString& login, const QString& password)
{
    QSqlQuery *query = new QSqlQuery(db);
    if(!query->prepare(QString("INSERT INTO ACCOUNTS(UserName, PassWord) VALUES (:UserName, :PassWord);")))
    {
        qDebug() << query->lastError().text();
    }

    query->bindValue(":UserName", login);
    query->bindValue(":PassWord", password);

    if(!query->exec()){
        qDebug() << "error insert into " << "TABLE";
        qDebug() << query->lastError().text();
    }
    delete query;

}
