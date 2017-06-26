// Composer.cc, Denys Soroka
// Composer class implementation

#include <iostream>
#include "Composer.h"

Composer::Composer() {}
Composer::~Composer() {}

void Composer::set_first_name(string in_first_name) {
  first_name_ = in_first_name;
}

string Composer::first_name() { 
  string first_name_copy(first_name_);  
  return first_name_copy; 
}

void Composer::set_last_name(string in_last_name) {
  last_name_ = in_last_name;
}

string Composer::last_name() {
  string last_name_copy(last_name_); 
  return last_name_copy;
}

void Composer::set_composer_yob(int in_composer_yob) {
  composer_yob_ = in_composer_yob;
}

int Composer::composer_yob() { return composer_yob_; }

void Composer::set_composer_genre(string in_composer_genre) {
  composer_genre_ = in_composer_genre;
}

string Composer::composer_genre() {
  string genre_copy(composer_genre_);
  return genre_copy;
}

void Composer::set_ranking(int in_ranking) {
  ranking_ = in_ranking;
}

int Composer::ranking() { return ranking_; }

void Composer::set_fact(string in_fact) {
  fact_ = in_fact;
}

string Composer::fact() {
  string fact_copy(fact_);
  return fact_copy;
}

void Composer::Promote(int increment) {
  ranking_ += increment;
}

void Composer::Demote(int decrement) {
  ranking_ -= decrement;
}

void Composer::Display() {
  cout << "*** " << first_name() << " " << last_name() << " ***"<< endl;
  cout << "\tYear of birht is " << composer_yob() << endl;
  cout << "\tGenre is " << composer_genre() << endl;
  cout << "\tRank is " << ranking() << endl;
  cout << "Interesting facts: " << fact() << endl;
}
