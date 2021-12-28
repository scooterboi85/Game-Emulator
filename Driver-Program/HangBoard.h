/*
Definition file fo rthe class that represents the hangman board
*/

#ifndef HANGBOARD_H
#define HANGBOARD_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class HangBoard
{
  private: 
    vector<char> total_word;
    vector<char> word_so_far;
    vector<string> graphics;
    int curr_life;
  public:
    void display();
    void set_word(string s);
    void update(char c);
    bool in_word(char c);
    bool done();
    friend class Hangman;
};

#endif
