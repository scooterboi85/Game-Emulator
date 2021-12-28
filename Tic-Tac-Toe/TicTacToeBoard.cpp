//implementation file for the clas srepresenting the board in a tic-tac-toe game

#include "TicTacToeBoard.h"
char &TicTacToeBoard::operator[](int i) 
{
  try 
  { 
    return this->board[i];
  }
  catch (const std::out_of_range& oor)
  {
    cerr << "Out of Range error: " << oor.what() << '\n';
    return this->board[0];
  }         
}

TicTacToeBoard::TicTacToeBoard()
{
  for(int i = 0; i < 9; i++)
    board.push_back(' ');
}

bool TicTacToeBoard::won(char sym)
{
  
  bool win = false;
  if ( (board[0] == sym && board[1] == sym && board[2] == sym ) 
  ||   (board[3] == sym && board[4] == sym && board[5] == sym ) 
  ||   (board[6] == sym && board[7] == sym && board[8] == sym ) 
  ||   (board[0] == sym && board[3] == sym && board[6] == sym ) 
  ||   (board[1] == sym && board[4] == sym && board[7] == sym ) 
  ||   (board[2] == sym && board[5] == sym && board[8] == sym ) 
  ||   (board[0] == sym && board[4] == sym && board[8] == sym ) 
  ||   (board[2] == sym && board[4] == sym && board[6] == sym ) )
    win = true;
  return win;   
}

void TicTacToeBoard::copy_board( TicTacToeBoard& copy)
{
  for(int i = 0; i < 9; i++)
    copy.board[i] = this->board[i];
}

void TicTacToeBoard::clear()
{
  for(int i = 0; i < 9; i++)
    this->board[i] = ' ';
}

void TicTacToeBoard::draw_board( )
{
  char ch;
  cout << "\n\n- - - - -\n";
  for(int r = 0; r < 3; r++)
  {
    for(int c = 0; c < 3; c++)
    {
      cout << "|";
      if(this->board[r * 3 + c] == ' ')
        cout << r * 3 + c;
      else
        cout << this->board[r * 3 + c] ;
      cout << "|";
    }
    cout << "\n- - - - -\n";
  }
}

bool TicTacToeBoard::is_full(  )
{
  bool full = true;
  for(int i = 0; i < 9; i++)
    if(this->board[i] == ' ')
      full = false;
  return full;
}

int TicTacToeBoard::get_rand_move(  )
{
  srand(time(0));
  vector<int> rem;
  for(int i = 0; i < 9; i++)
    if(this->board[i] == ' ')
      rem.push_back(i);
  int ind = rand() % rem.size();
  return rem[ind];
}

bool TicTacToeBoard::is_open(int move)
{
  if(board[move] == ' ')
    return true;
  return false;
}
