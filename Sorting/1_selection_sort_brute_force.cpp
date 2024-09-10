class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        int n = nums.size();
        
        for(int i = 0; i < n-1; i++){

            int minId = i;

            for(int j = i; j < n; j++){

                if(nums[j] < nums[minId]){
                    minId = j;
                }

            }

            if(minId != i){
                swap(nums[minId], nums[i]);
            }
        }

        return nums;
    }
};