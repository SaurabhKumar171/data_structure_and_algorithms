#include <bits/stdc++.h>
using namespace std;


// Recursion + Memoization
// Time Complexity: O(N2), where N is the size of the array
// Because there will be a total of N*N states for which the function will be called.

// Space Complexity: O(N2), because of the 2D dp array created taking O(N2) space and O(N) recursive stack space.


class Solution {
    int func(int id, int prev, vector<int>& nums, int n,
             vector<vector<int>>& dp) {
        if (id == n) return 0;

        if (dp[id][prev + 1] != -1) return dp[id][prev + 1];

        int pick = 0, notPick = 0;
        if (prev == -1 || nums[id] > nums[prev])
            pick = 1 + func(id + 1, id, nums, n, dp);
        notPick = func(id + 1, prev, nums, n, dp);

        return dp[id][prev + 1] = max(pick, notPick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 1, -1));
        return func(0, -1, nums, nums.size(), dp);
    }
};