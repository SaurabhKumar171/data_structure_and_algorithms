#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

// Optimal approach (Duth national flag Algorithm)
void threeWayPartition(vector<int> &nums, int a, int b) {
  int l = 0;
  int m = 0;
  int h = nums.size() - 1;

  while (m <= h) {
    if (nums[m] > b) {
      swap(nums[m], nums[h]);
      h--;
    } else if (nums[m] < a) {
      swap(nums[m], nums[l]);
      l++;
      m++;
    } else {
      m++;
    }
  }
}