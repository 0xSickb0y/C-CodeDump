#include <string>
#include <vector>
#include <iostream>

#include "read_file.hpp"
#include "save_file.hpp"

void add_word() {
    std::string new_word;
    std::cout << "New word (lowercase): " << std::endl;
    std::cin >> new_word;

    std::vector <std::string> words_in_file = read_file();
    words_in_file.push_back(new_word);
    save_file(words_in_file);
}