
//definition file for representing a point in the treasure hunt game

#ifndef POINT_H
#define POINT_H
class Point
{
  private:
    int row;
    int col;
  public:
    Point(int row_p = 0, int col_p = 0 ) {row = row_p; col = col_p;}
    int get_row() const {return row;}
    int get_col() const {return col;}
    void set_row(int row_p) { row = row_p;}
    void set_col(int col_p)  { col = col_p; }
    int distance_between(Point& p);
    bool operator==( const Point & ) const;
};
#endif