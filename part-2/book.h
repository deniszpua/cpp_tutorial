// book.h: Denys Soroka
// Class represents book store item

#define kPurchaseProbabilitiesPercentage {20, 65, 40, 90} 

class Book {
private:
  unsigned int _id;
  unsigned long _price_cents;
  unsigned int _number_on_hand;
  unsigned int _course_prospective_enrollment;
  unsigned int _condition_flag;
  unsigned long _revenue_forecast_cents;
  unsigned int _demand_forecast;
  Book(int book_code, double price, int number_on_hand,
        int course_prospective_enrollment, int properties_flag) {
    _id=book_code;
    _price_cents = price*100;
    _number_on_hand = number_on_hand;
    _course_prospective_enrollment = course_prospective_enrollment;
    _condition_flag = properties_flag;
    int purchase_rates[] = kPurchaseProbabilitiesPercentage;
    _demand_forecast = purchase_rates[_condition_flag] * _course_prospective_enrollment / 100 - _number_on_hand;
    _revenue_forecast_cents = _demand_forecast * _price_cents;
  };
public:
  static Book* createInstanceFromInput();
  void printStats();
  unsigned long getRevenueForecast();
};
