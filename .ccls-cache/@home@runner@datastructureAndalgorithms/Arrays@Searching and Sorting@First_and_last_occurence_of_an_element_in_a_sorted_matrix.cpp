#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int binarySearch(vector<int>& nums, int target, bool searchFirst){
    int i = 0;
    int j = nums.size() - 1;

    int result = -1;

    while(i <= j){
        int m = i + (j-i)/2;

        if(nums[m] == target){
            result = m;
            if(searchFirst){
                j = m - 1;
            }
            else{
                i = m + 1;
            }
        }
        else if(nums[m] > target){
            j = m - 1;
        }
        else{
            i = m + 1;
        }
    }

    return result;
}

vector<int> searchRange(vector<int>& nums, int target) {

    int firtsOccurence = binarySearch(nums, target, true);
    int secondOccurence = binarySearch(nums, target, false);

    return vector<int> {firtsOccurence, secondOccurence};
}