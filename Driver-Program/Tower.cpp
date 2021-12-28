//implementatino file for teh class representing a tower in the hanoi game

#include "Tower.h"

Tower::Tower(int count_p ) 
{ 
  count = count_p;
  if(count >= 1)
  {
    for( int i = count - 1; i >= 0; i-- )
      disks += 'A' + i;
    count = disks.size();
    top = disks[count - 1];
  }
  else
  {
    top = 'X';//x denotes empty tower
    disks = "";
  }
}

bool Tower::push(Disk d)
{
  if(top == 'X' || d < top)
  {
    top = d;
    disks += d;
    count++;
    return true;
  }
  else
  {
    cout << "\nCan't place a larger slab on top.\n";
    return false;
  }
}

Disk Tower::pop()
{
  //if there is nothing on rod
  Disk temp;
  if (count < 1)
  {
    return 'X';
  }
  else if(count == 1)
  {
    temp = top;
    top = 'X';
    disks = "";
  }
  else
  {
    temp = disks[count - 1];
    disks = disks.substr(0, count - 1);
    top = disks[count - 2];
  }
  count--;
  return temp;
}

void Tower::display()
{
  cout << "\n-----------------------\n";
  for(int i = 0; i < disks.size(); i++)
    cout << disks[i] << " ";
  cout << "\n-----------------------";
}

bool Tower::operator+=(Disk d)
{
  return this->push(d);
}