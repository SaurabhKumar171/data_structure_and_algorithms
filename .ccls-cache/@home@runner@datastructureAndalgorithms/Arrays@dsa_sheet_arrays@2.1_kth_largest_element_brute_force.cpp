#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int largestElement(vector<int>& nums, int n, int k){
  int maximum_index = 0;
  for(int i = 0; i < n; i++){
      if(nums[i] > nums[maximum_index]){
          maximum_index = i;
      }
  }

  if(k>1){
      nums[maximum_index] = INT_MIN;
  }

  return maximum_index;
}

int findKthLargest(vector<int>& nums, int k) {

  int kth_largest_element_index = 0;
  for(int i = k; i > 0; i--){
      kth_largest_element_index = largestElement(nums, nums.size(), i);
  }
  return nums[kth_largest_element_index];
}
