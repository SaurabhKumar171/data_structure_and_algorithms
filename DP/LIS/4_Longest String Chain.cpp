#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N^2), where N is the size of the given array.
// Space Complexity: O(N), because of two arrays (dp and parent) used, each of size N.

class Solution {
private:
    bool checkPossible(string &s, string &t) {
        //  Base case
        if (s.size() != t.size() + 1) return false;

        int i = 0, j = 0;  // Pointers

        // Traverse until the first string is exhausted
        while (i < s.size()) {
            // Move both pointers if characters matches
            if (j < t.size() && s[i] == t[j]) {
                i++, j++;
            }
            // Otherwise
            else {
                i++;
            }
        }

        // Return true if both the string gets exhausted
        if (i == s.size() && j == t.size()) return true;
        return false;  // Return false otherwise
    }
public:
    int longestStrChain(vector<string>& arr) {
        int n = arr.size();

        sort(arr.begin(), arr.end(),
             [](string &s, string &t) { return s.size() < t.size(); });

        vector<int> dp(n, 1), hash(n);
        int maxLen = 0, lastIndex = 0;

        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (checkPossible(arr[i], arr[prev]) && dp[i] < dp[prev] + 1) {
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }

            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        return maxLen;        
    }
};