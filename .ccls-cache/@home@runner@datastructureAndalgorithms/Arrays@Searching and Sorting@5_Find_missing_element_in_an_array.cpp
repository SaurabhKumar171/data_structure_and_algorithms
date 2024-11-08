#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

int missingNumber(int n, vector<int> &arr) {

  sort(arr.begin(), arr.end());
  // Your code goes here
  int i = 0;
  int j = arr.size() - 1;

  while (i <= j) {
    int m = i + (j - i) / 2;

    if (arr[m] != m + 1) {
      j = m - 1;
    } else {
      i = m + 1;
    }
  }

  return i + 1;
}