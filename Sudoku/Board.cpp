#include <iostream>
#include <iomanip>
#include "Board.h"
Board::Board(int grid_p[N][N])
{
  for(int r = 0; r < N; r++)
    for(int c = 0; c < N; c++)
      grid[r][c] = grid_p[r][c];
}
bool Board::is_in_col(int col, int num)
{
  for (int row = 0; row < N; row++)
    if (grid[row][col] == num)
      return true;
  return false;
}

bool Board::is_in_row(int row, int num)
{
  for (int col = 0; col < N; col++)
    if (grid[row][col] == num)
      return true;
  return false;
}


bool Board::is_in_square(int start_row, int start_col, int num)
{
  //check whether num is present in 3x3 box or not
  for (int row = 0; row < 3; row++)
    for (int col = 0; col < 3; col++)
      if (grid[row+start_row][col+start_col] == num)
        return true;
  return false;
}

bool Board::is_in_any_square(int num)
{
  //check whether num is present in 3x3 box or not
  for (int row = 0; row < 9; row += 3)
    for (int col = 0; col < 9; col += 3)
      if (is_in_square(row, col, num))
        return true;
  return false;
}