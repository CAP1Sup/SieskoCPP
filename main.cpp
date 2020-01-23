// Current working code is run with main() function
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int first_class_size = 5;
const int economy_class_size = 5;


string promptUser(string prompt) {
  
  string user_input;
  cout << prompt;

  cin >> user_input;

  return user_input;
}


int main() {

  //vector < vector <string> > first_class;
  //vector < vector <string> > economy_class;

  vector <string> first_class;
  vector <string> economy_class;

  while (true) {

    string intended_class = promptUser("What is your intended class? (1 for first, 2 for economy): \n");

    if (intended_class == "1" || intended_class == "2"){
      break;
    }
    else {
      cout << "Please input a valid class #\n";
    }
}



  

  //if (intended_class == 1) {

  //}

  cout << "Running\n";
  return 0;

}


