// greatest_common_divisor.cpp: Denys Soroka
// Program demonstrates Euclidian algorithm for calculation
// of greatest common divisor
#include <iostream>
using namespace std;
/** Computes greatest common divisor for to arguments */
int gcd(int bigger, int smaller) {
  
  // swap variables, if required
  int temp;
  if (bigger < smaller) {
    temp = bigger;
    bigger = smaller;
    smaller = temp;
  }
  
  while (smaller != 0) {
    temp = smaller;
    smaller = bigger % smaller;
    bigger = temp;
    
  }
  return bigger;
}

void test(int expected, int got, string name) {
  if (expected == got) {
    cout << "\t\tPassed: " << name << endl;
  } else {
    cout << "\tX\tFailed: " << name << ". Expected " << expected << ", got " << got << endl;
  }
}
/** Entry point */
int main() {
  // TODO
  test(2, gcd(6, 4), "GCD of 6 and 4");
  test(7, gcd(49, 42), "GCD of 42 and 49");
  test(1, gcd(0, 1), "GCD of 0 and 1");
  test(5, gcd(15, 40), "GCD of 15 and 40");
  test(1, gcd(37, 17), "GCD of 17 and 37");
  
}
