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

// Better Approach
class Solution2 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        set<vector<int>> tripletSet;

        for(int i = 0; i < n - 2; i++){

            for(int j = i + 1; j < n - 1; j++){
                
                set<int> hs;

                for(int k = j+1; k < n; k++){

                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long ele = target - sum;

                    if(hs.find(ele) != hs.end()){

                        vector<int> temp = {nums[i], nums[j], nums[k], static_cast<int>(ele)};
                        sort(temp.begin(), temp.end());

                        tripletSet.insert(temp);
                    }

                    hs.insert(nums[k]);
                }
            }
        }

        vector<vector<int>> ans(tripletSet.begin(), tripletSet.end());

        return ans;
    }
};


// Optimal Approach
class Solution3 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 3; i++){

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for(int j = i+1; j < n - 2; j++){

                if (j > i+1 && nums[j] == nums[j - 1])
                    continue;
                
                int k = j + 1, p = n - 1;

                while(k < p){

                    long long sum = (long long)(nums[i])+(long long)(nums[j]) + (long long)(nums[k]) + (long long)(nums[p]);

                    if(sum == (long long)target){
                        vector<int> temp = {nums[i] , nums[j] , nums[k] , nums[p]};
                        ans.push_back(temp);

                        k++;
                        p--;

                        while(k < p && nums[k] == nums[k - 1]) k++;
                        while(k < p && nums[p] == nums[p + 1]) p--;
                    }
                    else if(sum < target){
                        k++;
                    }
                    else{
                        p--;
                    }
                }

            }
        }

        return ans;
    }
};