#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include <numeric>
using namespace std;

class Solution{
    private:
        bool createSubset(int index, int k, vector<int> nums){

            if(k == 0){
                return true;
            }
            if (index >= nums.size() || k < 0) {
                return false;
            }

            bool path1 = createSubset(index + 1, k - nums[index], nums);

            bool path2 = createSubset(index + 1, k, nums);

            return path1 || path2;
        }

    public:
    bool checkSubsequenceSum(vector<int>& nums, int k) {
         //your code goes here
        return createSubset(0, k, nums);
    }
};