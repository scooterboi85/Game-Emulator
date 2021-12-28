#ifndef BOARD_H
#define BOARD_H
#include "transitions.h"
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
class Board
{
  private:
    vector<int> brd;
    vector<Transition> transitions;
  public:
    Board(int num_trans = NUM_TRANS);
    void print(int, int);
    friend class Player;
};
#endif