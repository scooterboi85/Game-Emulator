//implementation file for the class that represents a point on the map in the treasurehunt game

#include "Point.h"
#include <cmath>
bool Point::operator==(const Point & rhs) const
{
  return (row == rhs.get_row() && (col == rhs.get_col()));
} 

int Point::distance_between(Point& p)
{
  int row_diff = this->get_row() - p.get_row();
  int col_diff = this->get_col() - p.get_col(); 
  double dist = sqrt( row_diff * row_diff + col_diff * col_diff );
  return static_cast<int>(round(dist));
}