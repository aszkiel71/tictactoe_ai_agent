#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"

class Player {
public:
    Player(char symbol);
    virtual ~Player() = default;
    char getSymbol();
    virtual void makeTurn(Board& board) = 0;

protected:
    char playerSymbol;

};

#endif // PLAYER_H


