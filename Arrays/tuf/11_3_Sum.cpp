#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// Brute force Approach
class Solution {
public:
    vector<vector<int>> threeSumBruteForceApproach(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        set<vector<int>> tripletSet;

        for(int i = 0; i < n - 2; i++){       

            for(int j = i + 1; j < n - 1; j++){

                for(int k = j + 1; k < n; k++){

                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        tripletSet.insert({nums[i], nums[j], nums[k]});
                    }

                }

            }
        }

        vector<vector<int>> ans(tripletSet.begin(), tripletSet.end());

        return ans;
        
    }
};