//implementation file for the word generator class
//which reads in a file of words and picks one at random
#include "WordGenerator.h"
#include <fstream>
vector<string> WordGenerator::words;

void WordGenerator::load_words(string fname)
{
  srand(time(0));
  fstream file;
  file.open(fname);
  string curr_word;
  while(file >> curr_word)
    words.push_back(curr_word);
}
string WordGenerator::get_random_word()
{
  int ind = rand() % words.size();
  string temp =  words[ind];
  words.erase(words.begin() + ind);
  return temp;
}
