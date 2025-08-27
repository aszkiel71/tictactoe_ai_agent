#include "AIPlayer.h"
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::map;
using std::string;

static const char PLAYER_X = '1';
static const char PLAYER_O = '2';
static const char EMPTY = ' ';

map<string, int> memo;

int dfs(char board[3][3], int movesMade, bool ismaxp);
string boardToString(const char board[3][3]);
int checkWinner(const char board[3][3]);

void AIPlayer::makeTurn(Board& board) {
    int move = getMove(board.board);
    if (move == -1) {
        for(int r = 0; r < 3 && move == -1; ++r) {
            for(int c = 0; c < 3 && move == -1; ++c) {
                if(board.makeMove(r, c, playerSymbol)) {
                    move = r * 3 + c;
                }
            }
        }
    } else {
        int row = move / 3;
        int col = move % 3;
        board.makeMove(row, col, playerSymbol);
    }
}


string boardToString(const char board[3][3]){
    string res = "";
    for(int r = 0; r < 3; r++){
        for(int c = 0; c < 3; c++){
            res += board[r][c];
        }
    }
    return res;
}


int AIPlayer::getMove(const char board[3][3]) {
    memo.clear();
    
    bool isEmpty = true;
    for(int r = 0; r < 3 && isEmpty; ++r) {
        for(int c = 0; c < 3 && isEmpty; ++c) {
            if(board[r][c] != ' ') {
                isEmpty = false;
            }
        }
    }
    
    if(isEmpty) {
        srand(time(0));
        int randomValue = rand() % 100;
        
        if(randomValue < 20) {
            return 0;
        } else if(randomValue < 40) {
            return 2;
        } else if(randomValue < 60) {
            return 6;
        } else if(randomValue < 80) {
            return 8;
        } else if(randomValue < 90) {
            return 4;
        } else if(randomValue < 93) {
            return 1;
        } else if(randomValue < 96) {
            return 3;
        } else if(randomValue < 99) {
            return 5;
        } else {
            return 7;
        }
    }
    
    int bestMove = -1;
    int bestScore;
    if (playerSymbol == '1') {
        bestScore = -1000;
    } else {
        bestScore = 1000;
    }
    char tempBoard[3][3];
    for(int r = 0; r < 3; ++r)
        for(int c = 0; c < 3; ++c)
            tempBoard[r][c] = board[r][c];

    for(int r = 0; r < 3; ++r) {
        for(int c = 0; c < 3; ++c) {
            if(tempBoard[r][c] == ' ') {
                tempBoard[r][c] = playerSymbol;
                bool nextPlayerIsMax = (playerSymbol == '2');
                
                int currentMoves = 0;
                for(int i = 0; i < 3; i++) {
                    for(int j = 0; j < 3; j++) {
                        if(tempBoard[i][j] != ' ') currentMoves++;
                    }
                }
                
                int moveScore = dfs(tempBoard, currentMoves, nextPlayerIsMax);
                tempBoard[r][c] = ' ';
                
                bool isBetter;
                if (playerSymbol == '1') {
                    isBetter = (moveScore > bestScore);
                } else {
                    isBetter = (moveScore < bestScore);
                }
                if(isBetter) {
                    bestScore = moveScore;
                    bestMove = r * 3 + c;
                }
            }
        }
    }
    return bestMove;
}




AIPlayer::AIPlayer(char symbol) : Player(symbol) {
}



int checkWinner(const char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == PLAYER_X) return 10;
            if (board[i][0] == PLAYER_O) return -10;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == PLAYER_X) return 10;
            if (board[0][i] == PLAYER_O) return -10;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[1][1] == PLAYER_X) return 10;
        if (board[1][1] == PLAYER_O) return -10;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[1][1] == PLAYER_X) return 10;
        if (board[1][1] == PLAYER_O) return -10;
    }

    return 0; // draw
}



int dfs(char board[3][3], int movesMade, bool ismaxp){
    int score = checkWinner(board);
    if(score == 10 || score == -10){
        return score;
    }
    if(movesMade == 9){
        return 0;
    }

    string boardKey = boardToString(board);
    if(memo.count(boardKey))
        return memo[boardKey];

    if(ismaxp){
        int bestScore = -42;
        for(int r = 0; r < 3; r++){
            for(int c = 0; c < 3; c++){
                if(board[r][c] == EMPTY){
                    board[r][c] = PLAYER_X;
                    bestScore = std::max(bestScore, dfs(board, movesMade + 1, !ismaxp));
                    board[r][c] = EMPTY;
                }
            }
        }
        memo[boardKey] = bestScore;
        return bestScore;
    }
    else{
        int bestScore = 42;
        for(int r = 0; r < 3; r++){
            for(int c = 0; c < 3; c++){
                if(board[r][c] == EMPTY){
                    board[r][c] = PLAYER_O;
                    bestScore = std::min(bestScore, dfs(board, movesMade + 1, !ismaxp));
                    board[r][c] = EMPTY;
                }
            }
        }
        memo[boardKey] = bestScore;
        return bestScore;
    }
}