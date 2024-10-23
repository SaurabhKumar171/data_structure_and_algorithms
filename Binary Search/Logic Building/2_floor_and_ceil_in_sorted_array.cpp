#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
   
        int floor = lowerBound(nums, x);
        int ceil = upperBound(nums, x);

        return {floor, ceil};
    }

    int lowerBound(vector<int> nums, int x){

        int low = 0;
        int high = nums.size() - 1;
        int ele = -1;

        while(low <= high){

            int mid = low + (high - low)/2;

            if(nums[mid] > x){
                high = mid - 1; 
            }
            else{
                ele = nums[mid];
                low = mid + 1;
            }
        }

        return ele;
    }

    int upperBound(vector<int> nums, int x){

        int low = 0;
        int high = nums.size() - 1;
        int ele = -1;

        while(low <= high){

            int mid = low + (high - low)/2;

            if(nums[mid] >= x){
                ele = nums[mid];
                high = mid - 1; 
            }
            else{
                low = mid + 1;
            }
        }

        return ele;
    }
};