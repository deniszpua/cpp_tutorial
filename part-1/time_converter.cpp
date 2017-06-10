// time_converter.cpp: Denys Soroka
// takes number of seconds as input and prints number of days, hours, minutes
// and seconds that matches specified time interval
#include <iostream>

#define kSecondsInMinute 60
#define kMinutesInHour 60
#define kHoursInDay 24

using namespace std;

/** Prints prompt to std::out and reads input, that will be returned as a result.
    Returns -1 on error */
int get_input() {
  cout << "Please, enter time interval length in seconds: ";
  int result;
  if (cin >> result) {
    return result;
  }
  
  return -1;
}

/** Computes number of full days, that given time interval encloses.
    @param int seconds - time interval length, seconds */
int extract_days(int seconds) {
  return seconds / (kSecondsInMinute * kMinutesInHour * kHoursInDay);
  
}

/** Computes number of full days, that given time interval encloses.
    @param int seconds - time interval length, seconds */
int extract_hours(int seconds) {
  int day_remainder = seconds % (kSecondsInMinute * kMinutesInHour * kHoursInDay);
  return day_remainder / (kSecondsInMinute * kMinutesInHour);
  
}

/** Computes number of full days, that given time interval encloses.
    @param int seconds - time interval length, seconds */
int extract_minutes(int seconds) {
  int minutes_remainder =  seconds % (kSecondsInMinute * kMinutesInHour);
  return minutes_remainder / kSecondsInMinute;
  
}

int main() {
  // Take input 
  int interval_in_seconds = get_input();
  if (interval_in_seconds < 0) {
    cout << "Invalid input. Exiting..." << endl;
    return -1;
  }
  
  // Compute days
  cout << "Days: " << extract_days(interval_in_seconds) << endl;
  
  // Compute hours
  cout << "Hours: " << extract_hours(interval_in_seconds) << endl;
  
  // Compute minutes
  cout << "Minutes: " << extract_minutes(interval_in_seconds) << endl;
  
  // Computes seconds remainder
  cout << "Seconds: " << interval_in_seconds % 60 << endl;
  
  return 0;
}

