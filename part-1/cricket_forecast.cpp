// cricket_forecast.cpp: Denys Soroka
// Computes current temperature, based on cricket chirp rate
// using formula T = (cricket_chirp_rate + 40) / 4
#include <iostream>

#define kChirpRateDenominator 4.0
#define kChirpRateIncrementor 40

using namespace std;

/** Entry point */
int main() {
  
  cout << "Enter number of time cricket chirp during one minute: ";
  int chirp_rate;
  if (cin >> chirp_rate) {
    double temperature = (chirp_rate + kChirpRateIncrementor) / kChirpRateDenominator;
    cout << "Computed temperature is " << temperature << " degrees." << endl;
  } else {
    cout << "Invalid input" << endl;
    return 1;
  }
  return 0;
}
