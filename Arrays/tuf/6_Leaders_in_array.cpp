#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
      
      vector<int> result;
      int n = nums.size();

      int currentLeader = nums[n-1];

      result.push_back(currentLeader);

      for(int i = n - 2; i >= 0; i--){

          if(nums[i] > currentLeader){
            result.push_back(nums[i]);
            currentLeader = nums[i];
          }
      }   

      reverse(result.begin(), result.end());

      return result;
    }
};
