
/*
Implementatoin file for th eabstract game class
*/
#include "Game.h"
bool Game::play_again()
{
  char again;
  cout << "\nWould you like to play again? (y/n): ";
  cin >> again;
  again = tolower(again);
  while(again != 'y' && again != 'n')
  {
    cout << "\nPlease enter y or n only: ";
    cin >> again;
    again = tolower(again);
  }
  if(again == 'y')
    return true;
  else
    return false;
}
