class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){

            int mid = low + (high - low)/2;
            
            if(nums[mid] > x){
                high = mid - 1; 
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};