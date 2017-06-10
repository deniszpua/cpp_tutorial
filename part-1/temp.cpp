// file.cpp, Maggie Johnson
// Description: An illustration of file processing
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

#define kInvalidFilenameError 1

int main() {
  char first_name[30], last_name[30]; int age;
  char file_name[20];
  cout << endl << "Enter the name of the file: "; 
  if (!(cin >> file_name)) {
    cout << "Invalid filename" << endl;
    return kInvalidFilenameError;
  }
  // Create an ofstream called People, open the stream for output.
  ofstream People(file_name, ios::out);
  
  // Collect the data.
  while (true) {
    cout << "Enter First Name (zero for exit): "; cin >> first_name;
    if (strcmp(first_name, "0") == 0) {
      break;
    }
    cout << "Enter Last Name: "; cin >> last_name;
    cout << "Enter Age: "; cin >> age;

    // Write data to the stream.
    People << first_name << endl << last_name << endl << age << endl; 
    
  }

  // Open file
  People.close();
  ifstream ReadPeople(file_name, ios::in);
  
  char name[30], family_name[30];
  int read_age;
  
  while(!ReadPeople.eof()) {
    ReadPeople >> name >> family_name >> read_age;
    cout << "Data: " << name << "," << family_name << ", " << read_age << " was read from file." << endl;
    
  }
  
  ReadPeople.close();
  return 0;
}
