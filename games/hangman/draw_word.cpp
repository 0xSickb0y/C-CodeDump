#include <vector>

#include "read_file.hpp"

std::string draw_word() {
   std::vector <std::string> words = read_file();

   srand(time(NULL));
   int drawn_index = rand() % words.size();

   return words[drawn_index];
}