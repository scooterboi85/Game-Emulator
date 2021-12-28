#include "player.h"

void Player::move(Board& b)
{
  curr_pos += roll();
  for(auto t : b.transitions)
  {
    if(curr_pos == t.start)
    {
      cout << "You stumbled upon a ";
      cout << ( (t.type == SNEK) ? "snek " : "ladder " );
      cout << "and moved to the position " << t.end << endl;
      curr_pos = t.end;
    }
  }
}

