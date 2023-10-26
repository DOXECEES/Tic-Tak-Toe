#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>

class Database
{

public:
    Database();
    void Record(const QString& login, const QString& password);

private:
    QSqlDatabase db;
    int id = 0;
};

#endif // DATABASE_H
