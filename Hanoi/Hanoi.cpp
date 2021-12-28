//Implementation file for the class that represents a game of Tower of Hanoi

#include "Hanoi.h"

void Hanoi::show_descr()
{
  cout << "\nIn this classic puzzle, you are presented with three rods and a number of disks";
  cout << "\nYou start off with all rods being mounted on the first tower";
  cout << "\nThe goal is to move all disks from the first rod to third one";
  cout << "\nThe caveat is that you can only use one disk at a time";
  cout << "\nYou also cannot place a larger disk on top of a smaller one";
  cout << "\nIn this graphic representation, smaller disks are labeled with letters that come earlier in the aphabet (i.e.Diask A is smaller tahn disk B).";
}
Hanoi::Hanoi()
{
  cout << "\nEnter the desired number of disks: ";
  cin >> num_disks;
  Tower t1(num_disks), t2, t3;
  towers[0] = t1;
  towers[1] = t2;
  towers[2] = t3;
}

int Hanoi::get_from()
{
  int from;
  cout << "\nEnter from tower (1,2, or 3): ";
  cin >> from;
  while( from < 1 || from > 3 )
  { 
    cout << "\nInput out of range, please re-enter: ";
    cin >> from; 
    while (towers[from-1].get_count() == 0)
    {
      cout << "\nNo disks on this pole. Please re-enter: ";
      cin >> from;
    }
  }
  return from;
}

int Hanoi::get_to(int from)
{
  int to;
  cout << "\nEnter to tower (1,2, or 3): ";
  cin >> to;
  while( to < 1 || to > 3 )
  {
    cout << "\nOut-of-range, please re-enter: ";
    cin >> to;
  }
  while(to == from)
  {
    cout << "\nCan't pick the same tower as source. Pease re-enter: ";
    cin >> to;
  }
  return to;
}



bool Hanoi::check_move(int from, int to)
{
  bool valid = false;
  Disk temp = towers[from-1].pop();
  Disk to_top =  towers[to-1].get_top();
  if(temp < to_top || to_top == 'X')
  {
    towers[to-1] += (temp);
    cout << "\nMoved disk " << temp << " from tower " << from << " to tower " << to;
    valid = true;
  }
  else
  {
    cout << "\nCan't push a larger block atop of a smaller one.";
    towers[from -1 ] += (temp);
  }
  return valid;
}

void Hanoi::display()
{
  for(int i = 0; i < 3; i++)
    towers[i].display();
}

bool Hanoi::check_wins()
{
  bool won = false;
  cout << "\nTower 3 size: " << towers[2].get_count();
  cout << "\nNum disks: " << num_disks;
  if (towers[2].get_count() == this->num_disks )
  {
    cout << "\nYou won!\n";
    won = true;
  }
  return won;
}
void Hanoi::play()
{ 
  int from, to;
  this->display();
  while(true)
  {
    from = this->get_from();
    to = this->get_to(from);
    if(!this->check_move(from, to))
      continue;
    this->display();
    if(this->check_wins())
      break;
  }//end game loop
} 