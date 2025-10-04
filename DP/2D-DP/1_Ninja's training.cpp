#include <vector>
using namespace std;

// Recursion + Memoization
// Time Complexity:O(n), where n is the number of days due to the dynamic programming approach with memoization.
// Space Complexity:O(n) due to the depth of the recursion stack and the dp table of size n x 4.
class Solution {
   private:
    int func(int day, int last, vector<vector<int>>& matrix,
             vector<vector<int>>& dp) {
        if (dp[day][last] != -1) return dp[day][last];

        if (day == 0) {
            int maxPoints = 0;
            for (int i = 0; i <= 2; i++) {
                if (i != last) maxPoints = max(maxPoints, matrix[0][i]);
            }

            return dp[day][last] = maxPoints;
        }

        int maxPoints = 0;
        for (int i = 0; i <= 2; i++) {
            if (i != last) {
                int points = matrix[day][i] + func(day - 1, i, matrix, dp);
                maxPoints = max(maxPoints, points);
            }
        }

        return dp[day][last] = maxPoints;
    }

   public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));

        return func(n - 1, 3, matrix, dp);
    }
};



// Tabulation
// Time Complexity:O(n) due to the outer loop iterating 'n' times and the inner loops iterating a constant number of times.
// Space Complexity:O(n) due to the usage of a 2D DP array of size n x 4.
class Solution {
   public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));

        dp[0][0] = max(matrix[0][1], matrix[0][2]);
        dp[0][1] = max(matrix[0][0], matrix[0][2]);
        dp[0][2] = max(matrix[0][0], matrix[0][1]);
        dp[0][3] = max(matrix[0][0], max(matrix[0][1], matrix[0][2]));

        for (int day = 1; day < n; day++) {
            for (int last = 0; last < 4; last++) {
                dp[day][last] = 0;

                for (int task = 0; task <= 2; task++) {
                    if (task != last) {
                        int activity = matrix[day][task] + dp[day - 1][task];

                        dp[day][last] = max(dp[day][last], activity);
                    }
                }
            }
        }

        return dp[n - 1][3];
    }
};


// Space Optimization
// Time Complexity: O(N*4*3). There are N*4 states and for every state, we are running a for loop iterating three times.
// Space Complexity:O(4), We are using an external array of size ‘4’ to store only one row.
class Solution {
   public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(4, 0);

        prev[0] = max(matrix[0][1], matrix[0][2]);
        prev[1] = max(matrix[0][0], matrix[0][2]);
        prev[2] = max(matrix[0][0], matrix[0][1]);
        prev[3] = max(matrix[0][0], max(matrix[0][1], matrix[0][2]));

        for (int day = 1; day < n; day++) {
            vector<int> temp(4, 0);
            for (int last = 0; last < 4; last++) {
                temp[last] = 0;

                for (int task = 0; task <= 2; task++) {
                    if (task != last) {
                        temp[last] =
                            max(temp[last], matrix[day][task] + prev[task]);
                    }
                }
            }
            prev = temp;
        }

        return prev[3];
    }
};