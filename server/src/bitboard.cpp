#include "bitboard.h"

#include <QDebug>

BitBoard::BitBoard(const uint16_t board)
    :board(board)
{
    winCombinations.push_back(0b111);
    winCombinations.push_back(0b111000000);
    winCombinations.push_back(0b1001001);
    winCombinations.push_back(0b111000000);
    winCombinations.push_back(0b10010010);
    winCombinations.push_back(0b000111000);
    winCombinations.push_back(0b010010010);
    winCombinations.push_back(0b100010001);
    winCombinations.push_back(0b001010100);

}


BitBoard::BitBoard()
    :board(0)
{
    winCombinations.push_back(0b111);
    winCombinations.push_back(0b111000000);
    winCombinations.push_back(0b1001001);
    winCombinations.push_back(0b111000000);
    winCombinations.push_back(0b10010010);
    winCombinations.push_back(0b000111000);
    winCombinations.push_back(0b010010010);
    winCombinations.push_back(0b100010001);
    winCombinations.push_back(0b001010100);
}


// return false if pos free
bool BitBoard::CheakPosition(uint8_t pos) noexcept
{
    return (board & (1<<pos));
}


bool BitBoard::SetPosition(uint8_t pos) noexcept
{
    if(!this->CheakPosition(pos))
    {
        board |= (1<<pos);
        return true;
    }

    return false;
}


bool BitBoard::isWin()
{
    qDebug() << "BOARD IN WIN " << board;
    for(auto& i : winCombinations)
    {
        if((board & i) == i)
            return true;
    }
    return false;
}


bool BitBoard::isDraw(const uint16_t board)
{
    if((this->board & board) == std::numeric_limits<uint16_t>::max())
        return true;
    else
        return false;
}
