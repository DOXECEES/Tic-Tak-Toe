#include "client.h"
#include "mainmenu.h"

Client::Client(QObject *parent)
    : QTcpSocket(parent)
{
    // Always change
    QHostAddress *addr = new QHostAddress("192.168.0.101");
    this->connectToHost(*addr, 6000);


    connect(this, &Client::WhoWalksSignal, this, &Client::WhoWalksSlot);


}


void Client::SendSlot(const QByteArray &arr)
{
    this->write(arr);
    connect(this, &QTcpSocket::readyRead, this, &Client::ReadSlot);
    this->waitForReadyRead(100);
}

QByteArray Client::GetAnswer()
{
    if(this->waitForReadyRead())
    {
        QByteArray arr;
        arr = this->readAll();
        return arr;
    }
    else
    {
        return nullptr;
    }
}


void Client::SetLogin(const QString& log)
{
    clientLogin = std::move(log);
}

QByteArray Client::SendWhoWalks(uint8_t id)
{
    emit WhoWalksSignal(id);
    return GetData();
}

void Client::Proc(const QByteArray& arr)
{

    switch (arr[0]) {
    case Client::ServerCodes::START_GAME:
    {
        emit ShowFieldSignal();
        Widget *w = MainMenu::GetWidget();
        w->SetId(arr[1]);
        w->show();
        qDebug() << "ENT";


        SendWhoWalks(arr[1]);
        break;
    }
    case Client::ServerCodes::WALK:
    {
        Widget *w = MainMenu::GetWidget();
        w->SetLabel2("HOST");

        uint8_t firstLoginSize = arr[2];
        QString firstLogin = arr.mid(3, firstLoginSize);
        w->SetFirstPlayerLogin(firstLogin);

        uint8_t secondLoginSize = arr[3 + firstLoginSize];
        QString secondLogin = arr.mid(4 + firstLoginSize, secondLoginSize);
        qDebug() << firstLogin << secondLogin;
        w->SetSecondPlayerLogin(secondLogin);


        if(arr[1])
        {
            w->Block();
            w->SetPlayerWhoMove(secondLogin);
        }
        else
        {
            w->UnBlock();
            w->SetPlayerWhoMove(firstLogin);
        }
        w->SetCurrentPlayer();

        break;
    }
    case Client::ServerCodes::MOVE_ANS:
    {
        Widget* w = MainMenu::GetWidget();
        if(arr[1])
        {
            w->SetCell(arr[2]);
        }
        w->SetCell(arr[2]);
        QByteArray buf;
        buf.push_back(Client::SenderCodes::SEND_BOARD);
        buf.push_back(w->GetGameId());
        buf.push_back(arr[2]);
        //
        uint16_t board = w->GetBoard();
        uint8_t partA = static_cast<uint8_t>((board & 0xFF00) >> 8);
        uint8_t partB = static_cast<uint8_t>(board & 0x00FF);
        //

        qDebug() << "UINT16" << std::to_string(partA) << std::to_string(partB);

        buf.push_back(partA);
        buf.push_back(partB);
        buf.push_back(0xFF);

        emit w->SendToServerSignal(buf);

        w->Block();
        w->SetCurrentPlayer();



        break;
    }
    case Client::ServerCodes::WIN:
    {
        Widget *w = MainMenu::GetWidget();
        uint8_t loginSize = arr[1];
        QString login = arr.mid(2, loginSize);

        w->SetPlayerWhoMove(login);
        w->SetCurrentPlayer();
        w->GameOver();
        //MainMenu::DelWidget();
        break;
    }
    case Client::ServerCodes::SET_CELL:
    {
        Widget *w = MainMenu::GetWidget();

        uint8_t pos = arr[1];
        qDebug() << w->GetBoard();

        w->SetEnemyCell(pos);

        w->UnBlock();
        w->SetCurrentPlayer();


        break;
    }
    // DO NOT CHANGE
    case Client::ServerCodes::SET_NAMES:
    {
        //second
        Widget *w = MainMenu::GetWidget();
        w->SetLabel2("CLIENT");

        uint8_t firstLoginSize = arr[2];
        QString firstLogin = arr.mid(3, firstLoginSize);
        w->SetFirstPlayerLogin(firstLogin);

        uint8_t secondLoginSize = arr[3 + firstLoginSize];
        QString secondLogin = arr.mid(4 + firstLoginSize, secondLoginSize);
        qDebug() << firstLogin << secondLogin;
        w->SetSecondPlayerLogin(secondLogin);

        if(arr[1])
        {
            w->UnBlock();
            w->SetPlayerWhoMove(secondLogin);
        }
        else
        {
            w->Block();
            w->SetPlayerWhoMove(firstLogin);
        }
        w->SetCurrentPlayer();
        break;
    }
    case Client::ServerCodes::DRAW:
    {
        Widget *w = MainMenu::GetWidget();
        w->SetCurrentPlayer();
        w->Draw();
        break;
    }
    case Client::ServerCodes::STATS_ANS:
    {
        emit this->SendStatsSignal(arr[1], arr[2], arr[3]);

        break;
    }
    case Client::ServerCodes::ACCEPT:
    {
        uint8_t gameId = MainMenu::GetWidget()->GetGameId();

        MainMenu::DelWidget();
        QByteArray ar;
        ar.push_back(Client::ServerCodes::START_GAME);
        ar.push_back(gameId);

        Proc(ar);
        break;
    }
    case Client::ServerCodes::REJECT:
    {
        MainMenu::menu->show();
        MainMenu::DelWidget();

    }
    default:
        break;
    }
}

void Client::ReadSlot()
{
    while(this->bytesAvailable() > 0)
    {
        //lastData.clear();
        lastData = this->readAll();
        Proc(lastData);
    }
}

void Client::WhoWalksSlot(uint8_t id)
{
    QByteArray arr;
    arr.push_back(Client::SenderCodes::REQUEST_WALK);
    arr.push_back(id);
    SendSlot(arr);
}
