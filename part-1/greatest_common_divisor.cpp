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

void find_solution_and_print() {
  
  // prices in cents
  int horse_price = 10*100;
  int pig_price = 3*100;
  int rabbit_price = 50;
  int animals_bought = 100;
  int budget = 100*100;
  // expected
  // horses: 0, pigs: 20 and rabbits 80
  // horses: 5, pigs: 1 and rabbits 94

  cout << "Hore costs " << horse_price/100.0 <<"$, pig: " << pig_price/100.0 <<"$, and rabbit: " << rabbit_price/100.0 << "$." << endl;
  // brute force
  for (int horses = 0; horses <= budget/horse_price; horses++) {
    for (int pigs = 0; pigs <= budget/pig_price; pigs++) {
      for (int rabbits = 0; rabbits <= budget/rabbit_price; rabbits++) {
        int total_price = horses * horse_price + pigs * pig_price + rabbits * rabbit_price;
        int total_number = horses + pigs + rabbits;
        if (total_price == budget && total_number == animals_bought) {
          cout << "Found horses: " << horses << ", pigs: " << pigs << " and rabbits " << rabbits << endl;
        }
      }
    }
  }
  
}

/** Entry point */
int main() {
  // TODO
  // test(2, gcd(6, 4), "GCD of 6 and 4");
  // test(7, gcd(49, 42), "GCD of 42 and 49");
  // test(1, gcd(0, 1), "GCD of 0 and 1");
  // test(5, gcd(15, 40), "GCD of 15 and 40");
  // test(1, gcd(37, 17), "GCD of 17 and 37");
  
  // combination puzzle
  find_solution_and_print();
}
