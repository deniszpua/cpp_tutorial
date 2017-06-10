// date_decoding.cpp: Denys Soroka
// reads encoded date from input and print it
// to stdout in form MMM [D]D, YYYY
// Decoding procedure: First symbol corresponds to month 
// (A-Z maps Jan-Dec), then each date symbol encoded using Q to Z 
// letters and last is year after 1995 (A to Z maps 1 to 26)
// E.g. ARZM is Jan 19, 2008
#include <iostream>
#include <string>

#define kInvalidInputStatusCode 42
#define kInputPrompt "Enter encoded date: "
#define kMonthes {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}
#define kJanSymbol 'A'
#define kMonthSymbolPosition 0
#define kZeroDaySymbol 'Q'
#define kFirstDaySymbolPosition 1
#define kShortStringTerminatorPosition 3 
#define k1996Symbol 'A'
#define kMaxYearSymbol 'Q'

using namespace std;

bool is_valid_month_symbol(char symbol) {
  // allowed range is [kJanSymbol .. kJanSymbol + 12)
  return  (kJanSymbol <= symbol)
          && (symbol < kJanSymbol + 12);
}

bool is_valid_year_symbol(char symbol) {
  // allowed range is [k1996Symbol .. kMaxYearSymbol]
  return (k1996Symbol <= symbol)
          && (symbol <= kMaxYearSymbol);
}

bool is_valid_day_symbol(char symbol) {
  // [kZeroDaySymbol .. kZeroDaySymbol + 10)
  return (kZeroDaySymbol <= symbol) && (symbol < kZeroDaySymbol + 10);
  
}

bool is_valid_input(string input_string){
  bool valid (is_valid_month_symbol(input_string[kMonthSymbolPosition]));
  valid = valid && is_valid_day_symbol(input_string[kMonthSymbolPosition + 1]);

  // rest is length-dependent
  if (input_string[kShortStringTerminatorPosition] == '\0') {
    return valid && is_valid_year_symbol(input_string[kShortStringTerminatorPosition - 1]);
  } 
  
  valid = valid && is_valid_day_symbol(input_string[kMonthSymbolPosition + 1]);
    
  return valid && is_valid_year_symbol(input_string[kShortStringTerminatorPosition]);
} 
                 
/** Returns number representation of encoded date. */
int decode_day(string date_encoded){
  int first_digit = date_encoded[kFirstDaySymbolPosition] - kZeroDaySymbol;
  // one- or two- digits days are possible
  // so we need to check date lenght by examiming symbol at pos 3
  if (date_encoded[kShortStringTerminatorPosition] == '\0') {
    return first_digit;
  }
  return first_digit * 10 
    + (date_encoded[kFirstDaySymbolPosition + 1] - kZeroDaySymbol);
}

/** Returns string representation of month (e.g. Jan). */
string decode_month(char month_encoded){
  string monthes[] = kMonthes;
  return monthes[month_encoded - kJanSymbol];
}

/** Returns decoded year value */
int decode_year(string date_encoded) {
  int yearSymbol;
  if (date_encoded[kShortStringTerminatorPosition] != '\0') {
    yearSymbol = date_encoded[kShortStringTerminatorPosition]; 
  } else {
    yearSymbol = date_encoded[kShortStringTerminatorPosition - 1];
  }
  return 1996 + yearSymbol - k1996Symbol;
}

int main(int argc, char const *argv[]) {
  
  cout << kInputPrompt;
  string date_encoded;
  
  cin >> date_encoded;
  
  if (!is_valid_input(date_encoded)) {
    cout << "Input is not valid encoded date: " << date_encoded << endl;
    return kInvalidInputStatusCode;
  }
  
  cout << "Decoded date is: " << decode_month(date_encoded[kMonthSymbolPosition]);
  cout << " " << decode_day(date_encoded) << ", ";
  cout << decode_year(date_encoded) << endl;

  return 0;
}
