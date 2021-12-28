#include <iostream>
#include "Hangman.h"
int main() 
{
  bool again = true;
  while(again)
  {
    Hangman game;
    game.show_descr();
    game.play();
    again = game.play_again();
  }
}