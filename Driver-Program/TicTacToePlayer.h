
//definitiln file for classes representing tic tac toe player (teh abstract class and teh two derived classes to represent the computer and the user )
#ifndef TICTACTOEPLAYER_H
#define TICTACTOEPLAYER_H
#include <iostream>
#include <cctype>
#include "TicTacToeBoard.h"
using namespace std;
class TicTacToePlayer
{
  protected:
    char ch;
  public:
    void set_char(char ch) {this->ch = ch;}
    char get_char() {return ch;}
    virtual void make_move(TicTacToeBoard&) = 0;
    virtual bool has_won(TicTacToeBoard&) = 0;
};

class TicTacToePlayerPerson : public TicTacToePlayer
{
  public:
    void choose_sym();
    void make_move(TicTacToeBoard&);
    bool has_won(TicTacToeBoard&);
};
class TicTacToePlayerComputer  : public TicTacToePlayer
{
  public:
    void make_move(TicTacToeBoard&);
    bool has_won(TicTacToeBoard&);
};
#endif

