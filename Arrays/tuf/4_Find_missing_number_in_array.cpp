// Better Approach
class Solution2 {
public:
    int missingNumberBetterApproach(vector<int>& nums) {
        
        int n = nums.size();
        int sumOfNNumbers = (n*(n+1))/2;

        int totalSum = 0;

        for(int i : nums){
            totalSum += i;
        }

        return sumOfNNumbers - totalSum;
    }
};

// Optimal Approach - I
class Solution {
public:
    int missingNumberOptimalApproachI(vector<int>& nums) {
        
        int n = nums.size();
        vector<bool> track(nums.size() + 1, false);

        for(int i = 0; i < n; i++){
            track[nums[i]] = true;
        }

        for(int i = 0; i < n; i++){
            if(!track[i]){
                return i;
            }
        }

        return nums.size();
    }
};

// Optimal Approach - II
class Solution {
public:
    int missingNumberOptimalApproachII(vector<int>& nums) {
        
        int n = nums.size();

        int xor1 = 0;
        for(int i = 1; i <= n; i++){
            xor1 ^= i; 
        }

        for(int i = 0; i < n; i++){
            xor1 ^= nums[i]; 
        }

        return xor1;
    }
};