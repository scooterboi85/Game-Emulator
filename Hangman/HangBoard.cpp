#include "HangBoard.h"

bool HangBoard::done()
{
  for(int i = 0; i < word_so_far.size(); i++)
    if(word_so_far[i] == '-')
      return false;
  return true;
}

bool HangBoard::in_word(char c)
{
  bool is_in = false;
  for(int i = 0; i < total_word.size(); i++)
    if( total_word[i] == c)
      is_in = true;
  return is_in;
}

void HangBoard::set_word(string s)
{
  for(int i = 0; i < s.size(); i++)
  {
    total_word.push_back(s[i]);
    word_so_far.push_back('-');
  }
}

void HangBoard::update(char ch)
{
  for(int i = 0; i < total_word.size(); i++)
  {
    if (total_word[i] == ch)
      word_so_far[i] = ch;
  }
}



void HangBoard::display()
{
  cout << "\nWord so far: ";
  for(char c : word_so_far)
     cout << c;
  cout << "\nProgress: \n";
  cout << graphics[curr_life];
}