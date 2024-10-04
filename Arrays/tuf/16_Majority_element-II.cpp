#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
  
// Brute force Approach
class Solution1 {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {
        
        int n = nums.size();

        int k = n/3;

        vector<int> ans;

        for(int i = 0; i < n; i++){

            int cnt = 0;

            if(ans.size() != 0 && ans[0] == nums[i]) continue;

            for(int j = i; j < n; j++){

                if(nums[i] == nums[j]){
                    cnt++;
                }
            }

            if(cnt > k){
                ans.push_back(nums[i]);
            }

            if(ans.size() == 2){
                break;
            }
        }

        return ans;
    }
};


// Better Approach
class Solution2 {
public:
    vector<int> majorityElementTwo(vector<int>& nums) {
        
        int n = nums.size();

        int k = n/3;

        vector<int> ans;

        unordered_map<int, int> m;

        for(int i = 0; i < n; i++){
            m[nums[i]]++;
        }

        for(auto i : m){
            if(i.second > k){
                ans.push_back(i.first);
            }

            if(ans.size() == 2){
                break;
            }
        }

        return ans;
    }
};

// Optimal Approach
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();

        int k = n/3;

        vector<int> ans;

        int cnt1 = 0, ele1 = 0;
        int cnt2 = 0, ele2 = 0;

        for(int i = 0; i < n; i++){

            if(cnt1 == 0 && nums[i] != ele2){
                cnt1++;
                ele1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != ele1){
                cnt2++;
                ele2 = nums[i];
            }
            else if(nums[i] == ele1){
                cnt1++;
            }
            else if(nums[i] == ele2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == ele1){
                cnt1++;
            }
            else if(nums[i] == ele2){
                cnt2++;
            }
        }

        if(cnt1 > k){
            ans.push_back(ele1);
        }

        if(cnt2 > k && ele1 != ele2){
            ans.push_back(ele2);
        }

        return ans;
    }
};
