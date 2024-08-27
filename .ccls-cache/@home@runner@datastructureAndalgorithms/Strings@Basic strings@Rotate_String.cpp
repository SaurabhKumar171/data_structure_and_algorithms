#include <iostream>
using namespace std;

// Brute Force Approach
string rotate(string str) {
  char firstCharacter = str[0];

  for (int i = 0; i < str.size() - 1; i++) {
    str[i] = str[i + 1];
  }

  str[str.size() - 1] = firstCharacter;

  return str;
}

bool rotateStringBruteForce(string s, string goal) {

  for (int i = 0; i < goal.size(); i++) {

    goal = rotate(goal);

    cout << "rotated string " << goal << endl;

    if (goal == s) {
      return true;
    }
  }

  return false;
}

// Optimal Approach
bool rotateStringOptimalApproach(string s, string goal) {

  int sizeOfs = s.size();
  int sizeOfGoal = goal.size();

  if (sizeOfs != sizeOfGoal) {
    return false;
  }

  for (int i = 0; i < sizeOfs; i++) {
    string rotated = s.substr(i) + s.substr(0, i);

    if (rotated == goal) {
      return true;
    }
  }

  return false;
}