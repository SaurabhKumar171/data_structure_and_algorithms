// Brute Force Approach : O(n^2) time complexity, O(1) space complexity
class Solution {
    public:
        long long subArrayRanges(vector<int>& nums) {
            
            int n = nums.size();
            long long totalSum = 0;
    
            for(int i = 0; i < n; i++){
    
                int maximum = nums[i]; 
                int minimum = nums[i]; 
    
                for(int j = i; j < n; j++){
                    maximum = max(maximum, nums[j]);
                    minimum = min(minimum, nums[j]);
    
                    totalSum += (maximum - minimum)*1LL;
                }
            }
    
            return totalSum;
        }
    };