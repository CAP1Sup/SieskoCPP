// Current working code is run with main() function
#include <iostream>
#include <vector>
#include <string>

using namespace std;


// Set constants
const int first_class_max_size = 5;
const int economy_class_max_size = 5;


// Create data tables
vector <bool> first_class;
vector <bool> economy_class;

int current_seat;

string intended_class;

// Prompts user with the prompt, then waits for a value
string promptUser(string prompt) {
  
  string user_input;
  cout << prompt;
  
  cin >> user_input;

  return user_input;
}

void printTicket(string seating_class, int seat_number) {
  /*
  string test = string((7 - seating_class.length()), ' ');
  cout << ""
  "----------------------------------------\n"(7 - seating_class.length())
  "|  Class: " + seating_class +  + "   |\n"
  "|                                      |\n"
  "|                                      |\n"
  "|                                      |\n"
  "|                                      |\n"
  "----------------------------------------\n";
  */

  if (seating_class != "None") {
    cout << "Class: " << seating_class << endl;
    cout << "Seat number: " << seat_number <<endl;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
  }

  else {
    //cout << "Plane full. The next one leaves in 4 hours." << endl;
  }
  

}

// Adds a first class seat
string addFirstClassSeat() {

  if (first_class.size() < first_class_max_size) {
    first_class.push_back(true);
    current_seat = first_class.size();
    return "First";
  }

  else if (economy_class.size() < economy_class_max_size) {
    string move_to_economy = promptUser("No more first class seats available. Would you like to take economy class instead? (Yes/No): ");

    if (move_to_economy == "Yes" || move_to_economy == "yes" || move_to_economy == "Y") {
      economy_class.push_back(true);
      current_seat = economy_class.size();
      return "Economy";
    }

    else {
      cout << "All seats are filled. Next flight leaves in 4 hours.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
      current_seat = -1;
      return "None";
    }
    
    
  }

  else {
    cout << "All seats are filled. Next flight leaves in 4 hours.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    current_seat = -1;
    return "None";
  }

}

// Adds an economy class seat
string addEconomyClassSeat() {

  if (economy_class.size() < economy_class_max_size) {
    economy_class.push_back(true);
    current_seat = economy_class.size();
    return "Economy";
  }

  else {
    cout << "All seats are filled. Next flight leaves in 4 hours.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    current_seat = -1;
    return "None";
  }

}


int SieskoSkies() {

  while (true) {

    // Request user input, then check to make sure that it is valid
    while (true) {

      intended_class = promptUser("What is your intended class? (1 for first, 2 for economy, -1 for exit): \n");

      if (intended_class == "1" || intended_class == "2"){

        break;

      }

      else if (intended_class == "-1") {
        return 0;
      }

      else {

        cout << "Please input a valid class #\n";

      }
    }

    // Classify the input
    if (intended_class == "1") {

      cout << "First class selected\n";
      printTicket(addFirstClassSeat(), current_seat);

    }

    else if (intended_class == "2") {

      cout << "Economy class selected\n";
      printTicket(addEconomyClassSeat(), current_seat);

    }

  }

}