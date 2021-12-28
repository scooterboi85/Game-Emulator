/*
Implementation for the Bagels Guess file
*/
#ifndef BAGELS_GUESS_H
#define BAGELS_GUESS_H
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

#define DIGITS 3
#define LIVES 10
class BagelsGuess
{
  private:
    string true_num; 
    int num_digits;
    bool was_used(vector<string>&);
    bool has_duplicates();
  public:
    BagelsGuess(string num_p, int num_digits_p = DIGITS) {true_num = num_p; num_digits = num_digits_p;}
    bool valid_guess(vector<string>&);
    friend class Bagels;
};

#endif