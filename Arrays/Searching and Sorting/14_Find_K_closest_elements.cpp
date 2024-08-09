#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> &a, int x) {
  int i = 0;
  int j = a.size() - 1;
  int ans = j;

  while (i <= j) {
    int m = i + (j - i) / 2;

    if (a[m] >= x) {
      ans = m;
      j = m - 1;
    } else if (a[m] < x) {
      i = m + 1;
    } else {
      j = m - 1;
    }
  }

  return ans;
}

// Binary search + Two Pointer Approach [ Time complexity : O(logn+k) , Space
// complexity : O(k) ]    
vector<int> bs_method(vector<int> &arr, int k, int x) {

  int h = lowerBound(arr, x);
  // cout << "lb"<<h<<endl;
  int l = h - 1;

  while (k--) {
    if (l < 0) {
      h++;
    } else if (h >= arr.size()) {
      l--;
    } else if (x - arr[l] > arr[h] - x) {
      h++;
    } else {
      l--;
    }
  }

  vector<int> res;

  for (int i = l + 1; i < h; i++) {
    res.push_back(arr[i]);
  }

  return res;
}

// Two Pointer Approach [ Time complexity : O(n - k) , Space complexity : O(k) ]
vector<int> twoptrApproach(vector<int> &arr, int k, int x) {
  int l = 0;
  int h = arr.size() - 1;

  while (h - l >= k) {
    if (x - arr[l] > arr[h] - x) {
      l++;
    } else {
      h--;
    }
  }

  vector<int> res;

  for (int i = l; i <= h; i++) {
    res.push_back(arr[i]);
  }

  return res;
}

vector<int> findClosestElements(vector<int> &arr, int k, int x) {

  return bs_method(arr, k, x);
}
