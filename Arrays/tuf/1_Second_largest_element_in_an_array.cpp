class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        //your code goes here
      int n = nums.size();
      sort(nums.begin(), nums.end());
    
      int secondLargetElementIndex = n - 2;

      while(secondLargetElementIndex >= 0){
        
        if(nums[secondLargetElementIndex] == nums[secondLargetElementIndex + 1]){
            secondLargetElementIndex--;
        }
        else{
            return nums[secondLargetElementIndex];
        }
      }

      return -1;
    }
};
