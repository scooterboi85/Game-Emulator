
//definition file for the wordgeneraor class//shich is used to generate a random word for the hangman game
//by reading from a file containing a list of words 
#ifndef WORDGENERATOR_H
#define WORDGENERATOR_H
#include <stdlib.h>     
#include <time.h>
#include <vector>
#include <string>
using namespace std;
class WordGenerator
{
  private:
     static vector<string> words;
  public:
     static void load_words(string filename);
     static string get_random_word();
};
#endif