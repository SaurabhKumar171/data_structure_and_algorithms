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
class Solution2{
public:
    int longestSubarray(vector<int> &nums, int k){
        
        int n = nums.size();
        int maxLength = 0;

        unordered_map<int, int> map;

        int sum = 0;

        for(int i = 0; i < n; i++){

            sum += nums[i];

            if(sum == k){
                maxLength = max(maxLength, i+1);
            }

            int diff = sum - k;

            if(map.find(diff) != map.end()){
                maxLength = max(maxLength, i - map[diff]);
            }

            if(map.find(sum) == map.end()){
                map[sum] = i;
            }
        }

        return maxLength;
    }
};
