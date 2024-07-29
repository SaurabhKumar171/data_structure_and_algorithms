#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {

  int i = 0;
  int j = n - 1;

  while (i <= j) {
    int m = i + (j - i) / 2;

    if (arr[i] == target) {
      return i;
    } else if (arr[i] > target) {
      j = m - 1;
    } else {
      i = m + 1;
    }
  }

  return -1;
}