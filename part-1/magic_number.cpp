// magic_number.cpp: Denys Soroka
// modifies number, by adding its reversed form (vice-versa)
// and adding result's reversed form to result. E.g.:
//input number: 901
// reverse it: 109
// subtract: 901 - 109 = 792
// reverse it: 297
// add: 297 + 792 = 1089  

#include <iostream>
#include <string>

#define kErrorInvalidInput 5
#define kMaxStackArraySize 100

using namespace std;

/** Returns so called 'reversed' input, 
  * that is original number with digits 
  * in backwards order */
int get_reversed(int input) {
  string string_rep(to_string(input));
  int size = string_rep.length();
  char reversed_string[kMaxStackArraySize] = {};
  
  for (size_t i = 0; i < size; i++) {
    reversed_string[i] = string_rep[size - 1 - i];
  }
  return stoi(reversed_string);
}

int main() {
  cout << "Input number: ";
  
  int input_number;
  if (!(cin >> input_number)) { 
    cout << "Please, use only numeric input" << endl; 
    return kErrorInvalidInput;
  }
  
  int reversed = get_reversed(input_number);
  
  cout << "Reverse it: " << reversed << endl;
  
  int diff = input_number - reversed;
  
  cout << "Subtract : " << input_number << " - ";
  cout << reversed << " = " << diff << endl;
  
  int reversed_diff = get_reversed(diff);
  
  cout << "Reverse it " << reversed_diff << endl;
  
  cout << "add " << diff << " + " << reversed_diff;
  cout << " = " << diff + reversed_diff << endl;
  
  return 0;
}
