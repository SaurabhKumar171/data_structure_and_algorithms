#include <vector>
using namespace std;

// Recursion + Memoization

// Time Complexity:The time complexity is O(n) because of the memoization, which avoids recomputing the results for the same subproblems.
// Space Complexity:The space complexity is O(n) due to the two dp vectors used to store computed values and the recursive call stack.
class Solution {
    int func(int id, vector<int>& money, int n, vector<int>& dp){
        if(id == 0) return money[id];
        if(id < 0) return 0;

        if(dp[id] != -1) return dp[id];

        int pick = func(id - 2, money, n, dp) + money[id];
        int notPick = func(id - 1, money, n, dp) + 0;

        return dp[id] = max(pick, notPick);
    }
public:
    int houseRobber(vector<int>& money) {
        int n = money.size();

        if(n == 1) return money[0];

        // ignore last house
        vector<int> dp(n, -1);
        int ans = func(n - 2, money, n, dp); 

        // ignore first house
        vector<int> dp2(n, -1);
        vector<int> money2(money.begin() + 1, money.end());

        ans = max(ans, func(n - 2, money2, n, dp2));

        return ans;
    }
};



// Tabulation
// Time Complexity: O(n) where n is the number of houses. We iterate through the list of houses once to fill the dp array.
// Space Complexity: O(n) for the dp array used to store the maximum money that can be robbed up to each house.
class Solution {
    int func(vector<int>& nums) {
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
public:
    int houseRobber(vector<int>& money) {
        int n = money.size();
        if(n == 1) return money[0];

       vector<int> temp1, temp2;
       for(int i = 0; i < n; i++){
        if(i != 0) temp1.push_back(money[i]);
        if(i != n - 1) temp2.push_back(money[i]);
       }

        return max(func(temp1), func(temp2));
    }
};


// Space Optimization
// Time Complexity: O(n) where n is the number of houses. We iterate through the list of houses once.
// Space Complexity: O(1) since we are using only a constant amount of extra space.
class Solution {
    int func(vector<int>& nums) {
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
public:
    int houseRobber(vector<int>& money) {
        int n = money.size();
        if(n == 1) return money[0];

       vector<int> temp1, temp2;
       for(int i = 0; i < n; i++){
        if(i != 0) temp1.push_back(money[i]);
        if(i != n - 1) temp2.push_back(money[i]);
       }

        return max(func(temp1), func(temp2));
    }
};