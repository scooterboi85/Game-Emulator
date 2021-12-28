/*
definition for the class that represents a game of tower of hanoi
*/

#ifndef HANOI_H
#define HANOI_H
#include "Tower.h"
#include "Game.h"
#include <vector>
#include <string>
#define NUM_TOWERS 3
class Hanoi : public Game
{
  private: 
     int num_disks;
     Tower towers[NUM_TOWERS];
  public:
    Hanoi();
    int get_to(int);
    int get_from(); 
    bool check_wins();
    bool check_move(int to, int from);
    //overloaded virtual functions
    void play();
    void display();
    void show_descr();
};
#endif