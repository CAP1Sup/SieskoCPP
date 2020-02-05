#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;


void print(vector <int> input_vector) {
  cout << "The vector elements are : ";
  
  for(int i=0; i < input_vector.size(); i++)
    cout << input_vector.at(i) << ' ';

  cout << endl;

}


vector<int> findFactors(int num) {
  vector<int> factors;

  for (int current_num = num; current_num > 0; current_num--) {
    
    if (num % current_num == 0) {
      factors.push_back(current_num);
    }
    
  }

  return factors;
}


int vectorSum(vector<int> input_vector) {

  int sum = accumulate(input_vector.begin(), input_vector.end(), 0);
  return sum;

}


int main() {
  int k1 = 0;
  int k2 = 0;

  cout << "Input the first number: ";
  cin >> k1;

  cout << "Input the second number: ";
  cin >> k2;

  int g_value = k1 + k2 + 1;

  vector<int> k1_factors = findFactors(k1);
  vector<int> k2_factors = findFactors(k2);
  vector<int> g_factors = findFactors(g_value);

  int g_sum = accumulate(g_factors.begin(), g_factors.end(), 0);


  for (int current_k1 = k1_factors.size() - 2; current_k1 > 0; current_k1--) {

    for (int current_k2 = k2_factors.size() - 2; current_k2 > 0; current_k2--) {
      

      if (k1_factors.at(current_k1) == k2_factors.at(current_k2)) { 
        k1_factors.erase(k1_factors.begin() + current_k1);
        k2_factors.erase(k2_factors.begin() + current_k2);

      }
      
      for (int current_f = g_factors.size() - 2; current_f > 0; current_f--) {

        if (k1_factors.at(current_k1) == g_factors.at(current_f)) { 
          k1_factors.erase(k1_factors.begin() + current_k1);

        }

        else if (k2_factors.at(current_k2) == g_factors.at(current_f)) { 
          k2_factors.erase(k2_factors.begin() + current_k2);

        }

      }

    }

  }

  k1_factors.erase(k1_factors.begin() + k1_factors.size() - 1);
  k2_factors.erase(k2_factors.begin() + k2_factors.size() - 1);

  int k1_sum = vectorSum(k1_factors);
  int k2_sum = vectorSum(k2_factors);

  if (k1_sum == g_value) {
    //Player 1 wins
    cout << "Player 1 wins! Their sum was: " << k1_sum << endl;
  }

  else if (k2_sum == g_value) {
    //Player 2 wins
    cout << "Player 2 wins! Their sum was: " << k2_sum << endl;
  }
  else if (k1_sum == k2_sum) {
    // Tie
    cout << "It's a tie! Try again!" << endl;
  }
  else if (k1_sum > k2_sum) {
    // Player 1 wins
    cout << "Player 1 wins! Their sum was: " << k1_sum << endl;
  }
  else {
    // Player 2 wins
    cout << "Player 2 wins! Their sum was: " << k2_sum << endl;
  }

  //print(k1_factors);
  //print(k2_factors);

}
