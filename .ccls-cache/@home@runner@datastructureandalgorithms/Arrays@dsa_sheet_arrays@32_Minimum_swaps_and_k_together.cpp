#include <iostream>
#include <vector>
using namespace std;

int minSwap(int arr[], int n, int k) {
  // Complet the function

  int windowSizeNeeded = 0;
  int bad = 0;

  for (int i = 0; i < n; i++) {
    if (arr[i] <= k)
      windowSizeNeeded++;
  }

  for (int i = 0; i < windowSizeNeeded; i++) {
    if (arr[i] > k)
      bad++;
  }

  int ans = bad;
  for (int i = 0, j = windowSizeNeeded; j < n; i++, j++) {

    if (arr[i] > k)
      bad--;

    if (arr[j] > k)
      bad++;

    ans = min(ans, bad);
  }

  return ans;
}
