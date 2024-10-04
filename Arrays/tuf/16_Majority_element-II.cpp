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