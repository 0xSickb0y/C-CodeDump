#include <map>
#include <ctime>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

string secret_word;

map <char, bool> chars_guessed;
vector <char> incorrect_guesses;

void banner() {
   cout << "HANGMAN GAME" << endl;
   cout << "________" << endl;
   cout << "|      |" << endl;
   cout << "|      o" << endl;
   cout << "|     /|\\" << endl;
   cout << "|     / \\" << endl;
   cout << "|" << endl;
}

vector <string> read_file() {
   ifstream file;
   file.open("wordlist.txt");

   if (file.is_open()) {
      int total_words;
      file >> total_words;

      vector <string> words_in_file;

      for (int i=0; i<total_words; i++) {
         string word_read;
         file >> word_read;
         words_in_file.push_back(word_read);
      }
      file.close();
      return words_in_file;
   }

   else {
      cout << "Can't access the file: wordlist.txt" << endl;
      exit(0);
   }
}

void save_file(vector <string> new_list){
   ofstream file;
   file.open("wordlist.txt");
   if (file.is_open()) {
      file << new_list.size() << endl;
      for (string word : new_list) {
         file << word << endl;
      }
      file.close();
   }
   else {
      cout << "Can't access the file: wordlist.txt" << endl;
      exit(0);
   }
}

void draw_word() {
   vector <string> words = read_file();

   srand(time(NULL));
   int drawn_index = rand() % words.size();

   secret_word = words[drawn_index];
}

void add_word() {
    string new_word;
    cout << "New word (lowercase): " << endl;
    cin >> new_word;

    vector <string> words_in_file = read_file();
    words_in_file.push_back(new_word);
    save_file(words_in_file);
}

bool non_hit(){
   for (char i : secret_word){
      if (!chars_guessed[i]){
         return true;
      }
   }
   return false;
}

bool non_hanged(){
   return incorrect_guesses.size() < 5;
}

bool char_exists(char guess) {
   for (char i : secret_word) {
      if (guess == i){
         return true;
      }
   }
   return false;
}

void print_word(){
   for (char i : secret_word) {
      if (chars_guessed[i]) {
         cout << i << " ";
      } else {
         cout << "_ ";
      }
   }
   cout << "\n" << endl;
}

void print_errors(){
   cout << "Incorrect guesses: ";
   for (char i: incorrect_guesses){
      cout << i << " ";
   }
   cout << endl;
}

void make_guess() {
   cout << "Your guess: ";
   char guess;
   cin >> guess;

   chars_guessed[guess] = true;

   if (!char_exists(guess)) {
      incorrect_guesses.push_back(guess);
   }
   cout << endl;
}

int main() {

   banner();
   read_file();
   draw_word();

   while (non_hit() && non_hanged()) {
      
      print_word();
      print_errors();
      make_guess();
   }

   if (non_hit()) {
      cout << "Game Over, the secret word was: " << secret_word << endl;
   } else {
      cout << "You won!" << endl;
      cout << "Do you want to add a new word to the game? (Y/n)" << endl;

      bool answered;

      while (!answered){
         string answer;
         cin >> answer;

         if (answer == "Y" || answer == "y" ||) {
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
