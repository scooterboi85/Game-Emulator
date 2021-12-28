/*
The definitino file for the Bagels guessing game

*/
#include "BagelsGuess.h"

bool BagelsGuess::was_used(vector<string>& vect)
{
  for ( int i = 0; i < vect.size(); i++ )
    if (vect[i] == true_num)
      return true;
  return false;
}

bool BagelsGuess::has_duplicates()
{
  for(int i = 0; i < true_num.size(); i++)
    for (int j = 0; j < true_num.size(); j++)
      if( ( true_num[i] == true_num[j] ) && ( i != j ) )
        return true;
  return false;
}


bool BagelsGuess::valid_guess(vector<string>& past)
{
  if (true_num.size() != num_digits)
  {
    cout << "\nInvalid number of digits\n";
    return false;
  }
  else if(this->has_duplicates())
  {
    cout << "\nAll the digits of the numer should be unique\n";
    return false;
  }
  else if(was_used(past))
  {
    cout << "\nThis number has already been mentioned\n";
    return false;
  }
  return true;
}
