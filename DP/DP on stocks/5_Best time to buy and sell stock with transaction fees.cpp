#include <bits/stdc++.h>
using namespace std;


// Recursion + Memoization
// T.C: O(N)
// S.C: O(N)
class Solution {
   private:
    int func(int id, int buy, vector<int> arr, int n, vector<vector<int>>& dp, int fee) {
        if (id == n) return 0;

        if (dp[id][buy] != -1) return dp[id][buy];

        int profit = 0;

        if (buy) {
            int boughtStockOnCurrentDay =
                -arr[id] + func(id + 1, 0, arr, n, dp, fee);
            int notBoughtStockOnCurrentDay = func(id + 1, 1, arr, n, dp, fee);

            profit = max(boughtStockOnCurrentDay, notBoughtStockOnCurrentDay);
        } else {
            int soldStockOnCurrentDay = arr[id] + func(id + 1, 1, arr, n, dp, fee) - fee;
            int notSoldStockOnCurrentDay = func(id + 1, 0, arr, n, dp, fee);

            profit = max(soldStockOnCurrentDay, notSoldStockOnCurrentDay);
        }

        return dp[id][buy] = profit;
    }

   public:
    int stockBuySell(vector<int> arr, int n, int fee) {
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return func(0, 1, arr, n, dp, fee);
    }
};


// Tabulation
// Time Complexity:O(n) due to the single loop iterating from n-1 down to 0.
// Space Complexity:O(n) because of the dp table of size (n+1)*2.
class Solution {
   public:
    int stockBuySell(vector<int> arr, int n, int fee) {
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        dp[n][0] = dp[n][1] = 0;

        int profit = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    int boughtStockOnCurrentDay = -arr[i] + dp[i + 1][0];
                    int notBoughtStockOnCurrentDay = dp[i + 1][1];

                    profit = max(boughtStockOnCurrentDay,
                                 notBoughtStockOnCurrentDay);
                } else {
                    int soldStockOnCurrentDay = arr[i] + dp[i + 1][1] - fee;
                    int notSoldStockOnCurrentDay = dp[i + 1][0];

                    profit =
                        max(soldStockOnCurrentDay, notSoldStockOnCurrentDay);
                }

                dp[i][buy] = profit;
            }
        }

        return dp[0][1];
    }
};


// Space Optimization
// Time Complexity:O(n) due to the single loop iterating from n-1 down
// Space Complexity:O(1) as we are using constant space.
class Solution {
   public:
    int stockBuySell(vector<int> arr, int n, int fee) {
        int profit = 0;

        vector<int> prev(2, 0);
        for (int i = n - 1; i >= 0; i--) {
            vector<int> temp(2);
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    int boughtStockOnCurrentDay = -arr[i] + prev[0];
                    int notBoughtStockOnCurrentDay = prev[1];

                    profit = max(boughtStockOnCurrentDay,
                                 notBoughtStockOnCurrentDay);
                } else {
                    int soldStockOnCurrentDay = arr[i] + prev[1] - fee;
                    int notSoldStockOnCurrentDay = prev[0];

                    profit =
                        max(soldStockOnCurrentDay, notSoldStockOnCurrentDay);
                }

                temp[buy] = profit;
            }

            prev = temp;
        }

        return prev[1];  
    }
};
