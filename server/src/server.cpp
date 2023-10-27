#include "server.h"

Server::Server(QObject *parent)
    :QObject(parent),
    db(new DataBase(parent))
{
    availiableGameIds.resize(256);
    std::fill(availiableGameIds.begin(),availiableGameIds.end(),1);

    server = new QTcpServer(this);

    if(!server->listen(QHostAddress::Any, 6000))
    {
        qDebug() << "Failed to listen server";
    }

    QObject::connect(server, &QTcpServer::newConnection, this, &Server::NewConnectionSlot);
    QObject::connect(this, &Server::RequestFromDataBaseSignal, &db, &DataBase::GetRecords);
    QObject::connect(this, &Server::RequestWritetoDataBaseSignal, &db, &DataBase::Record);
    QObject::connect(this, &Server::RequestAnswerSignal, this, &Server::AnswerSlot);


}


QByteArray Server::Proccess(const QByteArray &arr, QTcpSocket *const sender)
{
    QByteArray buf;
    qDebug() << arr;
    switch(arr.at(0))
    {
        case Server::SenderCodes::REGISTRATION_CODE:
        {
            uint8_t loginSize = 0;
            uint8_t passwordSize = 0;
            uint32_t offset = 1;    // first byte is registration code
            QString login;
            loginSize = static_cast<uint8_t>(*arr.mid(offset,1));
            offset += 1;

            qDebug() << loginSize;

            login = arr.mid(offset,loginSize);
            offset += loginSize;

            passwordSize = static_cast<uint8_t>(*arr.mid(offset,1));
            offset += 1;

            QString password;
            password = arr.mid(offset,passwordSize);



            bool res;
            emit RequestWritetoDataBaseSignal(login, password, res, DataBase::TYPE::LOGIN_ONLY);
            qDebug() << login << password ;

            if(res == true)
            {
                buf.push_back(ServerCodes::OK);
            }
            else
            {
                buf.push_back(ServerCodes::NOT_REGISTRATE);
            }

            return buf;
        }
        case Server::SenderCodes::GAME_CREATION_CODE:
        {
            //
            //  arr[0] = code
            //  arr[1] = login size
            //  arr[1 -- arr[1] ] = login
            //

            uint8_t loginSize = arr[1];
            QString login = arr.mid(2, loginSize);

            uint8_t gameId = currentGames.size() + 1;
            //qDebug() << "ENTRY" << gameId;
            if(availiableGameIds[gameId] == true)
            {
                currentGames.push_back(std::make_unique<Game>(gameId, new Profile(sender,login)));
                availiableGameIds[gameId] = false;

                buf.push_back(ServerCodes::CREATED_SUCCESS);
                buf.push_back(gameId);
            }
            else
            {
                buf.push_back(ServerCodes::ERROR);
            }
            qDebug() << buf;
            return buf;
        }
        case Server::SenderCodes::GAME_CONNECTION_CODE:
        {
            //qDebug() << "Entry2";

            uint8_t gameId = arr[1];
            uint8_t loginSize = arr[2];
            QString login;
            login = arr.mid(3,loginSize);
            qDebug() << loginSize;
            qDebug() << login;
            qDebug() << currentGames.size();

            // 1 < 1 -- false

            if(currentGames.size() < gameId)
            {
               buf.push_back(ServerCodes::GAME_NOT_AVAILIABLE);
               qDebug() << "br";
               return buf;
            }

            if(!currentGames[gameId-1]->Connect(sender, login))
            {
               buf.push_back(ServerCodes::GAME_NOT_AVAILIABLE);
               qDebug() << "br2";
               return buf;
            }

            qDebug() << "ENTRY: 3";
            buf.push_back(ServerCodes::START_GAME);
            buf.push_back(gameId);
            auto profils = currentGames[gameId-1]->GetProfils();
            qDebug() << profils.second->GetLogin();
            //qDebug() << profils.first->GetLogin() << profils.second->GetLogin();

            userInGame.insert(std::make_pair<long long int, int>(static_cast<long long>(profils.second->GetClient()->socketDescriptor()), 1));

            //emit RequestAnswerSignal(buf,profils.first->GetClient());
            //emit RequestAnswerSignal(buf,profils.second->GetClient());
            profils.first->GetClient()->write(buf);

            qDebug() << "BUF: " <<buf;
            return buf;
        }
        case Server::SenderCodes::VERIFICATION_CODE:
        {
            uint8_t loginSize = 0;
            uint8_t passwordSize = 0;

            uint32_t offset = 1;    // first byte is verification code
            QString login;
            loginSize = static_cast<uint8_t>(*arr.mid(offset,1));
            offset += 1;

            login = arr.mid(offset,loginSize);
            offset += loginSize;

            passwordSize = static_cast<uint8_t>(*arr.mid(offset,1));
            offset += 1;

            QString password;
            password = arr.mid(offset,passwordSize);


            //qDebug() << login << password << arr;

            // Request to DB;
            bool res;
            emit RequestFromDataBaseSignal(login, password, res, DataBase::TYPE::LOGIN_PASSWORD);

            if(res)
            {
                buf.push_back(ServerCodes::OK);
            }
            else
            {
                buf.push_back(ServerCodes::NO_USER);
            }

            return buf;
        }
        case Server::SenderCodes::REQUEST_CONNECTION:
        {
            if(currentGames[arr[1] - 1]->isGameReady() == true)
            {
                buf.push_back(Server::ServerCodes::START_GAME);
            }
            else
            {
                buf.push_back(Server::ServerCodes::NO_USER);
            }
            return buf;
        }
        case Server::SenderCodes::REQUEST_WALK:
        {
            auto profiles = currentGames[arr[1] - 1]->GetProfils();

            buf.push_back(Server::ServerCodes::WALK);
            buf.push_back(currentGames[arr[1] - 1]->GenerateWhoWalks());
            buf.push_back(profiles.first->GetLogin().size());
            buf.push_back(profiles.first->GetLogin().toUtf8());
            buf.push_back(profiles.second->GetLogin().size());
            buf.push_back(profiles.second->GetLogin().toUtf8());

            QByteArray buf2;
            buf2.push_back(Server::ServerCodes::SET_NAMES);
            buf2.push_back(currentGames[arr[1] - 1]->GenerateWhoWalks());
            buf2.push_back(profiles.first->GetLogin().size());
            buf2.push_back(profiles.first->GetLogin().toUtf8());
            buf2.push_back(profiles.second->GetLogin().size());
            buf2.push_back(profiles.second->GetLogin().toUtf8());

            if(profiles.second->GetClient()->socketDescriptor() == sender->socketDescriptor())
            {
                profiles.first->GetClient()->write(buf2);
            }
            else
            {
                profiles.second->GetClient()->write(buf2);
            }

            qDebug() << "WALK: " << buf;

            return buf;
        }
        case Server::SenderCodes::CHEAK_MOVE:
        {
            qDebug() << "ent";
            uint8_t gameId = arr[1];
            uint8_t pos = arr[2];

            qDebug() << "ent2";

            buf.push_back(ServerCodes::MOVE_ANS);
            buf.push_back(currentGames[gameId-1]->MakeMove(pos));
            buf.push_back(pos);

            qDebug() << "BUFFER: "<< buf;



            return buf;
        }
        case Server::SenderCodes::SEND_BOARD:
        {
            uint8_t gameId = arr[1] - 1;
            uint8_t pos = arr[2];

            // arr[3] -- 8-15 bits
            // arr[4] -- 0-7 bits

            qDebug() << "UINT16" << std::to_string(arr[3]) << std::to_string(static_cast<uint8_t>(arr[4]));


            // WHY!?!?!?!?!??!?!
            unsigned short board = (static_cast<uint16_t>(static_cast<uint8_t>(arr[3])) << 8);
            board |= static_cast<uint16_t>(static_cast<uint8_t>(arr[4]));

            uint16_t prevBoard = currentGames[gameId]->GetLastBoard();

            qDebug() << board;

            currentGames[gameId]->SetBoard(board);

            auto profils = currentGames[gameId]->GetProfils();

            //currentGames[gameId]->SetBoard(board);

            qDebug() << "LAST BOARD" << currentGames[gameId]->GetLastBoard();
            qDebug() << "PREV BOARD" << prevBoard;

            buf.push_back(ServerCodes::SET_CELL);
            buf.push_back(pos);

            if(currentGames[gameId]->isDraw(prevBoard) && !currentGames[gameId]->isPlayerWin())
            {
                buf.clear();
                buf.push_back(ServerCodes::DRAW);
                db.Update(DataBase::COLUMNS::DRAWS, currentGames[gameId]->GetSenderLogin(sender));
                db.Update(DataBase::COLUMNS::DRAWS, currentGames[gameId]->GetSenderLoginR(sender));
            }
            else if(currentGames[gameId]->isPlayerWin())
            {
                QString login = currentGames[gameId]->GetSenderLogin(sender);
                buf.clear();
                buf.push_back(ServerCodes::WIN);
                buf.push_back(login.size());
                buf.push_back(login.toUtf8());
                db.Update(DataBase::COLUMNS::WINS, login);
                db.Update(DataBase::COLUMNS::LOSES, currentGames[gameId]->GetSenderLoginR(sender));
            }


            qDebug() << "BUF" << buf;

            if(profils.second->GetClient()->socketDescriptor() == sender->socketDescriptor())
            {
                profils.first->GetClient()->write(buf);
                if(buf[0] == ServerCodes::WIN || buf[0] == ServerCodes::DRAW)
                    return buf;
            }
            else
            {
                profils.second->GetClient()->write(buf);
                if(buf[0] == ServerCodes::WIN || buf[0] == ServerCodes::DRAW)
                    return buf;
            }

            buf.clear();
            return buf;
        }
        case SenderCodes::REQUEST_STATS:
        {
            // arr[1] -- size of login
            // arr[2- .] -- login
            qDebug() << "Request stat";
            uint8_t loginSize = static_cast<uint8_t>(arr[1]);
            QString login;
            login = arr.mid(2,loginSize);

            auto res = db.GetStats(login);
            buf.push_back(ServerCodes::STATS_ANS);
            buf.push_back(std::get<0>(res));
            buf.push_back(std::get<1>(res));
            buf.push_back(std::get<2>(res));
            qDebug() << buf;

            return buf;
        }
        case SenderCodes::REQUEST_REVENGE:
        {
            uint8_t gameId = static_cast<uint8_t>(arr[1]) - 1;
            auto profiles = currentGames[gameId]->GetProfils();
            qDebug() << "First set rev 1";

            if(currentGames[gameId]->GetSenderLogin(sender) == currentGames[gameId]->GetProfils().first->GetLogin())
            {
                currentGames[gameId]->SetFirstRevenge(arr[2]);
            }
            else
            {
                currentGames[gameId]->SetSecondRevenge(arr[2]);
            }

            uint8_t result = currentGames[gameId]->CheakRevenge();
            qDebug() << "Cheak rev";

            if(result == std::numeric_limits<uint8_t>::max())
            {
                buf.push_back(ServerCodes::NOT_READY);
            }
            else if(result == 0)
            {
                buf.push_back(ServerCodes::REJECT);
            }
            else
            {
                buf.push_back(ServerCodes::ACCEPT);
                currentGames[gameId]->ResetRevenge();
            }

            if(buf[0] == ServerCodes::ACCEPT || buf[0] == ServerCodes::REJECT)
            {
                if(profiles.second->GetClient()->socketDescriptor() == sender->socketDescriptor())
                {
                    profiles.first->GetClient()->write(buf);
                }
                else
                {
                    profiles.second->GetClient()->write(buf);
                }
            }

            qDebug() << buf;
            return buf;
        }
        default:
        {
            buf.push_back(ServerCodes::ERROR);
            return buf;
        }
    }
    return nullptr;

}


/// SLOTS

void Server::NewConnectionSlot()
{
    connectedDevices.push_back(server->nextPendingConnection());
    connect(connectedDevices.back(), &QTcpSocket::readyRead, this, &Server::ReadSlot);

}


void Server::ReadSlot()
{
    QTcpSocket *sok = qobject_cast<QTcpSocket*>(sender());
    while(sok->bytesAvailable()>0)
    {
        QByteArray array = sok->readAll();
        sok->write(this->Proccess(array, sok));
    }

}


void Server::AnswerSlot(const QByteArray& arr, QTcpSocket *client)
{
    client->write(arr);
}

