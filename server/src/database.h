#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>

class DataBase : public QObject
{    
    Q_OBJECT
public:

    enum COLUMNS
    {
        WINS,
        LOSES,
        DRAWS,
    };

    enum TYPE : bool
    {
        LOGIN_ONLY     = 0,
        LOGIN_PASSWORD = 1,
    };

    DataBase(QObject* parent = nullptr);
    ~DataBase();

public slots:
    void GetRecords(const QString& login, const QString& password, bool &res, TYPE type);
    void Record(const QString& login, const QString& password, bool &res, TYPE type);
    void Update(COLUMNS type, const QString& login);
    std::tuple<int,int,int> GetStats(const QString& login);

private:
    QSqlDatabase db;
    int id = 0;
};

#endif // DATABASE_H
