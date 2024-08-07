#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int getPivot(vector<int> &nums) {

  int i = 0;
  int j = nums.size() - 1;

  while (i <= j) {
    int m = i + (j - i) / 2;
    if (i == j) {
      return i;
    }
    if (m <= j && nums[m] > nums[m + 1]) {
      return m;
    }
    if (m - 1 >= i && nums[m] < nums[m - 1]) {
      return m - 1;
    }
    if (nums[m] < nums[i]) {
      j = m - 1;
    } else {
      i = m + 1;
    }
  }

  return -1;
}

int binarySearch(vector<int> &arr, int i, int j, int target) {
  while (i <= j) {
    int m = i + (j - i) / 2;

    if (arr[m] == target) {
      return m;
    } else if (arr[m] < target) {
      i = m + 1;
    } else {
      j = m - 1;
    }
  }
  return -1;
}

int search(vector<int> &nums, int target) {

  int pivot = getPivot(nums);
  // cout << "pivot" <<pivot<<endl;
  int ans = 0;

  if (target <= nums[pivot] && target >= nums[0]) {
    ans = binarySearch(nums, 0, pivot, target);
  } else {
    ans = binarySearch(nums, pivot + 1, nums.size() - 1, target);
  }

  return ans;
}