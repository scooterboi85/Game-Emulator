#include "Game.h"

bool Game::valid_move(int row, int col, int num)
{
  if(num > 9 || num < 1)
  {
    cout << "\nNumber out of range; please try again: ";
    return false;
  }
  else if(row > 9 || row < 0)
  {
    cout << "\nRow out of range; please try again: ";
    return false;
  }
  else if (col > 9 || col < 0)
  {
    cout << "\nColumn out of range; please try again: ";
    return false;
  }
  else if(brd.grid[row][col] != 0)
  {
    cout << "This position is taken; please try again:";
    return false;
  }
  else if(brd.is_in_row(row, num))
  {
    cout << "\nRow " << row << " already contains this number; please try again: ";
    return false;
  }
  else if(brd.is_in_col(col, num))
  {
    cout << "\nColumn " << col<< " already contains this number; please try again: ";
    return false;
     
  }
  else if(brd.is_in_any_square(num))
  {
    cout << "\nGiven square already contains this number; please try again: ";
    return false;
  }
  else
    return true;
}

void Game::move()
{
  int row, col, num;
  bool valid = false;
  while(valid == false)
  {
    cout << "\nEnter row: ";
    cin >> row;
    cout << "\nEnter column: ";
    cin >> col;
    cout << "\nEnter a number: ";
    cin >> num;
    valid = valid_move(row - 1, col - 1, num);
  }
  brd.grid[row][col] = num;
}

void Game::print()
{
  cout << "     ";

  for(int c = 0; c < 9; c++)
   {
      cout << setw(3) << c + 1<< ".";
      if(c == 2 || c == 5)
        cout << " | ";
   }
  
  cout << "\n  --------------------------------------------\n";
  for(int r =  0; r < 9;r++)
  {
    cout << setw(2) << r + 1 << ". |";
    for(int c = 0; c < 9; c++)
    {
      cout << setw(3) << brd.grid[r][c] << " ";
      if(c == 2 || c == 5)
        cout << " | ";
    }
    if(r == 2 || r == 5)
      cout << "\n  --------------------------------------------\n";
    else
      cout << "\n";
  }
}

bool Game::won()
{
  for(int r =  0; r < 9;r++)
  {
    for(int c = 0; c < 9; c++)
    {
      if(brd.grid[r][c] == 0)
        return false;
    }
  }
  return true;
}
