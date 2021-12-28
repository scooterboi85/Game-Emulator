#include <iostream>
#include "Bagels.h"
using namespace std;
int main() {
  bool again = true;
  while(again)
  {
    Bagels game;
    game.show_descr();
    game.play();
    again = game.play_again();
  }
}