// get_input.cpp: Denys Soroka quux@ukr.net
// Description: a program demonstrates handling keyboard input
// using cin

#include <iostream>
using namespace std;

/** Entry point */
int main()
{
  int input_var = 0;
  
  do {
    cout << "Enter any number, -1 for exit" << endl;
    
    if (!(cin >> input_var)) {
      cout << "You've entered non-numeric symbol. Exiting..." << endl;
      break;
    }
    
    if (input_var != -1) {
      cout << "You've entered " << input_var << endl;
    }
  } while (input_var != -1);
  
  cout << "All done!" << endl;
  return 0;
}
