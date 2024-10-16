#include <iostream>
#include "print_word.hpp"

void print_word(std::string secret_word, const std::map <char, bool> chars_guessed) {
   for (char i : secret_word) {
      if (chars_guessed.find(i) == chars_guessed.end() || chars_guessed.at(i)) {
         std::cout << i << " ";
      } else {
         std::cout << "_ ";
      }
   }
   std::cout << "\n" << std::endl;
}