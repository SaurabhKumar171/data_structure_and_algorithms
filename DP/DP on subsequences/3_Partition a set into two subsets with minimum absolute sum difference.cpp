#include <bits/stdc++.h>
using namespace std;

// Tabulation
class Solution {
   public:
    int minDifference(vector<int>& arr, int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) sum += arr[i];

        int target = sum;
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


        int ans = INT_MAX;
        for(int i = 0; i <= sum/2; i++){
            if(dp[n - 1][i]) ans = min(ans, abs((sum - i) - i));
        }

        return ans;
    }
};

// Space optimisation
class Solution {
   public:
    int minDifference(vector<int>& arr, int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) sum += arr[i];

        int target = sum;
        vector<bool> prev(target + 1, 0), temp(target + 1, 0);

        prev[0] = true;
        if(arr[0] <= target) prev[arr[0]] = true;

        for (int id = 1; id < n; id++) {
            temp[0] = true;
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

        int ans = INT_MAX;
        for(int i = 0; i <= sum/2; i++){
            if(prev[i]) ans = min(ans, abs((sum - i) - i));
        }

        return ans;
    }
};
