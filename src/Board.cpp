#include "Board.h"
#include <iostream>

Board::Board(){
    reset();
}

void Board::reset(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}

void Board::display() const{
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            char c = board[i][j];
            if (c == '1')
                std::cout << 'X';
            else if (c == '2')
                std::cout << 'O';
            else
                std::cout << ' ';
            if (j < 2) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "---------" << std::endl;
    }
}

bool Board::makeMove(int x, int y, char player){
    if(board[x][y] != ' ') return false;
    if(x > 3 || x < 0 || y > 3 || y < 0) return false;
    board[x][y] = player;
    return true;
}

char Board::checkWinner(){
    // D -> draw, ' ' -> ongoing, 1 -> X, 2 -> O
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
    }
 
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return board[0][j];
    }

    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];
    bool draw = true;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ')
                draw = false;
    if (draw)
        return 'D';
    return ' '; 
}