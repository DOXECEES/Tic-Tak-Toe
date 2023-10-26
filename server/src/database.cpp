#include "database.h"


DataBase::DataBase(QObject *parent)
   // :QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))
{
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:\\Users\\isymo\\Documents\\Tic-Tak-Toe\\server\\bin\\ACCOUNTS.sqlite");

    }

    if(!db.open())
    {
        qDebug() << db.lastError().text();
    }
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE IF NOT EXISTS ACCOUNTS("
                     "UserName VARCHAR(255),"
                     "PassWord VARCHAR(255),"
                     "Wins INTEGER,"
                     "Loses INTEGER,"
                     "Draws INTEGER"
                     " )"
                     ))
    {
        qDebug() << query.lastError().text();
    }

    //this->Record("dasdd","dsadas");

}

// true - not recorded
// false - recorded
void DataBase::Record(const QString& login, const QString& password, bool &res)
{
    QSqlQuery query(db);
    if(!query.prepare(QString("INSERT INTO ACCOUNTS(UserName, PassWord, Wins, Loses, Draws) VALUES (:UserName, :PassWord, :Wins, :Loses, :Draws);")))
    {
        qDebug() << query.lastError().text();
    }


    GetRecords(login, password, res);
    if(res == true) // res == true means that login or password has already been recorded
    {
        res = false;
        // TODO Set bool value to false;
        // print message that this login or password not availiable
        return;
    }
    res = true;

    query.bindValue(":UserName", login);
    query.bindValue(":PassWord", password);
    query.bindValue(":Wins", 0);
    query.bindValue(":Loses", 0);
    query.bindValue(":Draws", 0);


    if(!query.exec()){
        qDebug() << "error insert into " << "TABLE";
        qDebug() << query.lastError().text();
    }

}


void DataBase::GetRecords(const QString& login, const QString& password, bool &res)
{
    QSqlQuery query(db);

    if(!query.prepare("SELECT * FROM ACCOUNTS WHERE UserName = :UserName AND PassWord = :PassWord;"))
    {
        qDebug() << query.lastError().text();
    }

    query.bindValue(":UserName", login);
    query.bindValue(":PassWord", password);

    if(query.exec())
    {
        if(query.next())
            res = true;
        else
            res = false;

    }
}


void DataBase::Update(COLUMNS type, const QString& login)
{
    QSqlQuery query(db);

    QString request;

    switch (type) {
    case COLUMNS::WINS:
    {
        request = "UPDATE ACCOUNTS SET Wins = Wins + 1 WHERE UserName = :UserName";
        break;
    }
    case COLUMNS::LOSES:
    {
        request = "UPDATE ACCOUNTS SET Loses = Loses + 1 WHERE UserName = :UserName";
        break;
    }
    case COLUMNS::DRAWS:
    {
        request = "UPDATE ACCOUNTS SET Draws = Draws + 1 WHERE UserName = :UserName";
        break;
    }
    default:
        break;
    }

    if(!query.prepare(request))
    {
        qDebug() << query.lastError().text();
    }

    query.bindValue(":UserName", login);

    if(!query.exec()){
        qDebug() << "error Update " << "TABLE";
        qDebug() << query.lastError().text();
    }

}


std::tuple<int,int,int> DataBase::GetStats(const QString& login)
{
    QSqlQuery query(db);

    if(!query.prepare("SELECT Wins, Loses, Draws FROM ACCOUNTS WHERE UserName = :UserName;"))
    {
        qDebug() << query.lastError().text();
    }

    query.bindValue(":UserName", login);

    int wins = 0;
    int loses = 0;
    int draws = 0;

    if(query.exec())
    {
        if(query.next())
        {
            wins = query.value("Wins").toInt();
            loses = query.value("Loses").toInt();
            draws = query.value("Draws").toInt();
        }
    }

    return {wins, loses, draws};
}

DataBase::~DataBase()
{
    {
        db.close();
    }
    QSqlDatabase::removeDatabase("ACCOUNTS");
}
