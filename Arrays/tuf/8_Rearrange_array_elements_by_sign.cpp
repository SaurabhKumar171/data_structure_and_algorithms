#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute force Approach
class Solution1 {
public:
    vector<int> rearrangeArrayBruteForceApproach(vector<int>& nums) {
        
        vector<int> positive;
        vector<int> negative;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                positive.emplace_back(nums[i]);
            }
            else{
                negative.emplace_back(nums[i]);
            }
        }
        
        for(int i = 0; i < nums.size()/2; i++){
            nums[2*i] = positive[i];
            nums[2*i+1] = negative[i];
        }

        return nums;
    }
};


//Optimal Approach
class Solution2 {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
       int pIndex = 0;
       int nIndex = 1;

       vector<int> ans(nums.size(), 0);

      for(int i = 0; i < nums.size(); i++){

        if(nums[i] > 0){
            ans[pIndex] = nums[i];

            pIndex +=2;
        }
        else{
            ans[nIndex] = nums[i];

            nIndex +=2;   
        }
      }

       return ans;
    }
};