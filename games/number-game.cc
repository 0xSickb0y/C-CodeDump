#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {

   cout << "***************************************" << endl;
   cout << "                BANNER                 " << endl;
   cout << "***************************************" << endl;
   
   int difficulty;
   int max_guesses;

   cout << "Choose your difficulty level: " << endl;
   cout << "Easy (0) | Medium (1) | Hard (2)" << endl;

   cin >> difficulty;

   if (difficulty == 0) {
      max_guesses = 15;
   } 

   else if (difficulty == 1) {
      max_guesses = 10;

   }

   else {
      max_guesses = 5;
   }

   int guess_count = 0;
   bool non_hit = true;
   double score = 1000.0;

   srand(time(NULL));
   const int SECRET_NUMBER = rand() % 100;

   for (guess_count = 1; guess_count <= max_guesses; guess_count++) {

      int guess;
      
      cout << ">>> ";
      cin >> guess;

      double lost_points = abs(guess - SECRET_NUMBER)/2.0;
      score = score - lost_points;

      bool higher = guess > SECRET_NUMBER;
      bool jackpot = guess == SECRET_NUMBER;

      if (jackpot) {
        cout << "jackpot!\n" << endl;
        non_hit = false;
        break;
      }

      else if (higher) {
        cout << "higher\n" << endl;
      }

      else {
        cout << "lower\n" << endl;
      }
   }
   
   cout << "End of game!" << endl;

   if (non_hit) {
      cout << "You lost, try again." << endl;
   }

   else {
      cout << "You guessed in " << guess_count << " tries" << endl;

      cout.precision(2);
      cout << fixed;
      cout << "Your score was " << score << " points." << endl;
   }
}
