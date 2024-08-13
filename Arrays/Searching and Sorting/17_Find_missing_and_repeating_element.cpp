#include <iostream>
using namespace std;
#include <vector>

// Brute force approach
vector<int> findTwoElementBruteForce(vector<int> arr, int n) {
  int repeatingNum = -1;
  int missingNum = -1;

  for (int i = 1; i <= n; i++) {

    int count = 0;

    for (int j = 0; j < n; j++) {
      if (arr[j] == i) {
        count++;
      }
    }

    if (count > 1) {
      repeatingNum = i;
    }

    if (count == 0) {
      missingNum = i;
    }
  }

  return vector<int>{repeatingNum, missingNum};
}

// Better Approach
vector<int> findTwoElementBetterApproach(vector<int> arr, int n) {
  // code here
  // int missingNum = missingNumber(arr, n);
  // int repeatingNum = repeatingNumber(arr, n);

  int repeatingNum = -1;
  int missingNum = -1;

  unordered_map<int, int> map;

  for (int i = 0; i < n; i++) {
    map[arr[i]]++;
  }

  for (int i = 1; i <= n; i++) {
    if (map[i] == 0) {
      missingNum = i; // Number i is missing
    }
    if (map[i] > 1) {
      repeatingNum = i; // Number i is repeating
    }
  }

  return vector<int>{repeatingNum, missingNum};
}