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