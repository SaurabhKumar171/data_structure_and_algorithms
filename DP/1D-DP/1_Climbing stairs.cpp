
#include <iostream>
#include <vector>
using namespace std;

// Recursion
class Solution {
   private:
    int func(int n, vector<int>& dp) {
        if (n == 0)
            return 1;
        else if (n < 0)
            return 0;

        int left;
        if (dp[n - 1] != -1) {
            left = dp[n - 1];
        } else {
            left = func(n - 1, dp);
            dp[n - 1] = left;
        }

        int right;
        if (dp[n - 2] != -1) {
            right = dp[n - 2];
        } else {
            right = func(n - 2, dp);
            dp[n - 2] = right;
        }

        return left + right;
    }

   public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return func(n, dp);
    }

};