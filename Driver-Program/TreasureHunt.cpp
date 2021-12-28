//implementation file for the class representing the treasure hunt game

#include "TreasureHunt.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <iomanip>

TreasureHunt::TreasureHunt(int num_locators_p,int num_chests_p, int rows_p, int cols_p ) : board(rows_p, cols_p)
{
  num_locators = num_locators_p;
  num_chests = num_chests_p;
  rows = rows_p;
  cols = cols_p;
}

void TreasureHunt::display()
{
  board.draw_board();
}

void TreasureHunt::show_descr()
{
  cout << "\nWelcome to Treasure Hunt";
  cout << "\nThere are chests hidden on the map";;
  cout << "\nYou are provided with sonar devices that can be dropped anywhere" ;
  cout << "\nIf a sonar device is close enough to a chest (<10), the board will reflect the distance between the two";
  cout << "\nYour goal is to find all chests before running out of sonar devices";
}

Point TreasureHunt::get_move()
{
  int row,col;
  cout << "\nEnter row number: ";
  cin >> row;

  while(row >= rows || row < 0 )
  {
    cout << "\nPlease, re-enter row number in the appropriate range: ";
    cin >> row;
  }

  cout << "\nEnter column number: ";
  cin >> col;
    
  while(col >= cols || col < 0 )
  {
    cout << "\nPlease, re-enter column number in the appropriate range: ";
    cin >> col;
  }

  while(board.is_free(row, col) == false)
  {
    cout << "\nThis spot is taken; enter a different row number: ";
    cin >> row;
    cout << "\nEnter a different column number: ";
    cin >> col;
  }
  Point move(row, col);
  return move;
}

void TreasureHunt::mark_move(Point move)
{
  int shortest_dist = 100000;
  char symbol;
  for(Point chest: chests)
  {
    int dist = move.distance_between(chest);
    if(dist <= shortest_dist)
      shortest_dist = dist;
  }

  if(shortest_dist < 1)//if chest is found 
  {
    cout << "\nYou found a chest at row "<< move.get_row() << " and column " << move.get_col() << endl;
    symbol = 'x';//x marks chest
    num_chests--;
    chests.erase(find(chests.begin(), chests.end(), move)); 
  }
  else
  {
    cout << "\nNo hit! Currently, the closest chest is " << shortest_dist << " away.\n";
    symbol = (shortest_dist <= 10) ? static_cast<char>(shortest_dist + '0') : 'o';
  }
  board.mark(move, symbol);
  num_locators--;
}


void TreasureHunt::generate_chests()
{
  srand(time(0));
  vector<int> row_nums;
  vector<int> col_nums;
  for (int i = 0; i < board.get_num_rows(); i++)
    row_nums.push_back(i);
  for(int i = 0; i < board.get_num_cols(); i++)
    col_nums.push_back(i);
  random_shuffle(row_nums.begin(), row_nums.end());
  random_shuffle(col_nums.begin(), col_nums.end());
  //generate random chest positions 
  for(int i = 0; i < NUM_LOCATORS; i++)
  {
    Point temp;
    temp.set_row(row_nums.back());
    temp.set_col(col_nums.back());
    chests.push_back(temp);
    row_nums.pop_back();
    col_nums.pop_back();
  }
}

void TreasureHunt::play()
{
  generate_chests();
  while (true)
  {
    display();
    Point move = get_move();
    mark_move(move);
    if(check_if_done() == true)
      break;
  }
}


bool TreasureHunt::check_if_done()
{
  bool done = false;
  if (num_chests < 1)
  {
    cout << "\nCongratulations! You found all the lost treasure chests!";
    done = true;
  }
  else if (num_locators < 1)
  {
    cout << "\nOh no, you ran out of all the locator devices!";
    done = true;
  }
  return done;
}




