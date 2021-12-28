#include "board.h"

void Board::print(int pos1, int pos2)
{
  for(int i = 0; i < 100; i++)
  {
    if( i == pos1)
      cout << setw(3) << 'o' << " |";
    else if( i == pos2)
      cout << setw(3) << 'x' << " |";
    else
      cout << setw(3) << i << " |";
    
    if(i % 9 == 0)
      cout << "\n---------------------------------------------\n";
  }
}

Board::Board(int num_trans )
{
  srand(time(0));
  for(int i = 0; i < 100; i++)
    brd.push_back(i);

  int tstart, tend;
  random_shuffle(brd.begin(), brd.end());
  for(int i = 0; i < 15; i++)
  {
    tstart = brd.back();
    brd.pop_back();

    tend = brd.back();
    brd.pop_back();

    Transition t(tstart, tend);
    transitions.push_back(t);
  }
}