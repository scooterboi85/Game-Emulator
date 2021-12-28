//definition file for teh class that represent a game of tic tac toe
#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "TicTacToePlayer.h"
#include "TicTacToeBoard.h"
#include "Game.h"
class TicTacToe : public Game
{
  private: 
    TicTacToePlayerPerson p1;
    TicTacToePlayerComputer p2;
    vector<TicTacToePlayer* >players;
    TicTacToeBoard board;
  public: 
    TicTacToe();
    void play();
    void display();
    void show_descr();
};
#endif