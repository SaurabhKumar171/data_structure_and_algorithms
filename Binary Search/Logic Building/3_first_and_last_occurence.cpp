#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution{
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        
        int firstOccur = firstOccurence(nums, target); 
        int lastOccur = lastOccurence(nums, target); 

        return {firstOccur, lastOccur};
    }

    int firstOccurence(vector<int> &nums, int target){
        
        int low = 0;
        int high = nums.size() - 1;
        int id = -1;

        while(low <= high){

            int mid = low + (high - low)/2;

            if(nums[mid] == target){
                id = mid;
                high = mid - 1;
            }
            else if(nums[mid] > target){
                high = mid - 1; 
            }
            else{
                low = mid + 1;
            }
        }

        return id;
    }

    int lastOccurence(vector<int> &nums, int target){
        
        int low = 0;
        int high = nums.size() - 1;
        int id = -1;

        while(low <= high){

            int mid = low + (high - low)/2;

            if(nums[mid] == target){
                id = mid;
                low = mid + 1;
            }
            else if(nums[mid] > target){
                high = mid - 1; 
            }
            else{
                low = mid + 1;
            }
        }

        return id;
    }
};