#include <iostream>
#include "player.h"
#include "board.h"
using namespace std;

int main()
{
  Player p1('o');
  Player p2('x');
  char roll_again;
  Board brd;
  brd.print(0,0);
  cout<< "\nYou starting off at position 0.";
  while(true)
  {
    cout << "\nPlayer 1 - press o to roll dice: ";
    cin >> roll_again;
    while(roll_again != 'o')
    {
      cout << "\nEnter o to roll: ";
      cin >> roll_again;
    }
    p1.move(brd);
    brd.print(p1.get_pos(), p2.get_pos());
    if(p1.won())
    {
      cout << "\nPlayer 1 wins!";
      break;
    }

    cout << "\nPlayer 2 - press x to roll dice: ";
    cin >> roll_again;
    while(roll_again != 'x')
    {
      cout << "\nEnter x to roll: ";
      cin >> roll_again;
    }
    p2.move(brd);
    brd.print(p1.get_pos(), p2.get_pos());
    if(p2.won())
    {
      cout << "\nPlayer 2 wins!";
      break;
    }
  }//end game loop
}//end main