#ifndef PROFILE_H
#define PROFILE_H

#include <QString>

#include "client.h"

class Profile : public QObject
{
    Q_OBJECT
public:
    explicit Profile(std::shared_ptr<Client>client, const QString& login = nullptr, const QString &password = nullptr);
    ~Profile() = default;

    inline const QString& GetLogin() const {return login;};
    inline const QString& GetPassword() const {return password;};

    bool isVerified() noexcept;


    QByteArray SendToServer(const QByteArray& arr);
private:
    QString login;
    QString password;
    uint8_t verifiedStatus = std::numeric_limits<uint8_t>::min();
    std::shared_ptr<Client> client;

signals:
    void SendToServerSignal(const QByteArray& arr);

};

#endif // PROFILE_H
