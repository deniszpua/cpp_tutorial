// card_trick.cpp: Denys Soroka
// Takes three digit input (ABC) and determines
// its three digits based on remainders of ABC, BCA and CAB
// and 11.

#include <iostream>

#define kInvalidInputStatusCode 7

using namespace std;

int main() {
  cout << "Please, enter three digit number: ";
  
  unsigned int input;
  if (!(cin >> input) || input > 999 || input < 100) {
    cout << "Invalid input: only three digit numbers are allowed!" << endl;
    return kInvalidInputStatusCode;
  }
}
