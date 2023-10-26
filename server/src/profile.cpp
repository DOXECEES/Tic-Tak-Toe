#include "profile.h"

Profile::Profile(QTcpSocket *client, const QString& login)
    :client(client),
    login(login)
{


}


QByteArray Profile::SendToServer(const QByteArray& arr)
{

}


