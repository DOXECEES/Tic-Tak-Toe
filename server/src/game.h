#ifndef GAME_H
#define GAME_H

#include <stdint.h>
#include <QString>
#include <QPair>
#include <QRandomGenerator>

#include "profile.h"
#include "bitboard.h"
class Game
{
    static constexpr auto  MAX_VAL_FOR_9_BITS = 511;

public:
    explicit Game(uint8_t id, Profile *first, Profile *second = nullptr);

    bool Connect(QTcpSocket *sock, const QString& login) noexcept;
    inline QPair<Profile*, Profile*> GetProfils() {return qMakePair(firstPlayer.get(), secondPlayer.get());};
    inline bool isGameReady() const {return isReady;};
    const QString& GetSenderLogin(QTcpSocket *sock) const;
    const QString& GetSenderLoginR(QTcpSocket *sock) const;



    uint8_t CheakRevenge();
    bool isDraw(const uint16_t board);
    bool GenerateWhoWalks();
    bool MakeMove(const uint8_t pos);

    inline uint16_t GetLastBoard() {return lastBoard;};
    bool isPlayerWin();
    void SetFirstPlayerSymbol(const QString& s);

    inline void SetBoard(const uint16_t board) {lastBoard = std::move(board);};
    inline void SetFirstRevenge(bool ans) {firstWantRevenge = static_cast<uint8_t>(ans);};
    inline void SetSecondRevenge(bool ans) {secondWantRevenge = static_cast<uint8_t>(ans);};
    inline void ResetRevenge() {firstWantRevenge = std::numeric_limits<uint8_t>::max();
                            secondWantRevenge = std::numeric_limits<uint8_t>::max();};
private:
    uint8_t firstWantRevenge = std::numeric_limits<uint8_t>::max();
    uint8_t secondWantRevenge = std::numeric_limits<uint8_t>::max();

    uint16_t lastBoard = 0;
    bool firstMove = 0;
    bool isMoveGen = false;
    bool isReady = false;
    uint8_t id;
    std::unique_ptr<Profile> firstPlayer;
    std::unique_ptr<Profile> secondPlayer;
    QChar firstPlayerSymbol;
    QChar secondPlayerSymbol;

};

#endif // GAME_H
