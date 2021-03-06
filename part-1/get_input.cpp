// get_input.cpp: Denys Soroka
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
      cout << "You've entered non-numeric symbol. Resetting..." << endl;
      if (cin.fail()){
        cin.clear();
      }

      cin.ignore(1000, '\n');
      continue;
    }
    
    if (input_var != -1) {
      cout << "You've entered " << input_var << endl;
    }
  } while (input_var != -1);
  
  cout << "All done!" << endl;
  return 0;
}
