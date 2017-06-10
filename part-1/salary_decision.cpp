// salary_decision.cpp: Denys Soroka
// Helps determine best salary options
#include <iostream>
using namespace std;

// constants
#define kComissionRateForMethod2 0.1
#define kComissionRateForMethod3 0.2
#define kComissionPerPairMethod3 20
#define kWeeklyAmountMethod1 600
#define kHourlyRateMethod2 7
#define kHoursPerWeek 40
#define kPairPrice 225.0

/** Reads weekly sales from stdin and returns its value */
int GetInput(){
  cout << "Please enter weely sales amount ($): ";
  int result = -1;
  while (result < 0){
    if (cin >> result) {
      return result;
    } else {
      cout << "Invalid input, use numbers only" << endl;
      if (cin.fail()) {
        cin.clear();
      }
      cin.ignore(1000, '\n');
    }
  }
  return -1;
}

void CalcMethod1() {
  cout << "Method 1: " << kWeeklyAmountMethod1 << endl;
}

void CalcMethod2(int pairs_sold_per_week) {
  double amount =  kHoursPerWeek * kHourlyRateMethod2 + pairs_sold_per_week * kPairPrice * kComissionRateForMethod2;
  cout << "Method 2: " << amount << endl;
}

void CalcMethod3(int pairs_sold_per_week) {
  // stub
  int weekly_sales = pairs_sold_per_week * kPairPrice;
  double result =  kComissionRateForMethod3 * weekly_sales + pairs_sold_per_week * kComissionPerPairMethod3;
  cout << "Method 3: " << result << endl;
}

/** Entry point */
int main(int argc, char const *argv[]) {
  
  int pairs_sold_per_week = 0;
  pairs_sold_per_week = GetInput();
  CalcMethod1();
  CalcMethod2(pairs_sold_per_week);
  CalcMethod3(pairs_sold_per_week);
  
  return 0;
}
