// Brute force
class Solution {
public:
    void moveZeroesBruteForce(vector<int>& nums) {

        int n = nums.size();

        vector<int> temp;

        for(int i = 0; i < n; i++){
            if(nums[i] != 0) temp.push_back(nums[i]);
        }

        fill(nums.begin(), nums.end(), 0);

        for(int i = 0; i < temp.size(); i++){
            nums[i] = temp[i];
        }
    }
};