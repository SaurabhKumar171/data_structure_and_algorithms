#include <iostream>
#include <unordered_map>
using namespace std;

int getPairsCount(int arr[], int n, int k) {
  // code here
  int cnt = 0;
  unordered_map<int, int> uMap;

  for (int i = 0; i < n; i++) {
    int target = k - arr[i];

    if (uMap.count(target) != 0)
      cnt += uMap[target];

    uMap[arr[i]]++;
  }

  return cnt;
}