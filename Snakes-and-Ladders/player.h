#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "board.h"


class Player
{
  private:
    char sym;
    int curr_pos;
  public:
    Player(char sym_p) { curr_pos = 0; sym = sym_p; }
    void move(Board&);
    int roll(){return rand() % 6;}
    int get_pos() {return curr_pos;}
    bool won() { return (curr_pos >= 100) ? true : false; }
};

#endif