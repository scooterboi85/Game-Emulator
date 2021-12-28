#ifndef TRANSITION_H
#define TRANSITION_H
#define NUM_TRANS 12

enum Type {SNEK, LADDER};
struct Transition 
{
  Type type;
  int start, end;
  Transition(int s = 0, int e = 0)
  {
    start = s;
    end = e;
    if ( start < end )
      type = LADDER;
    else
      type = SNEK;
  }
};


#endif 