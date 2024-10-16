#include <iostream>
#include "print_errors.hpp"

void print_errors(const std::vector <char>& incorrect_guesses) {
   std::cout << "Incorrect guesses: ";
   for (char i: incorrect_guesses){
      std::cout << i << " ";
   }
   std::cout << std::endl;
}
