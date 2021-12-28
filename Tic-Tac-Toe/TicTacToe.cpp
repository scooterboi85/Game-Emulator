//impplementation file for teh class representing s game of tic-tac-toe
#include "TicTacToe.h"


void TicTacToe::display()
{
  this->board.draw_board();
}

void TicTacToe::show_descr()
{
  cout << "\nWelcome to TicTacToe against a computer";
  cout << "\nYour moves would be marked with a 'X', while the computer's - with an 'O'";
  cout << "\nFor your move, enter a number in the range (0-8) to select the desirable board cell\n";
  display();

}

TicTacToe::TicTacToe()
{
  p1.choose_sym();
  if(p1.get_char() == 'x')
    p2.set_char('o');
  else 
    p2.set_char('x');
  players.push_back(&p1);
  players.push_back(&p2);
}

void TicTacToe::play()
{
  int turn = 0;
  while(true)
  {
    players[turn%2]->make_move(board);
    display();
    if(players[turn%2]->has_won(board))
      break;
    turn += 1;
  }
}


