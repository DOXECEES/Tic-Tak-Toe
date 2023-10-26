#ifndef BITBOARD_H
#define BITBOARD_H


#include <stdint.h>
#include <vector>
#include <limits>

// bitboard representation
//+---+----+---+
//| 0 | 1  | 2 |
//+---+----+---+
//| 3 | 4  | 5 |
//+---+----+---+
//| 6 | 7  | 8 |
//+---+----+---+

//     0b111       // top
// 0b1001001       // left
// 0b111000000     // bot
// 0b100100100      // right
// 0b000111000     // HorCenter
// 0b010010010     // VerCenter
// 0b100010001     // Main Diag
// 0b001010100     // oth diag

class BitBoard
{
public:

    BitBoard();
    BitBoard(const uint16_t board);

    bool CheakPosition(uint8_t pos) noexcept;
    bool SetPosition(uint8_t pos) noexcept;
    bool isWin();
    bool isDraw(const uint16_t board);
    inline uint16_t GetBoard() const {return board;};
    // Debug

    void Show();

private:

    uint16_t board;
    std::vector<uint16_t> winCombinations;

};

#endif // BITBOARD_H
