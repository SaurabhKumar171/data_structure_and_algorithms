#include <vector>
using namespace std;

// Recursion + Memoization
// Time Complexity:O(n), where n is the number of elements in the array.
// Space Complexity:O(n), due to the maximum depth of the recursion stack and the dp array.
class Solution {
private:
    int func(int index, int n, vector<int>& nums, vector<int>& dp){
        if(index == 0) return nums[index];
        if(index < 0) return 0;

        if(dp[index] != -1) return dp[index];

        int pick = func(index - 2, n, nums, dp) + nums[index];
        int notPick = func(index - 1, n, nums, dp) + 0;

        return dp[index] = max(pick, notPick);
    }
public:
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return func(n - 1, n, nums, dp);
    }
};


// Tabulation
// Time Complexity:O(n), where n is the number of elements in the array.
// Space Complexity:O(n), due to the dp array.
class Solution {
public:
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        dp[0] = nums[0];
        for(int i = 1; i < n; i++){
            
            int pick = nums[i];
            if(i > 1) pick += dp[i - 2];

            int notPick = 0 + dp[i - 1];
            dp[i] = max(pick, notPick);
        }

        return dp[n - 1];
    }
};

// Space Optimization
// Time Complexity:O(n), where n is the number of elements in the array.
// Space Complexity:O(1), as no extra space is used.
class Solution {
   public:
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();

        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++) {
            int pick = nums[i];
            if (i > 1) pick += prev2;

            int notPick = 0 + prev;

            int cur_i = max(pick, notPick);
            prev2 = prev;
            prev = cur_i;
        }

        return prev;
    }
};