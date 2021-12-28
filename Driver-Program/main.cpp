/*
Min Gahramanova U29579643
The driver program that allows to user to play any of the five offered brain - teaser games

*/
#include "Bagels.h"
#include "Hangman.h"
#include "Hanoi.h"
#include "TicTacToe.h"
#include "TreasureHunt.h"
using namespace std;

int main() 
{
  int choice;
  while (true)
  {
    cout << "Welcome to the mind-teaser games!\n";
    cout << "Here are the options:\n";
    cout << "1. Bagels (number-guessing game).\n";
    cout << "2. Hangman (word-guessing game).\n";
    cout << "3. TicTacToe.\n";
    cout << "4. Treasure Hunt.\n";
    cout << "5. Hanoi.\n";
    cout << "6. Exit.\n";
    cout << "Enter your choice: ";
    cin >> choice;
    if(choice == 1)
    {
      bool again = true;
      while(again)
      {
        Bagels game;
        game.show_descr();
        game.play();
        again = game.play_again();
      }
    }
    else if (choice == 2)
    {
      bool again = true;
      while(again)
      {
        Hangman game;
        game.show_descr();
        game.play();
        again = game.play_again();
      }

    }
    else if (choice == 3)
    {
      bool again = true;
      while(again)
      {
        TicTacToe game;
        game.show_descr();
        game.play();
        again = game.play_again();
      }
    }
    else if (choice == 4)
    {
      bool again = true;
      while(again)
      {
        TreasureHunt game;
        game.show_descr();
        game.play();
        again = game.play_again();
      }
    }
    else if (choice == 5)
    {
      Hanoi h;
      bool again = true;
      while(again)
      {
        Hanoi game;
        game.show_descr();
        game.play();
        again = game.play_again();
      }
    }
    else if (choice == 6)
    {
       cout << "\nBye!";
       break;
    }
    else 
    {
      cout << "\nThis is not a valid option, please re-enter.\n";
      continue;
    }
    
  }
}
