// book_shelf.cpp: Denys Soroka
// Computes number of possible vays to place 6 books on shelf.

#include <iostream>
using namespace std;

int combination_counter(int rearrangeble_items) {
  if (rearrangeble_items == 1)
    return 1;
  
  return rearrangeble_items * combination_counter(rearrangeble_items - 1);
}
/** Entry point */
int main() {
  cout << "Number of combinations: " << combination_counter(6) << endl;
  
  
}
