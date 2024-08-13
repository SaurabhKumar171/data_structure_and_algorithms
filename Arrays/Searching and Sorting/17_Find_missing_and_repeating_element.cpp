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