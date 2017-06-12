// artillery.cpp: Denys Soroka
// program simulates war defence
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>

#define kMaxDistance 1000
#define kMaxShots 10
#define kDefaultShotAngleValue 45.0
#define kLineMaxLenght 1000
#define kInitialProjectileVelocity 200
#define kGravityConstant 32.2

using namespace std;

void print_intro_message();
bool check_if_wants_to_play_more();
int play_one_round();
/** Takes user input in degrees and returns corresponding
  * value in radians. */
double get_shot_angle();
/** Returns amount of time, that projectile spends in air 
  * before falling on ground. */
double compute_time_in_air(double angle_degrees, double projectile_speed);

int main() {
  
  print_intro_message();
  int enemies_killed(0);
  bool should_continue(true);
  srand(time(NULL));
  
  // loop rounds until exit
  do {
    enemies_killed += play_one_round();
    should_continue = check_if_wants_to_play_more();
  } while(should_continue);
  
  cout << "You killed " << enemies_killed << " of the enemy." << endl;
  return 0;
}

int play_one_round(){
  
  int distance(rand() % kMaxDistance);
  int shots_left(kMaxShots);
  
  while (shots_left > 0) {
    double angle = get_shot_angle();
    double time_in_air (compute_time_in_air(angle, kInitialProjectileVelocity));
    double shot_distance (round(kInitialProjectileVelocity * cos(angle) * time_in_air));
    
    if (shot_distance != distance) {
      cout << "You " << ((distance > shot_distance) ? "under" : "over");
      cout << " shot by " << abs(shot_distance - distance) << endl;
      shots_left--;
    } else {
      cout << "You hit him!!!" << endl;
      cout << "It took you " << kMaxShots - shots_left << " shots." << endl;
      return 1;
    }
    
  }
  
  cout << "No more projectiles left." << endl;
  return 0;
}

double get_shot_angle() {
  cout << "What angle? ";
  double angle(kDefaultShotAngleValue);
  if(!(cin >> angle) || (angle < 0) || (angle > 90)) {
      cout << "Invalid angle value, assuming " << kDefaultShotAngleValue;
      cout << " degrees..." << endl;
      if (cin.fail()) {
        cin.clear();
        cin.ignore(kLineMaxLenght, '\n');
      }
  }
  return angle * 3.1415 / 180;
}

double compute_time_in_air(double angle, double projectile_speed) {
    return (2 * projectile_speed * sin(angle)) / kGravityConstant;
}

bool check_if_wants_to_play_more() {
  char input;
  cout << "I see another one, care to shoot again? (Y/N) " << endl;  
  cin >> input;
  if (input == 'n' || input == 'N') {
    return false;
  }
  return true;
}

void print_intro_message() {
  cout << "Welcome to Artillery." << endl;
  cout << "You are in the middle of a war and being charged by thousands of enemies." << endl;
  cout << "You have one cannon, which you can shoot at any angle." << endl;
  cout << "You only have " << kMaxShots << " cannonballs for this target.." << endl; 
  cout << "Let's begin..." << endl;
}
