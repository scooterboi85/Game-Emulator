
//definition file for teh class that represents the graphical board in the game of tersure hunt
#ifndef TREASURE_BOARD_H
#define TREASURE_BOARD_H
#include <vector>
#include "Point.h"
using namespace std;
#define ROWS 30
#define COLS 15
class TreasureBoard 
{
  private:
    vector<vector<char>> board;
    int rows;
    int cols;
  public:
    TreasureBoard(int rows_p = ROWS, int cols_p = COLS);
    void draw_board();
    int get_num_rows() {return rows;}
    int get_num_cols() {return cols;}
    bool is_free(Point p);
    bool is_free(int row, int col);
    void mark(Point, char);
};
#endif