#include <fstream>
#include <iostream>

#include "save_file.hpp"

void save_file(std::vector <std::string> new_list){
   std::ofstream file;
   file.open("wordlist.txt");
   if (file.is_open()) {
      file << new_list.size() << std::endl;
      for (std::string word : new_list) {
         file << word << std::endl;
      }
      file.close();
   }
   else {
      std::cout << "Can't access the file: wordlist.txt" << std::endl;
      exit(0);
   }
}