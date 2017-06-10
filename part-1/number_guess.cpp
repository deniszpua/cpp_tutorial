// number_guess.cpp: Denys Soroka
// Description: program implements random number guess game

#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

/** Entry point */
int main() {
  
  // Init random number with seed
  srand(time(NULL));
  int generated_number = rand() % 100;
  
  // Prompt for input and read it safely
  cout << "Guess random number from 0 to 99" << endl;
  int guess;
  int attempt = 1;
  
  while (true) {
    cout << "Attempt No " << attempt << endl;
  
    if (cin >> guess) {
      if (guess != generated_number) {
        bool need_go_higher = guess < generated_number;
        cout << "You missed. Try " << (need_go_higher?"higher":"lower") << " value" << endl;
        attempt++;
  
      } else {
        cout << "You win!" << endl;
        return 0;
      }

    } else {
      cout << "Incorrect input" << endl;
      if (cin.fail()) {
        cin.clear();
      }
      cin.ignore(1000, '\n');
    }
  }
}
