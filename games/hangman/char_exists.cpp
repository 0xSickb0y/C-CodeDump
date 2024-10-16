#include <string>

extern std::string secret_word;

bool char_exists(char guess) {
   for (char i : secret_word) {
      if (guess == i){
         return true;
      }
   }
   return false;
}
