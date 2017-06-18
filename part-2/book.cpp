// book.cpp
#include <iostream>
#include "book.h"

#define kFlagStub     0 // 0B00
#define kRequiredFlag 1 // 0B01
#define kNewFlag      2 // 0B10

#define kHorizontalSeparator "**************************************************"

using namespace std;

Book* Book::createInstanceFromInput() {
  // Sample listing:
  // Please enter the book code: 1221
  //  single copy price: 69.95
  //  number on hand: 30
  //  prospective enrollment: 150
  //  1 for reqd/0 for optional: 1
  //  1 for new/0 for used: 0
  
  int book_code;
  cout << "Please enter the book code: ";
  cin >> book_code;
  
  double price;
  cout << " single copy price: ";
  cin >>  price;
  
  int number_on_hand;
  cout << " number on hand: ";
  cin >> number_on_hand;
  
  int course_prospective_enrollment;
  cout << " prospective enrollment: ";
  cin >> course_prospective_enrollment;
  
  cout << " 1 for reqd/0 for optional: ";
  int isRequired;
  cin >> isRequired;
  int properties_flag = (isRequired == 1) ? kFlagStub^kRequiredFlag : kFlagStub;
  
  cout << " 1 for new/0 for used: ";
  int isNew;
  cin >> isNew;
  properties_flag = (isNew == 1) ? properties_flag^kNewFlag : properties_flag;
  
  return new Book(book_code, price, number_on_hand, course_prospective_enrollment,
      properties_flag);

}

void Book::printStats() {
  // Example:
  // ***************************************************
  // Book: 1221
  // Price: $69.95
  // Inventory: 30
  // Enrollment: 150
  // 
  // This book is required and used.
  // ***************************************************
  // Need to order: 67
  // Total Cost: $4686.65
  // ***************************************************

  cout << "***************************************************" << endl;
  cout << "Book: " << _id << endl;
  cout << "Price: $" << _price_cents / 100.0 << endl;
  cout << "Inventory: " << _number_on_hand << endl;
  cout << "Enrollment: " << _course_prospective_enrollment << endl << endl;
  string requirement_desc = (_condition_flag&kRequiredFlag) == kRequiredFlag ? "required": "optional";
  string condition_desc = (_condition_flag&kNewFlag) == kNewFlag ? "new" : "used";
  cout << "This book is " << requirement_desc << " and " << condition_desc << endl;
  cout << "***************************************************" << endl;

  cout << "Need to order: " << _demand_forecast << endl;
  cout << "Total Cost: $" << _revenue_forecast_cents/100.0 << endl; 
  cout << kHorizontalSeparator << endl << endl;
}

unsigned long Book::getRevenueForecast() {
  return _revenue_forecast_cents;
}
