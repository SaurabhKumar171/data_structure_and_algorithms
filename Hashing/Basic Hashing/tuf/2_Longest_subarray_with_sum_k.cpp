#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// Brute force Approach
class Solution1{
public:
    int longestSubarray(vector<int> &nums, int k){
        
        int n = nums.size();
        int longestSubarray = 0;

        for(int i = 0; i < n; i++){

            int cnt = 0;
            int sum = 0;

            for(int j = i; j < n; j++){
                sum += nums[j];

                if(sum == k){
                    cnt = j-i+1;
                }
                else{
                    continue;
                }
            }

            longestSubarray = max(longestSubarray, cnt);
        }

        return longestSubarray;
    }
};


// Optimal Approach
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        
        int n = nums.size();
        int longestSubarray = 0;


        map<int, int> mp;
        int sum = 0;

        for(int i = 0; i < n; i++){

            sum += nums[i];

            if(sum == k){
                longestSubarray = max(longestSubarray, i + 1);
            }

            int target = sum - k;

            if(mp.find(target) != mp.end()){
                int len = i - mp[target];
                longestSubarray = max(longestSubarray, i - mp[target]);
            }

            if(mp.find(sum) == mp.end()){
                mp[sum] = i;
            }
        }

        return longestSubarray;
    }
};
