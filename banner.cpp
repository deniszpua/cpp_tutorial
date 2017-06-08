// banner.cpp: Denys Soroka
// Prints input in column using ASCII graphic to increase font
#include <iostream>

#define kFGlyph "FFFFF\nF\nFFF\nF\nF"
#define kRGlyph "RRR\nR  R\nRRR\nR R\nR  R"
#define kEGlyph "EEEEE\nE\nEEE\nE\nEEEEE"
#define kZGlyph "ZZZZZ\n   Z\n  Z\n Z\nZZZZZ"
#define kYGlyph "Y   Y\n Y Y\n  Y\n  Y\n  Y"

using namespace std;

void print_letter(char symbol) {
  // cout << "Printing letter " << symbol << endl;
  cout << endl;

  switch (symbol) {
    case 'F':
      cout << kFGlyph << endl;
      return;
    case 'R':
      cout << kRGlyph << endl;
      return;
    case 'E':
      cout << kEGlyph << endl;
      return;
    case 'Z':
    cout << kZGlyph << endl;
      return;
    case 'Y':
      cout << kYGlyph << endl;
      return;
    default:
      cout << "Unexpected symbol " << symbol << endl;
      
  }
}

int main() {
  string input ("FREEZY");
  // iterate over string chars printing each symbol
  
  for (int i = 0; i < input.length(); i++) {
    print_letter(input[i]);
  }
  
}
