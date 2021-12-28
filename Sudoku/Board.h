#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <iomanip>
using namespace std;

#define N 9

class Board
{
  public:
    int grid[N][N];
    Board(int grid_p[N][N]);
    bool is_in_col(int col, int num);
    bool is_in_row(int row, int num);
    bool is_in_square(int start_row, int start_col, int num);
    bool is_in_any_square(int num);
};
#endif