
#include <iostream>
#include <vector>
using namespace std;

// Recursion
// Time Complexity:The time complexity is O(2^n) due to the recursive calls forming a binary tree.
// Space Complexity:The space complexity is O(n) due to the call stack depth during recursion and the vector dp.
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


// Recursion + memoization
// Time Complexity: The time complexity is O(n) due to memoization avoiding redundant calculations.
// Space Complexity:The space complexity is O(n) due to the dp vector and recursion depth.
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


// Tabulation
// Time Complexity: The time complexity is O(n) due to the single loop iterating from 2 to n.
// Space Complexity: The space complexity is O(n) due to the dp vector storing results for each step.
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 1, dp[1] = 1;

        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

// Space Optimization
// Time Complexity: The time complexity is O(n) due to the single loop iterating from 2 to n.
// Space Complexity: The space complexity is O(1) as it uses only a constant amount of space for prev and prev2.
class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1, prev = 1;

        for(int i = 2; i <= n; i++){
            int curr = prev + prev2;
            prev2 = prev;
            prev = curr; 
        }

        return prev;
    }
};