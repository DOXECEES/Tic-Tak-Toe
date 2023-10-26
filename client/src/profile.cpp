#include "profile.h"

Profile::Profile(std::shared_ptr<Client>client, const QString& login, const QString &password)
    :login(login),
     password(password),
    client(client)
{
    connect(this, &Profile::SendToServerSignal, client.get(), &Client::SendSlot);

}


QByteArray Profile::SendToServer(const QByteArray& arr)
{
    emit SendToServerSignal(arr);
    return client->GetData();
}


bool Profile::isVerified() noexcept
{


    if(verifiedStatus == std::numeric_limits<uint8_t>::min())
    {
        QByteArray buf;
        buf.push_back(Client::SenderCodes::VERIFICATION_CODE);
        buf.push_back(login.size());
        buf.push_back(login.toUtf8());
        buf.push_back(password.size());
        buf.push_back(password.toUtf8());
        verifiedStatus = static_cast<uint8_t>(*SendToServer(buf).data());
    }


    if(verifiedStatus == Client::ServerCodes::OK)
    {
        return true;
    }
    else
    {
        return false;
    }
}
