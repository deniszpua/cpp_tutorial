// temp.cpp: Denys Soroka
// Description: a program that prints the immortal saying "Hello World"
// and demonstrates some output formatting flags

#include <iostream>
using namespace std;

/** Main docstring */
int main()
{
  cout.setf(ios::left);
  for (size_t line = 0; line < 6; line++) {
    for (size_t i = 0; i < 4; i++) {
      cout.width(17);
      cout << "Hello World!";
      
    }
    cout << endl;
  }
  return 0;
}
