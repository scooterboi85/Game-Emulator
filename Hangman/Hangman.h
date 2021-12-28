//definition file lfor the class that represents the hangman game

#ifndef HANGMAN_H
#define HANGMAN_H 
#include "HangPlayer.h"
#include "HangBoard.h"
#include "WordGenerator.h"
#include "Game.h"
class Hangman : public Game
{
  private:
    string curr_word;
    HangBoard board;
    HangPlayer player;
  public:
    void set_graphics(vector<string>);
    bool check_if_over();
    void play();
    void display();
    void show_descr();
};

#endif