class Solution {
public:
    vector<int> insertionSort(vector<int>& nums) {

        for(int i = 0; i < nums.size(); i++){

            int j = i;

            while(j > 0 && nums[j-1] > nums[j]){
                swap(nums[j-1], nums[j]);
                j--;
            }
        }

        return nums;
    }
};
   