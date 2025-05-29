// Brute Force Approach : O(n^2) time complexity, O(1) space complexity
class Solution {
    public:
        int sumSubarrayMins(vector<int> &arr) {
            int n = arr.size();
            int totalSum = 0;
            int mod = 1e9 + 7;
    
            for(int i = 0; i < n; i++){
                int minVal = arr[i];
                for(int j = i; j < n; j++){
                    minVal = min(minVal, arr[j]);
                    totalSum = (totalSum + minVal) % mod;
                }
            }
            
    
            return totalSum;
        }
    };
    