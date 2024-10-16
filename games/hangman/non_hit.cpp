#include "non_hit.hpp"

bool non_hit(std::string secret_word&, const std::map<char, bool>& chars_guessed) {
   for (char i : secret_word) {
      if (chars_guessed.find(i) == chars_guessed.end() || !chars_guessed.at(i)) {
         return true;
      }
   }
   return false;
}