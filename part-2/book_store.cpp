// book_store.cpp: Denys Soroka
// Counts forecast for books demand and profit
// based on purchase probability and retrospective demand predictions.
// Probability of purchase for new (not used before in class)
// is 90% for required and 40 for optional. For books, that were mentioned
// in class before probabilities are 65% and 20% respectively.
// Profit rate is 20% of gross revenue.
// Sample output:
/* 
    Please enter the book code: 1221
     single copy price: 69.95
     number on hand: 30
     prospective enrollment: 150
     1 for reqd/0 for optional: 1
     1 for new/0 for used: 0
    ***************************************************
    Book: 1221
    Price: $69.95
    Inventory: 30
    Enrollment: 150

    This book is required and used.
    ***************************************************
    Need to order: 67
    Total Cost: $4686.65
    ***************************************************

    Enter 1 to do another book, 0 to stop. 0
    ***************************************************
    Total for all orders: $4686.65
    Profit: $937.33
    ***************************************************
*/

#include <iostream>
#include "book.h"

#define kProfitRatePercentage 20
#define kHorizontalSeparator "**************************************************"

using namespace std;

/** Queries if operator wants to process more books and returs true if so
  * and false otherwise. */
bool isOtherItemToAdd();
/** Prints forecast for total revenue and profit, based on given input. */
void printTotalForecast(unsigned long revenue_cents, unsigned int profit_percentage);

int main() {
  unsigned long totalRevenueCents(0);
  
  // Get input data, print stats for that book and increment totalRevenue.
  // Than prompt for another book input
  while (true) {
    Book *book = Book::createInstanceFromInput();
    book->printStats();
    totalRevenueCents += book->getRevenueForecast();
    if (!isOtherItemToAdd()) {
      break;
    }
  }
  printTotalForecast(totalRevenueCents, kProfitRatePercentage);
  
  return 0;
}

void printTotalForecast(unsigned long revenue_cents, unsigned int profit_percentage) {
  cout << kHorizontalSeparator << endl;
  
  unsigned long dollarsAmount = revenue_cents / 100;
  unsigned short centsAmount = revenue_cents % 100;
  cout << "Total for all orders: $" << dollarsAmount << "." << centsAmount << endl;
  
  unsigned long dollarsProfit = revenue_cents * profit_percentage / (100 * 100);
  unsigned short centsProfit = (revenue_cents * profit_percentage / 100) % 100;
  cout << "Profit: $" << dollarsProfit << "." << centsProfit << endl;
  
  cout << kHorizontalSeparator << endl;
  
}

bool isOtherItemToAdd() {
  cout << "Enter 1 to do another book, 0 to stop.";
  int choice(0);
  cin >> choice;
  cout << endl;
  return choice == 1;
}
