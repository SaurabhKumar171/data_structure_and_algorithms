#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int findPairs(vector<int> &nums, int k) {

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