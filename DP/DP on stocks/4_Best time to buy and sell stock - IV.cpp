#include <bits/stdc++.h>
using namespace std;


// Recursion + Memoization
// T.C: O(N)
// S.C: O(N)
class Solution {
   private:
    int func(int id, int buy, vector<int> arr, int n,
             vector<vector<vector<int>>>& dp, int buyCount) {
        if (id == n || buyCount == 0) return 0;

        if (dp[id][buy][buyCount] != -1) return dp[id][buy][buyCount];

        int profit = 0;

        if (buy) {
            int boughtStockOnCurrentDay =
                -arr[id] + func(id + 1, 0, arr, n, dp, buyCount);
            int notBoughtStockOnCurrentDay =
                func(id + 1, 1, arr, n, dp, buyCount);

            profit = max(boughtStockOnCurrentDay, notBoughtStockOnCurrentDay);
        } else {
            int soldStockOnCurrentDay =
                arr[id] + func(id + 1, 1, arr, n, dp, buyCount - 1);
            int notSoldStockOnCurrentDay =
                func(id + 1, 0, arr, n, dp, buyCount);

            profit = max(soldStockOnCurrentDay, notSoldStockOnCurrentDay);
        }

        return dp[id][buy][buyCount] = profit;
    }

   public:
    int stockBuySell(vector<int> arr, int n, int k) {
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return func(0, 1, arr, n, dp, k);
    }
};

// Tabulation
// Time Complexity:O(n) due to the single loop iterating from n-1 down to 0.
// Space Complexity:O(n) because of the dp table of size (n+1)*2.
class Solution {
   private:
    int func(int id, int buy, vector<int> arr, int n,
             vector<vector<vector<int>>>& dp, int buyCount) {
        if (id == n || buyCount == 0) return 0;

        if (dp[id][buy][buyCount] != -1) return dp[id][buy][buyCount];

        int profit = 0;

        if (buy) {
            int boughtStockOnCurrentDay =
                -arr[id] + func(id + 1, 0, arr, n, dp, buyCount);
            int notBoughtStockOnCurrentDay =
                func(id + 1, 1, arr, n, dp, buyCount);

            profit = max(boughtStockOnCurrentDay, notBoughtStockOnCurrentDay);
        } else {
            int soldStockOnCurrentDay =
                arr[id] + func(id + 1, 1, arr, n, dp, buyCount - 1);
            int notSoldStockOnCurrentDay =
                func(id + 1, 0, arr, n, dp, buyCount);

            profit = max(soldStockOnCurrentDay, notSoldStockOnCurrentDay);
        }

        return dp[id][buy][buyCount] = profit;
    }

   public:
    int stockBuySell(vector<int> arr, int n, int k) {
        int buyCount = k;
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int id = n - 1; id >= 0; id--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int buyCount = 1; buyCount <= k; buyCount++) {
                    if (buy) {
                        int boughtStockOnCurrentDay =
                            -arr[id] + dp[id + 1][0][buyCount];
                        int notBoughtStockOnCurrentDay =
                            dp[id + 1][1][buyCount];

                        dp[id][buy][buyCount] = max(boughtStockOnCurrentDay,
                                                    notBoughtStockOnCurrentDay);
                    } else {
                        int soldStockOnCurrentDay =
                            arr[id] + dp[id + 1][1][buyCount - 1];
                        int notSoldStockOnCurrentDay = dp[id + 1][0][buyCount];

                        dp[id][buy][buyCount] = max(soldStockOnCurrentDay,
                                                    notSoldStockOnCurrentDay);
                    }
                }
            }
        }

        return dp[0][1][k];
    }
};
