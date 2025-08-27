#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"

class Game {
public:
    Game(Player* p1, Player* p2);
    void play();
private:
    Player* player1;
    Player* player2;
};

#endif // GAME_H