#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {

// sort(nums.begin(), nums.end());

int st = 0;

  while(st < nums.size()){

    if(nums[nums[st]] == nums[st]){
        return nums[st];
    }
    swap(nums[nums[st]],nums[st]);
  }

  return -1;  
}