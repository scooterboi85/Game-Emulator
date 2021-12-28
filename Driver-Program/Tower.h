//definition file for the class that represents a tower in teh Hnoi game
#ifndef TOWER_H
#define TOWER_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef char Disk;

class Tower
{
  private:
    Disk top;
    string disks;
    int count;
  public: 
    Tower( int count_p = 0);
    bool push(char);
    bool operator+=(Disk);
    char pop();
    char get_top() {return top;}
    int get_count() {return count; }
    void display();
};


#endif