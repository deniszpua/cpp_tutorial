// perfect_squares.cpp: Denys Soroka
// Find three smallest numbers that are perfect squares and sum of 
// natural order  1, 2, .. N
#include <iostream>

#define kRootSearchStart 36
#define kNaturalOrderMaxSearchStart 50

using namespace std;

unsigned long natural_order_sum(long max) {
  return max * (max + 1) / 2;
}

unsigned long squared(long root) {
  return root * root;
}

int main() {
  // smallest two are given in excersise description: 36 and 1225
  // the latter is 35^2 and sum(0, .. 35)
  // since sum(0,..N) is N * (N+1)/2 = 0.5N^2 + 0.5N increases slower
  // for equation M^2 = 0.5N^2 + 0.5N, --> M < N
  // we'll need to test couple N for each N
  
  unsigned long root = kRootSearchStart;
  unsigned long natural_order_max = kNaturalOrderMaxSearchStart;
  unsigned long sum;
  unsigned long square;
  
  while (true) {
    sum = natural_order_sum(natural_order_max);
    square = squared(root);
    if (sum < square) {
      natural_order_max++;
    } else if (square < sum) {
      root++;
    } else {
      break;
    }

  }
  
  cout << "Found perfect square " << square << " of " << root;
  cout << ", that is also natural order sum up to " << natural_order_max << endl;
  
  return 0;
} 
