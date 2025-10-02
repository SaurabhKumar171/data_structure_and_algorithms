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