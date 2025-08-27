#include "Game.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include <iostream>

Game::Game(Player* p1, Player* p2)
	: player1(p1), player2(p2) {}

void Game::play() {
	Board board;
	Player* current = player1;
	int turn = 0;
	std::cout << "\nCurrent board:" << std::endl;
	board.display();
	while (true) {
		current->makeTurn(board);
		char winner = board.checkWinner();
		if (winner == '1' || winner == '2') {
			std::cout << "\nFinal board:" << std::endl;
			board.display();
			std::cout << "Winner: ";
			if (winner == '1') {
				std::cout << "X";
			} else {
				std::cout << "O";
			}
			std::cout << std::endl;
			break;
		} else if (winner == 'D' || winner == 0) {
			std::cout << "\nFinal board:" << std::endl;
			board.display();
			std::cout << "Draw!" << std::endl;
			break;
		}
		if (current == player1) {
			current = player2;
		} else {
			current = player1;
		}
		std::cout << "\nCurrent board:" << std::endl;
		board.display();
		++turn;
	}
}
