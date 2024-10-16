#include <fstream>
#include <iostream>

#include "read_file.hpp"

std::vector <std::string> read_file() {
   std::ifstream file;
   file.open("wordlist.txt");

   if (file.is_open()) {
      int total_words;
      file >> total_words;

      std::vector <std::string> words_in_file;

      for (int i=0; i<total_words; i++) {
         std::string word_read;
         file >> word_read;
         words_in_file.push_back(word_read);
      }
      file.close();
      return words_in_file;
   }

   else {
      std::cout << "Can't access the file: wordlist.txt" << std::endl;
      exit(0);
   }
}