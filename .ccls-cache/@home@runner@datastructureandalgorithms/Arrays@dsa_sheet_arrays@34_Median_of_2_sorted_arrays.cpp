#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
  int n = nums1.size();
  int m = nums2.size();

  vector<int> merged;

  int i = 0;
  int j = 0;

  while (i < n && j < m) {
    if (nums1[i] < nums2[j]) {
      merged.push_back(nums1[i]);
      i++;
    } else if (nums1[i] > nums2[j]) {
      merged.push_back(nums2[j]);
      j++;
    } else {
      merged.push_back(nums1[i]);
      merged.push_back(nums2[j]);
      i++;
      j++;
    }
  }

  while (i < n) {
    merged.push_back(nums1[i]);
    i++;
  }

  while (j < m) {
    merged.push_back(nums2[j]);
    j++;
  }

  int size = merged.size();

  double res = 0;

  if (size % 2 == 0) {
    cout << merged[size / 2] << "end" << endl;
    cout << merged[(size / 2) - 1] << "end" << endl;

    res = (merged[size / 2] + (merged[(size / 2) - 1])) / 2.0;
  } else {
    res = merged[size / 2];
  }

  return res;
}