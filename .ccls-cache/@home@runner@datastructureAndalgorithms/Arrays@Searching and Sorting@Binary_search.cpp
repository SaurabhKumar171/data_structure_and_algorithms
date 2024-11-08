#include <iostream>
using namespace std;
#include <vector>;

int binarySearch(vector<int> &arr, int target) {
  int i = 0;
  int j = arr.size() - 1;

  while (i <= j) {
    int m = i + (j - i) / 2;

    if (arr[m] == target) {
      return m;
    } else if (arr[m] > target) {
      j = m - 1;
    } else {
      i = m + 1;
    }
  }

  return -1;
}