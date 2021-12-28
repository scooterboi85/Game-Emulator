#include <iostream>
#include "TicTacToe.h"
int main() 
{
  bool again = true;
  while(again)
  {
    TicTacToe game;
    game.show_descr();
    game.play();
    again = game.play_again();
  }
}