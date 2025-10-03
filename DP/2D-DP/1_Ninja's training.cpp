#include <vector>
using namespace std;

// Recursion + Memoization
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