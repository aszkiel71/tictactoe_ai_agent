#include "Player.h"

Player::Player(char symbol) : playerSymbol(symbol) {} // init list

char Player::getSymbol() {
    return playerSymbol;
}