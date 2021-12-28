/*
Implementaion file for the Bagles game
*/

#include "Bagels.h"

void Bagels::show_descr()
{
  cout << "\nWelcome to Bagels, a number guessing game!";
  cout << "\nThe computer would generate a random 3-digit number";
  cout << "\nThe number consists of unique digits";
  cout << "\nWith Each one of the guesses, you would be given a number of clues";
  cout << "\nIf a digit was guessed in the same position, you get the clue 'Fermi'";
  cout << "\nIf a digit is guessed, but in the wrong position, the clue is 'Pico";
  cout << "If neither are satisfied, the clue is Bagels\n\n";
}

bool is_in(char ch, string s)
{
  for ( int i = 0; i < s.size(); i++ )
    if (s[i] == ch)
      return true;
  return false;
}

void Bagels::gen_number()
{
  srand(time(0));
  curr_num = "";
  int ind;
  vector<char> digits;
  for(int i = 0; i < 10; i++)
    digits.push_back(i + '0');
  random_shuffle(digits.begin(), digits.end());
  for (int i = 0; i < DIGITS; i++)
  {
    curr_num += digits.back();
    digits.pop_back();
  }
}

void Bagels::get_clues(BagelsGuess& guess)
{
  for(int i = 0; i < guess.true_num.size(); i++)
  {
    if( guess.true_num[i] == curr_num[i] )
      clues.push_back( "Fermi" );
    else if ( is_in(guess.true_num[i], curr_num) )
      clues.push_back( "Pico" );
  }
  if(clues.size() == 0)
    clues.push_back( "Bagels" );
}

void Bagels::display()
{
  cout << "\nClues: ";
  for(auto s : clues)
    cout << s << endl;
}

bool Bagels::check_end(BagelsGuess& guess)
{
  if(guess.true_num == curr_num)
  {
    cout << "\nYou guessed the number!";
    return true;
  }
  else if (curr_life < 1)
  {
    cout << "\nYou ran out of lives! The number was " << curr_num;
    return true;
  }
  return false;
}

void Bagels::play()
{
  int lives = LIVES;
  string num;
  gen_number();
  vector<string> past_guesses;
  while (true)
  {
    clues.clear();
    cout << "\nEnter a " << digits << "-digit number: ";
    cin >> num;
    BagelsGuess guess(num, digits);
    while( guess.valid_guess(past_guesses) == false )
    {
      cout << "\nRe-enter your guess: ";
      cin >> num;
      guess.true_num = num;
    }
    past_guesses.push_back(guess.true_num);
    get_clues(guess);
    cout <<"\n-------------------------\n";
    display();
    lives -= 1;
    if(guess.true_num == curr_num)
    {
      cout << "\nYou guessed the number!";
      break;
    }
    else if (lives < 1)
    {
      cout << "\nYou ran out of lives! The number was " << curr_num;
      break;
    }
  }
}
