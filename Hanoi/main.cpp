#include <iostream>
#include "Hanoi.h"
int main() 
{
  bool again = true;
  while(again)
  {
    Hanoi game;
    game.show_descr();
    game.play();
    again = game.play_again();
  }
}