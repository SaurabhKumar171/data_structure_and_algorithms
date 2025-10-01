// Recursion
// Time Complexity:The time complexity is O(2^n) due to the recursive calls forming a binary tree.
// Space Complexity:The space complexity is O(n) due to the call stack depth during recursion.
#include <vector>
using namespace std;

class Solution {
private:
    int func(int id, vector<int>& heights){
        if(id == 0) return 0;

        int oneStep = func(id - 1, heights) + abs(heights[id] - heights[id - 1]);

        int twoStep = INT_MAX;
        if(id > 1) twoStep = func(id - 2, heights) + abs(heights[id] - heights[id - 2]);

        return min(oneStep, twoStep);
    }
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        return func(n - 1, heights);
    }
};


// Recursion + memoization
// Time Complexity: The time complexity is O(n) due to memoization avoiding redundant calculations.
// Space Complexity:The space complexity is O(n) due to the dp vector and recursion depth.
class Solution {
private:
    int func(int id, vector<int>& heights, vector<int>& dp){
        if(id == 0) return 0;
        if(dp[id] != -1) return dp[id];

        int oneStep = func(id - 1, heights, dp) + abs(heights[id] - heights[id - 1]);

        int twoStep = INT_MAX;
        if(id > 1) twoStep = func(id - 2, heights, dp) + abs(heights[id] - heights[id - 2]);

        return dp[id] =  min(oneStep, twoStep);
    }
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n, -1);
        return func(n - 1, heights, dp);
    }
};


// Tabulation
// Time Complexity: The time complexity is O(n) due to the single loop iterating through the heights array.
// Space Complexity: The space complexity is O(n) due to the dp vector storing the minimum energy costs.
class Solution {
   public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n, -1);
        // return func(heights, dp);

        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            int oneStep = abs(heights[i] - heights[i - 1]) + dp[i - 1];

            int twoStep = INT_MAX;
            if (i > 1) {
                twoStep = abs(heights[i] - heights[i - 2]) + dp[i - 2];
            }

            dp[i] = min(oneStep, twoStep);
        }

        return dp[n - 1];
    }
};



// Space Optimization
// Time Complexity: The time complexity is O(n) due to the single loop iterating through the heights array.
// Space Complexity: The space complexity is O(1) as only a constant amount of space is used for prev, prev2, and curr.
class Solution {
   public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();

        int prev = 0, prev2 = 0, curr = 0;
        for (int i = 1; i < n; i++) {
            int oneStep = abs(heights[i] - heights[i - 1]) + prev;

            int twoStep = INT_MAX;
            if (i > 1) {
                twoStep = abs(heights[i] - heights[i - 2]) + prev2;
            }

            curr = min(oneStep, twoStep);
            prev2 = prev;
            prev = curr; 
        }

        return prev;
    }
};