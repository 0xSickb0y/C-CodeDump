#include <map>
#include <string>
#include <vector>
#include <iostream>

#include "banner.hpp"
#include "non_hit.hpp"
#include "add_word.hpp"
#include "draw_word.hpp"
#include "read_file.hpp"
#include "save_file.hpp"
#include "make_guess.hpp"
#include "print_word.hpp"
#include "char_exists.hpp"
#include "print_errors.hpp"

using namespace std;

string secret_word;

map <char, bool> chars_guessed;
vector <char> incorrect_guesses;

int main() {

   banner();
   secret_word = draw_word();

   while (non_hit(secret_word, chars_guessed) && incorrect_guesses.size() < 5) {
      
      print_word(secret_word, chars_guessed);
      print_errors(incorrect_guesses);
      make_guess(chars_guessed, incorrect_guesses);
   }

   if (non_hit(secret_word, chars_guessed)) {
      cout << "Game Over, the secret word was: " << secret_word << endl;
   } else {
      cout << "You won!" << endl;
      cout << "Do you want to add a new word to the game? (Y/n)" << endl;

      bool answered;

      while (!answered){
         string answer;
         cin >> answer;

         if (answer == "Y" || answer == "y") {
            add_word();
            answered = true;
         }
         else if (answer == "N" || answer == "n"){
            answered = true;
            exit(0);
         }
         else {
            cout << "Y/n only." << endl;
         }
      } 
   }
}