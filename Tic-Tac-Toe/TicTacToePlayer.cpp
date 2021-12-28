
//implementation file for the class that reppresents a player in the tic tac te game//includes an abstract class rom which we derive the specific computer payer class//and the specific user player class
#include "TicTacToePlayer.h"
 
void TicTacToePlayerPerson::make_move(TicTacToeBoard& board)
{

      int move;
      cout << "\nEnter your move: (0-8)";
      cin >> move;

      while( move < 0 || move > 8 )
      {
        cout << "\nThe number is out of range, please try again...";
        cin >> move;
      }
      while(board.is_open(move) == false)
      {
        cout << "\nThat position is invalid, try again...";
        cin >> move;
      }
      board[move] = ch;
}

 
void TicTacToePlayerPerson::choose_sym()
{
  char temp;
  cout << "\nChoose a symbol (x or o): ";
  cin >> temp;
  temp = tolower(temp);
  while (temp != 'x' && temp != 'o')
  {
    cout << "Please choose between x and o only: ";
    cin >> temp;
  }
  ch = temp;
}

bool TicTacToePlayerPerson::has_won(TicTacToeBoard& board)
{
  bool won = true;
  if(board.won( ch ))
    cout << "\nPlayer wins!";
  else if (board.is_full() )
    cout << "\nIt's a tie!";
  else
    won = false;
  return won;
}

bool TicTacToePlayerComputer::has_won(TicTacToeBoard& board)
{
  bool won = true;
  if(board.won( ch ))
    cout << "\nComputer wins!";
  else if (board.is_full() )
    cout << "\nIt's a tie!";
  else
    won = false;
  return won;
}

void TicTacToePlayerComputer::make_move(TicTacToeBoard& board)
{
  cout << "\nComputer makes its move...\n";
  char user;
  if(ch == 'x')
    user = 'o';
  else 
    user = 'x';
  //check if computer can win in the next step 
  for(int i = 0; i < 9; i++)
  {
    TicTacToeBoard extra;
    board.copy_board(extra);
    if(extra.is_open(i))
    {
      extra[i] = ch;
      if(extra.won(ch))
      {
        board[i] = ch;
        return;
      }
    }
  }
  //check if the user can win with any of the next moves
  for(int i = 0; i < 9; i++)
  {
    TicTacToeBoard extra;
    board.copy_board(extra);
    if(extra.is_open(i))
    {
      extra[i] = user;
      if(extra.won(user))
      {
        board[i] = ch;
        return;
      }
    }
  }

  int rand_num = board.get_rand_move();
  board[rand_num] = ch;
}

