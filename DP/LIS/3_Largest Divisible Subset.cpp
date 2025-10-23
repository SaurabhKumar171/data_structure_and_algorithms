#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N^2), where N is the size of the given array.
// Space Complexity: O(N), because of two arrays (dp and parent) used, each of size N.

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();

        sort(arr.begin(), arr.end());

        vector<int> dp(n, 1), hash(n);
        int maxLen = 0, lastIndex = 0;

        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (arr[i] % arr[prev] == 0 && dp[i] < dp[prev] + 1) {
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }

            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        int i = lastIndex;
        vector<int> ans;
        ans.push_back(arr[lastIndex]);
        while (lastIndex != hash[lastIndex]) {
            lastIndex = hash[lastIndex];
            ans.push_back(arr[lastIndex]);
        }

        reverse(ans.begin(), ans.end());

        return ans;        
    }
};