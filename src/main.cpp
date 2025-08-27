#include "Game.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include <iostream>

int main() {
    char playAgain = 'y';
    while(playAgain == 'y' || playAgain == 'Y') {
        std::cout << "Tic-Tac-Toe: X - Human, O - Computer\nPress 'b' to secret game\n";
        std::cout << "Do you want to start first? (y/n): ";
        
        char choice;
        std::cin >> choice;
        Player *p1, *p2;
        if (choice == 'y' || choice == 'Y') {
            p1 = new HumanPlayer('1');
            p2 = new AIPlayer('2');
        } 
        else if (choice == 'b'){
            p1 = new AIPlayer('1');
            p2 = new AIPlayer('2');
        }
        else {
            p1 = new AIPlayer('1');
            p2 = new HumanPlayer('2');
        }
        Game game(p1, p2);
        game.play();
        delete p1;
        delete p2;
        
        std::cout << "\nPlay again? (y/n): ";
        std::cin >> playAgain;
    }
    return 0;
}