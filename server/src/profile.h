#ifndef PROFILE_H
#define PROFILE_H

#include <QString>
#include <QObject>
#include <QTcpSocket>

class Profile : public QObject
{
    Q_OBJECT
public:
    explicit Profile(QTcpSocket *client, const QString& login = nullptr);
    ~Profile() = default;

    inline const QString& GetLogin() const {return login;};
    inline QTcpSocket* GetClient() const {return client;};
    inline void SetSymbol(QString s) {symbol = std::move(s);};
    inline QString GetSymbol() const {return symbol;};

    QByteArray SendToServer(const QByteArray& arr);
private:
    QString login;
    QTcpSocket *client;
    QString symbol;
signals:
    void SendToServerSignal(const QByteArray& arr);

};

#endif // PROFILE_H
