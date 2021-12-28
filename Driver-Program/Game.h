
/*
Definition file for the Game abstract class
*/
#ifndef GAME_H
#define GAME_H
#include <iostream>
using namespace std;
class Game
{
  public:
  //pure virtual functions to be overloaded in child classes
    virtual void play() = 0;
    virtual void display() = 0;
    virtual void show_descr() = 0;
    bool play_again();
};
#endif