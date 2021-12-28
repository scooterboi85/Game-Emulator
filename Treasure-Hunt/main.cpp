#include <iostream>
#include "TreasureHunt.h"
int main()
{
  bool again = true;
  while(again)
  {
    TreasureHunt game;
    game.show_descr();
    game.play();
    again = game.play_again();
  }
}