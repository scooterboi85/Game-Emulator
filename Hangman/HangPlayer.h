//definition file for the class that represents the player in the hangman game

#ifndef HANGPLAYER_H
#define HANGPLAYER_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class HangPlayer
{
  private:
    vector<char> used_chars;
    int max_tries;
    int curr_try;
  public:
    HangPlayer(int max_tries_p = 9) {max_tries = max_tries_p; curr_try = 0;}
    int get_max_tries() {return max_tries;}
    char get_move();
    int get_curr_try() {return curr_try;}
    bool was_used(char);
    void incr_try() {curr_try++;}
    void show_used_chars();

};
#endif 


