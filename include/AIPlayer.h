#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Player.h"


#include <vector>
using std::vector;



class AIPlayer : public Player{
    public:
        AIPlayer(char symbol);
        int getMove(const char board[3][3]);
        void makeTurn(Board& board) override;
};


#endif // AIPLAYER_H