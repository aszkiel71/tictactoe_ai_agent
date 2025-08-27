#include "HumanPlayer.h"
#include <iostream>
#include <limits>
HumanPlayer::HumanPlayer(char symbol) : Player(symbol) {}

void HumanPlayer::makeTurn(Board& board){
    int mv;
    while(true){
        std::cout << "Enter your move (1 - 9) -> ";
        std::cin >> mv;
        if(std::cin.fail()){
            std::cout << "Unknown character. Try again : ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        int row = (mv - 1) / 3;
        int col = (mv - 1) % 3;
        if(board.makeMove(row, col, playerSymbol)){break;}
        else std::cout << "Error. Try again : \n";
    }
}