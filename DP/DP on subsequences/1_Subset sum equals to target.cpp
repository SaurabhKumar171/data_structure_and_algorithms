#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization
class Solution {
   private:
    bool func(int id, vector<int> arr, int target, int sum, int n, vector<vector<int>>& dp) {
        if (sum == target) return true;
        if (id == n) return false;
        if(dp[id][sum] != -1) return dp[id][sum];

        bool pick; 
        bool notPick = false;
        if (sum + arr[id] <= target) pick = func(id + 1, arr, target, sum + arr[id], n, dp);
        notPick = func(id + 1, arr, target, sum, n, dp);

        return dp[id][sum] = pick || notPick;
    }

   public:
    bool isSubsetSum(vector<int> arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (target + 1, -1));
        return func(0, arr, target, 0, n, dp);
    }
};


// Tabulation
class Solution {
   public:
    bool isSubsetSum(vector<int> arr, int target) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));

        for (int i = 0; i < n; i++) dp[i][0] = true;
        dp[0][arr[0]] = true;

        for (int id = 1; id < n; id++) {
            for (int k = 1; k <= target; k++) {
                bool pick = false;
                bool notPick = false;
                if (arr[id] <= k)
                    pick = dp[id - 1][k - arr[id]];
                notPick = dp[id - 1][k];

                dp[id][k] = pick || notPick;
            }
        }

        return dp[n - 1][target];
    }
};

// Space Optimization
class Solution {
   public:
    bool isSubsetSum(vector<int> arr, int target) {
        int n = arr.size();
        vector<bool> prev(target + 1, 0), curr(target + 1, 0);

        prev[0] = curr[0] = true;
        prev[arr[0]] = true;

        for (int id = 1; id < n; id++) {
            for (int k = 1; k <= target; k++) {
                bool pick = false;
                bool notPick = false;
                if (arr[id] <= k) pick = prev[k - arr[id]];
                notPick = prev[k];

                curr[k] = pick || notPick;
            }

            prev = curr;
        }

        return prev[target];
    }
};