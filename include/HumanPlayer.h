#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player{
    public:
        HumanPlayer(char symbol);
        void makeTurn(Board& board) override;
};

#endif // HUMANPLAYER_H