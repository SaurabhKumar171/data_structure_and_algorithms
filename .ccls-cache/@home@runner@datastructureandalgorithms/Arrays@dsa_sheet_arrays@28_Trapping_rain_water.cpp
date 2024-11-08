#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

// Brute force
int trap1(vector<int> &height) {
  int n = height.size();

  int ans = 0;

  for (int i = 0; i < n; i++) {
    int j = i;
    int lmax = INT_MIN;
    while (j >= 0) {
      lmax = max(lmax, height[j]);
      j--;
    }

    j = i;
    int rmax = INT_MIN;
    while (j < n) {
      rmax = max(rmax, height[j]);
      j++;
    }

    ans += min(lmax, rmax) - height[i];
  }

  return ans;
}

// Better approach
int trap2(vector<int> &height) {
  int n = height.size();

  if (n == 0)
    return 0; // early return for empty input

  vector<int> leftMax(n);
  vector<int> rightMax(n);
  int ans = 0;
  int maximum = INT_MIN;

  for (int i = 0; i < n; i++) {
    maximum = max(maximum, height[i]);
    leftMax[i] = maximum;
  }

  maximum = 0;
  for (int i = n - 1; i >= 0; i--) {
    maximum = max(maximum, height[i]);
    rightMax[i] = maximum;
  }

  for (int i = 0; i < n; i++) {
    ans += min(rightMax[i], leftMax[i]) - height[i];
    cout << ans;
  }

  return ans;
}

// Optimal Solution
int trap3(vector<int> &height) {
  int n = height.size();

  int l = 0;
  int r = n - 1;
  int lmax = 0;
  int rmax = 0;
  int ans = 0;

  while (l <= r) {
    if (height[l] <= height[r]) {
      if (lmax < height[l]) {
        lmax = height[l];
      } else {
        ans += lmax - height[l];
      }
      l++;
    } else {
      if (rmax < height[r]) {
        rmax = height[r];
      } else {
        ans += rmax - height[r];
      }
      r--;
    }
  }

  return ans;
}