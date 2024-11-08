#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Binary search Approach
int findPairs2(vector<int> &nums, int k) {

  int n = nums.size();
  int count = 0;

  unordered_map<int, int> map;

  for (int i = 0; i < n; i++) {
    map[nums[i]]++;
  }

  for (auto i : map) {
    int target = i.first + k;

    if (k > 0 && map.find(target) != map.end()) {
      count++;
    } else if (k == 0 && i.second > 1) {
      count++;
    }
  }

  return count;
}

// Two pointer Approach
int findPairs1(vector<int> &nums, int k) {

  int n = nums.size();

  set<pair<int, int>> ans;

  sort(nums.begin(), nums.end());

  int i = 0;
  int j = 1;

  while (j < n) {

    int diff = nums[j] - nums[i];

    if (i != j && diff == k) {
      ans.insert({nums[i], nums[j]});
      j++;
      i++;
    } else if (diff > k) {
      i++;
    } else {
      j++;
    }
  }

  return ans.size();
}