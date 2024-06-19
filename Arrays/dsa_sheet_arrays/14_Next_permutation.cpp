#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

void nextPermutation(vector<int>& nums) {

    int n = nums.size();
    int idx = -1;

    // find the point where an element is smlaare than next element
    for(int i = n-1; i > 0; i--){
        if(nums[i] > nums[i-1]){
            idx = i - 1;
            break;
        }
    }

    // reverse array if it is in decreasing order
    if(idx == -1){
        reverse(nums.begin(), nums.end());
    }
    else{
        // to find the element just greater than pivot
        int elementToSwap = idx + 1;
        for(int i = idx + 1; i < n; i++){

            if(nums[i] > nums[idx] && nums[i] <= nums[elementToSwap]){
                elementToSwap = i;
            }
        }

        // swap pivot and element just greater than pivot
        swap(nums[idx], nums[elementToSwap]);

        // reverse the array after the pivot element
        reverse(nums.begin() + idx + 1, nums.end());
    }

}