// card_trick.cpp: Denys Soroka
// Takes three digit input (ABC) and determines
// its three digits based on remainders of ABC, BCA and CAB
// and 11.

#include <iostream>

#define kInvalidInput -1

using namespace std;

/** Reads number, that was provided by customer and validates it.
  * Returns number itself or error statu code kInvalidInput */
int read_input(){
  cout << "Please, enter three digit number: ";
  
  int input;
  if (!(cin >> input) || input > 999 || input < 100) {
    cout << "Invalid input: only three digit numbers are allowed!" << endl;
    return kInvalidInput;
  }
  return input;
}

/** Returns even number less than 20, wich computed by adding 
  * given arguments and increasing (decreasing) result by 11. */
int get_normalized_sum(int a, int b) {
  int sum(a + b);
  if (sum % 2 == 0) {
    return sum;
  }
  
  return sum - 11 > 0 ? sum - 11: sum + 11;
}

int main() {
  int three_digit_number(read_input());
  
  if (three_digit_number == kInvalidInput) {
    return kInvalidInput;
  }
  
  cout << "Number is " << three_digit_number << endl;
  
  int a(three_digit_number/100);
  int temp(three_digit_number % 100);
  int b(temp/10);
  int c(three_digit_number % 10);

  cout << "Extracted A = " << a << ", B = " << b << ", C = " << c << endl;
  
  // compute remainders x = ABC % 11, y = BCA % 11 and z = CAB % 11
  int x(three_digit_number % 11);
  int y((b*100 + c*10 + a) % 11);
  int z((c*100 + a*10 + b) % 11);
  
  cout << "Computed X = " << x << ", Y = " << y << ", Z = " << z << endl;
  // compute X + Y, Y + Z and Z + X sums and make them even number < 20 
  // by adding or subtracting 11
  
  int x_y(get_normalized_sum(x, y));
  cout << "x_y = " << x_y << endl;
  if (x_y == 9) {
    cout << "X + Y resulted in 9" << endl;
    return 0;
  }
  
  int y_z(get_normalized_sum(y, z));
  cout << "y_z = " << y_z << endl;
  if (x_y == 9) {
    cout << "Y + Z resulted in 9" << endl;
    return 0;
  }
  
  int z_x(get_normalized_sum(z, x));
  cout << "z_x = " << z_x << endl;
  if (z_x == 9) {
    cout << "Z + X resulted in 9 " << endl;
    return 0;
  }
  
  cout << "Digits are: " << x_y / 2 << ", " << y_z / 2 << ", ";
  cout << z_x / 2 << endl;
  
  return 0;
}
