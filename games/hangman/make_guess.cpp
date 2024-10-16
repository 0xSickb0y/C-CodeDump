#include <iostream>
#include "make_guess.hpp"
#include "char_exists.hpp"

void make_guess(std::map <char, bool>& chars_guessed, std::vector <char>& incorrect_guesses) {
   std::cout << "Your guess: ";
   char guess;
   std::cin >> guess;

   chars_guessed[guess] = true;

   if (!char_exists(guess)) {
      incorrect_guesses.push_back(guess);
   }
   std::cout << std::endl;
}