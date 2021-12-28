//iplementation file for the class that represents the hangman game

#include "Hangman.h"
#define NUM_LIVES 9
vector<string> nine_graphics = {
"\n======\n",
"\n         |\n"          
"         |\n"          
"         |\n"    
"      ======\n",
"\n+--------+\n"
"         |\n"          
"         |\n"          
"         |\n"    
"      ======\n",
"\n+--------+\n"
"     o   |\n"         
"         |\n"          
"         |\n"    
"      ======\n",                     
"\n+--------+\n"    
"     o   |\n"
"     |   |\n"
"         |\n"  
"       ======\n",
"\n+--------+\n" 
"   o     |\n"
"  /|     |\n" 
"         |\n"
"      ======\n",  
"\n+---------+\n"
"    o     |\n"
"   /|\\    |\n"
"          |\n"   
"       ======\n", 
"\n+---------+\n"
"     o    |\n"
"    /|\\   |\n"
"    /     |\n"
"       ======\n",
      
"\n+---------+\n"
"     o    |\n"
"    /|\\   |\n"
"    / \\   |\n"
"       ======\n" };


void Hangman::show_descr()
{
  cout << "\nWelcome to hangman!";
  cout << "In this word guessing game, you would need to guess a word letter by letter";
  cout << "\nHowever, you only have a limited number of tries to 'save' the hangman";
}

void Hangman::set_graphics(vector<string> pictures_p)
{
  for (int i = 0; i < pictures_p.size(); i++)
  {
    board.graphics.push_back(pictures_p[i]);
  }
}

void Hangman::display()
{
  board.display();
}

void Hangman::play()
{
  WordGenerator::load_words("words.txt");
  curr_word = WordGenerator::get_random_word();
  board.set_word(curr_word);
  board.curr_life = 0;
  set_graphics(nine_graphics);
  char curr;
  while(true)
  {
    display();
    if(check_if_over())
      break;
    player.show_used_chars();
    curr = player.get_move();
    if(board.in_word(curr))
    {
      cout << "\nYou guessed a letter! " << curr << " is in the word\n";
      board.update(curr);
    }
    else
    {
      cout << "\nThe letter " << curr << " is not in the word.";
      board.curr_life++;
    }
  }
}

bool Hangman::check_if_over()
{
  bool over = false;
  if(board.done())
  {
    cout << "\nCongratulations, you guessed the word " << curr_word;
    over = true;
  }
    
  if(board.curr_life ==
  
   NUM_LIVES - 1)
  {
    cout << "\nYou lost! The word was " << curr_word;
    over = true;
  }
  return over;
}
