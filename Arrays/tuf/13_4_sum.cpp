#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// Brute force Approach
class Solution1 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();

        set<vector<int>> quadrupletsSet;

        for(int i = 0; i < n - 3; i++){

            for(int j = i + 1; j < n - 2; j++){

                for(int k = j + 1; k < n - 1; k++){

                    for(int p = k + 1; p < n; p++){
                        
                        long long sum = (long long)(nums[i])+(long long)(nums[j]) + (long long)(nums[k]) + (long long)(nums[p]);

                        if(sum == (long long)(target)){
                            vector<int> temp = {nums[i] , nums[j] , nums[k] , nums[p]};
                            sort(temp.begin(), temp.end());

                            quadrupletsSet.insert(temp);
                        }
                    }
                }
            }
        }

        vector<vector<int>> ans(quadrupletsSet.begin(), quadrupletsSet.end());

        return ans;
    }
};