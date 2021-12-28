//implememntation file for the class that represents the player in the hangman game

#include "HangPlayer.h"

void HangPlayer::show_used_chars()
{
  cout << "\nUsed characters: ";
  for (int i = 0; i < used_chars.size(); i++)
     cout << used_chars[i] << " ";

}

bool HangPlayer::was_used(char c)
{
  for(int i = 0; i < used_chars.size(); i++)
    if (c == used_chars[i])
      return true;
  return false;
}

char HangPlayer::get_move()
{
  char ch;
  cout << "\n\nEnter your letter: ";
  cin >> ch;
  ch = tolower(ch);
  while(!isalpha(ch))
  {
    cout << "Please enter a letter: ";
    cin >> ch;
  }
  while(was_used(ch))
  {
      cout << "This letter has already been used, please enter another option: ";
      cin >> ch;
  }
  used_chars.push_back(ch);
  return ch;
}
