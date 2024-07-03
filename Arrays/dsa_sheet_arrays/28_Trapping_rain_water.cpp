#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
  
int trap(vector<int> &height) {
  int n = height.size();

  if (n == 0)
    return 0; // early return for empty input

  vector<int> leftMax(n);
  vector<int> rightMax(n);
  int ans = 0;
  int maximum = INT_MIN;

  // cout << "rf";
  for (int i = 0; i < n; i++) {
    maximum = max(maximum, height[i]);
    leftMax[i] = maximum;
    // cout << leftMax[i];
  }

  // cout << endl<< "rf";

  maximum = 0;
  for (int i = n - 1; i >= 0; i--) {
    maximum = max(maximum, height[i]);
    rightMax[i] = maximum;
    // cout << rightMax[i];
  }

  for (int i = 0; i < n; i++) {
    // cout << rightMax[i] << "|"<< leftMax[i] << "|" <<height[i]<<endl;
    ans += min(rightMax[i], leftMax[i]) - height[i];
    cout << ans;
  }

  return ans;
}