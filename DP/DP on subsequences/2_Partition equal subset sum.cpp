#include <bits/stdc++.h>
using namespace std;

// Recursion + Memoization
class Solution {
   private:
    bool func(int id, vector<int> arr, int target, int n,
              vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (id == 0) return arr[id] == target;
        if (dp[id][target] != -1) return dp[id][target];

        bool pick = false;
        bool notPick = false;
        if (arr[id] <= target)
            pick = func(id - 1, arr, target - arr[id], n, dp);
        notPick = func(id - 1, arr, target, n, dp);

        return dp[id][target] = pick || notPick;
    }

   public:
    bool equalPartition(int n, vector<int> arr) {
        int sum = 0;
        for (int i = 0; i < n; i++) sum += arr[i];

        if (sum % 2 != 0) return false;

        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return func(n - 1, arr, target, n, dp);
    }
};





// Tabulation
class Solution {
   public:
    bool equalPartition(int n, vector<int> arr) {
        int sum = 0;
        for (int i = 0; i < n; i++) sum += arr[i];

        if (sum % 2 != 0) return false;

        int target = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));

        for (int i = 0; i < n; i++) dp[i][0] = true;
        if (arr[0] <= target) dp[0][arr[0]] = true;

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
    bool equalPartition(int n, vector<int> arr) {
        int sum = 0;
        for (int i = 0; i < n; i++) sum += arr[i];

        if (sum % 2 != 0) return false;

        int target = sum / 2;

        vector<bool> prev(target + 1, 0), temp(target + 1, 0);

        prev[0] = true;
        if(arr[0] <= target) prev[arr[0]] = true;

        for (int id = 1; id < n; id++) {
            for (int k = 1; k <= target; k++) {
                bool pick = false;
                bool notPick = false;
                if (arr[id] <= k)
                    pick = prev[k - arr[id]];
                notPick = prev[k];

                temp[k] = pick || notPick;
            }

            prev = temp;
        }

        return prev[target];
    }
};
