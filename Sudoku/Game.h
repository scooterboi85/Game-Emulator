#ifndef GAME_H
#define GAME_H
#include "Board.h"

class Game
{
  private: 
    Board brd;
  public:
    Game(int grid_p[N][N]) : brd(grid_p) { ;};
    bool valid_move(int row, int col, int num);
    void move();
    bool won();
    void print();
};

#endif