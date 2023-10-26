#include "game.h"



Game::Game(uint8_t id, Profile *first, Profile *second)
    :id(id), firstPlayer(first), secondPlayer(second)
{

}


const QString& Game::GetSenderLogin(QTcpSocket *sock) const
{
    if(firstPlayer->GetClient() == sock)
        return firstPlayer->GetLogin();
    else
        return secondPlayer->GetLogin();
}


uint8_t Game::CheakRevenge()
{
    if(firstWantRevenge == std::numeric_limits<uint8_t>::max()
        || secondWantRevenge == std::numeric_limits<uint8_t>::max())
    {
        return std::numeric_limits<uint8_t>::max();
    }
    else
    {
        qDebug() << firstWantRevenge << secondWantRevenge;
        return static_cast<bool>(firstWantRevenge & secondWantRevenge);
    }
}


const QString& Game::GetSenderLoginR(QTcpSocket *sock) const
{
    if(firstPlayer->GetClient() != sock)
        return firstPlayer->GetLogin();
    else
        return secondPlayer->GetLogin();
}


bool Game::Connect(QTcpSocket *sock, const QString& login) noexcept
{
    if(isReady == false)
    {
        secondPlayer = std::make_unique<Profile>(sock, login);
        isReady = true;
        return true;
    }
    return false;
}


void Game::SetFirstPlayerSymbol(const QString& s)
{
    if(s == "X")
    {
        firstPlayer->SetSymbol("X");
        secondPlayer->SetSymbol("O");
    }
    else
    {
        firstPlayer->SetSymbol("O");
        secondPlayer->SetSymbol("X");
    }
}

bool Game::GenerateWhoWalks()
{
    if(isMoveGen == false)
    {
        std::mt19937 rng(std::random_device{}());
        firstMove = std::uniform_int_distribution<>{0, 1}(rng);
        isMoveGen = true;
    }
    return firstMove;
}


bool Game::isPlayerWin()
{
    return BitBoard(lastBoard).isWin();
}


bool Game::isDraw(const uint16_t board)
{
    if((lastBoard | board) == MAX_VAL_FOR_9_BITS)
    {
        return true;
    }
    return false;
}

bool Game::MakeMove(const uint8_t pos)
{
    if(lastBoard & (1 << pos))
    {
        return false;
    }
    return true;
}
