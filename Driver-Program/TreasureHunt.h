
//edclaration file for the class representing a treasure hunt game
#ifndef TREASUREHUNT_H
#define TREASUREHUNT_H
#include <vector>
#include <iostream>
#include "Point.h"
#include "TreasureBoard.h"
#include "Game.h"
#define NUM_LOCATORS 15
using namespace std;
class TreasureHunt : public Game
{
  private:
    TreasureBoard board;
    vector<Point> chests; 
    int num_chests;
    int rows;
    int cols;
    int num_locators;
  public:
    TreasureHunt(int num_locators_p = NUM_LOCATORS, int num_chests_p = NUM_LOCATORS, int rows_p = ROWS, int cols_p = COLS);
    void generate_chests();
    Point get_move();
    void mark_move(Point);
    bool check_if_done();
    void play();
    void display();
    void show_descr();
};
#endif