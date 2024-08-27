#include <algorithm>
#include <iostream>
using namespace std;

int getMinDiff(int arr[], int n, int k) {
  // code here

  sort(arr, arr + n);

  int res = arr[n - 1] - arr[0];
  int maximum = 0;
  int minimum = 0;
  for (int i = 1; i < n; i++) {

    if (arr[i] > k) {
      minimum = min(arr[i] - k, arr[0] + k);
      maximum = max(arr[i - 1] + k, arr[n - 1] - k);

      res = min(res, maximum - minimum);
    }
  }

  return res;
}