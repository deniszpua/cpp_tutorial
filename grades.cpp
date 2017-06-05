// grades.cpp: Denys Soroka
// computes final course grade using following formula:
// course_grade = (assignement1_grade + assignement2_grade + .. + assignement4_grade) * 0.1 +
//                midterm_exam_grade * 0.15 + final_exam_grade * .35 + 
//                class_participation_grade * .1

#include <iostream>

#define kAssignementMultiplier 0.1
#define kMidtermExamMultiplier 0.15
#define kFinalExamMultiplier 0.35
#define kClassParticipationMultiplier 0.1

using namespace std;

int main() {
  double multipliers[] = {
    kAssignementMultiplier, 
    kAssignementMultiplier, 
    kAssignementMultiplier, 
    kAssignementMultiplier,
    kMidtermExamMultiplier,
    kFinalExamMultiplier,
    kClassParticipationMultiplier
  };
  string grade_names[] = {
    "first assignement",
    "second assignement",
    "third assignement",
    "fourth assignement",
    "midterm exam",
    "final exam",
    "class participation"
  };
  
  double total_score = 0.0;
  int grade;
  for (size_t i = 0; i < 7; i++) {
    cout << "Enter grade for " << grade_names[i] << ": ";
    if(cin >> grade){
      total_score += grade * multipliers[i];
    } else {
      cout << "Invalid input" << endl;
      return 1;
    }
    
  }
  
  cout << "Total course grade is " << total_score << endl;
  
}
