#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// Brute force Approach
class Solution1 {
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



// Better Approach
class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();

       set<vector<int>> tripletSet;

       for(int i = 0; i < n; i++){

            set<int> hashset;

            for(int j = i + 1; j < n; j++){

                int third = -(nums[i] + nums[j]);

                if(hashset.find(third) != hashset.end()){
                    vector<int> temp = {nums[i], nums[j], third};
                    
                    sort(temp.begin(), temp.end());
                    tripletSet.insert(temp);
                }

                hashset.insert(nums[j]);
            }

       }

       vector<vector<int>> ans(tripletSet.begin(), tripletSet.end());

       return ans;
        
    }
};



// Optimal Approach
class Solution3 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
       int n = nums.size();

       vector<vector<int>> ans;

       sort(nums.begin(), nums.end());

       for(int i = 0; i < n; i++){

            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            int j = i + 1, k = n - 1;

            while(j < k){

                int sum = nums[i]+nums[j]+nums[k];

                if(sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while(j < k && nums[j] == nums[j-1]){
                        j++;
                    }

                    while(j < k && nums[k] == nums[k+1]){
                        k--;
                    }

                }
                else if(sum < 0){
                    j++;
                }
                else{
                    k--;
                }
            }
       }

       return ans;
    }
};