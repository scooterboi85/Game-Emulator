/*
Header file for the bagels class.
This class is an accumulation of all the constituent parts of the game
*/
#ifndef BAGELS_H
#define BAGELS_H
#include "BagelsGuess.h"
#include "Game.h"
class Bagels : public Game
{
  private:
    vector<string>clues;
    string curr_num;
    int curr_life;
    int digits;

  public:
    Bagels(int digits_p = DIGITS) {digits = digits_p;}
    void gen_number();
    void get_clues(BagelsGuess&);
    bool check_end(BagelsGuess&);
    //virtal functions that need overloading
    void play();
    void display();
    void show_descr();
};
#endif 