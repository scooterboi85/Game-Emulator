//definition file for te clas that represents the board in a tic tac toe game
#ifndef TTTBOARD_H
#define TTTBOARD_H
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;
class TicTacToeBoard
{
  private:
    vector<char> board;
  public:
    TicTacToeBoard();
    void copy_board(TicTacToeBoard& );
    bool is_full();
    int get_rand_move();
    bool is_open(int move);
    void update(int move);
    void clear();
    void draw_board();
    bool won(char sym);
    char &operator[](int);
};
#endif