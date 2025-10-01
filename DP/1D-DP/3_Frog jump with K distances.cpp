
#include <vector>
using namespace std;

// Recursion
// Time Complexity:O(n*k), where n is the number of heights and k is the maximum jump distance.
// Space Complexity:O(n), due to the maximum depth of the recursion stack.
class Solution {
   private:
    int func(int id, vector<int>& heights, int k) {
        if (id == 0) return 0;

        int res = INT_MAX;
        for (int i = id - 1; i >= id - k; i--) {
            if (i >= 0) {
                int steps = func(i, heights, k) + abs(heights[id] - heights[i]);
                res = min(res, steps);
            }
        }
        return res;
    }

   public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        return func(n - 1, heights, k);
    }
};



// Recursion + Memoization
// Time Complexity:O(n*k), where n is the number of heights and k is the maximum jump distance.
// Space Complexity:O(n), due to the maximum depth of the recursion stack and the dp array.
class Solution {
   private:
    int func(int id, vector<int>& heights, int k, vector<int>& dp) {
        if (id == 0) return 0;

        if(dp[id] != -1) return dp[id];

        int res = INT_MAX;
        for (int i = id - 1; i >= id - k; i--) {
            if (i >= 0) {
                int steps = func(i, heights, k, dp) + abs(heights[id] - heights[i]);
                res = min(res, steps);
            }
        }

        dp[id] = res;

        return res;
    }

   public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, -1);
        return func(n - 1, heights, k, dp);
    }
};

// Tabulation
// Time Complexity:O(n*k), where n is the number of heights and k is the maximum jump distance.
// Space Complexity:O(n), due to the dp array.  
class Solution {
   public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n);

        dp[0] = 0;
        for(int i = 1; i < n; i++){
            int res = INT_MAX;


            for(int j = i - 1; j >= i - k; j--){
                if(j >= 0){
                    int steps = abs(heights[i] - heights[j]) + dp[i - (i - j)];
                    res = min(res, steps);
                }
            }

            dp[i] = res;
        }

        return dp[n - 1];
    }
};
