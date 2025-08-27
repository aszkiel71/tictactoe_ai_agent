#ifndef BOARD_H
#define BOARD_H

class AIPlayer;
class Board {
    char board[3][3];
    friend class AIPlayer;
    void reset();

public:
    Board();
    void display() const;
    bool makeMove(int x, int y, char player);
    char checkWinner();
    const char* getBoard() const { return &board[0][0]; }


};

#endif // BOARD_H