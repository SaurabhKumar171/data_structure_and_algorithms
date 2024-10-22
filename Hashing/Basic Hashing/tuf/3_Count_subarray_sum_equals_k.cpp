#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// Brute force Approach
class Solution1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int longestSubarray = 0;
        int cnt = 0;

        for(int i = 0; i < n; i++){

            int sum = 0;

            for(int j = i; j < n; j++){
                sum += nums[j];

                if(sum == k){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};


// Optimal Approach
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> map;
        map[0] = 1;

        int cnt = 0;
        int sum = 0;

        for(int i = 0; i < n; i++){

            sum += nums[i];
            int diff = sum - k;

            if(map.find(diff) != map.end()){
                cnt += map[diff];
            }
            
            map[sum]++;
        }

        return cnt;
    }
};
