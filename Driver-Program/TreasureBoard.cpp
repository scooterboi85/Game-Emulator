
//implementation file for the class that represents teh graphical board in teh treasure hunt game
#include "TreasureBoard.h"
#include <iostream>
#include <iomanip>

void TreasureBoard::mark(Point p, char sym)
{
  board[p.get_row()][p.get_col()] = sym;
}

TreasureBoard::TreasureBoard(int rows_p, int cols_p)
{
  rows = rows_p;
  cols = cols_p;
  for (int r = 0; r < rows; r++)
  {
    vector<char> row(cols, '~');
    board.push_back(row);
  }
}

void TreasureBoard::draw_board()
{
  cout << "    ";
  for(int c = 0; c < cols; c++)
      cout << setw(3) << c;
  cout << '\n';
  for(int r = 0; r < rows; r++)
  {
    cout << setw(4) <<r;
    for(int c = 0; c < cols; c++)
      cout << setw(3) << board[r][c];
    cout << endl;
  }
}
bool TreasureBoard::is_free(
Point p)
{
  //tilde means non-taken space
  return board[p.get_row()][p.get_col()] == '~';
}
bool TreasureBoard::is_free( 
int row, int col)
{
  //tilde means non-taken space
  return board[row][col] == '~';
}