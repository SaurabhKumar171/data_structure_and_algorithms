#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include <numeric>
using namespace std;

class Solution{
    private:   
        int createSubset(int index, int k, vector<int> nums){

            int cnt = 0;

            if(k == 0){
                return 1;
            }
            if (index >= nums.size() || k < 0) {
                return 0;
            }

            cnt += createSubset(index + 1, k - nums[index], nums);

            cnt += createSubset(index + 1, k, nums);

            return cnt;
        }

    public:    	
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	//your code goes here

        return createSubset(0, k, nums);
    }
};