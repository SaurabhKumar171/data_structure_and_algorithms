#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int sumHighestAndLowestFrequency(vector<int> &nums) {

  unordered_map<int, int> frequencyMap;

  for (int i = 0; i < nums.size(); i++) {
    frequencyMap[nums[i]]++;
  }

  int highestFrequency = INT_MIN;
  int leastFrequency = INT_MAX;

  for (auto entry : frequencyMap) {
    highestFrequency = max(highestFrequency, entry.second);
    leastFrequency = min(leastFrequency, entry.second);
  }

  return leastFrequency + highestFrequency;
}