#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int k) {
       
       int low = 0;
       int high = nums.size() - 1;

       while(low <= high){

        int mid = low + (high - low)/2;

        if(nums[mid] == k) return mid;
        
        // Check if the left part is sorted
        if(nums[mid] >= nums[low]){
            if(k >= nums[low] && k <= nums[mid]) high = mid - 1;
            else low = mid + 1;
        }
        else{
            // Check if the right part is sorted
            if(k >= nums[mid] && k <= nums[high]) low = mid + 1;
            else high = mid - 1;
        }
       }

       return -1;
    }
};