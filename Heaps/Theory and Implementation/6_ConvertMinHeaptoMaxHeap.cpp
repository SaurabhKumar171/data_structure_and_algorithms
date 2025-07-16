#include <iostream>
#include <vector>
using namespace std;

//Approach :  O(n) time complexity , O(1) space complexity
class Solution {
private:
    void heapifyDown(vector<int> &nums, int ind, int n){
        int left = 2*ind + 1;
        int right = 2*ind + 2;

        int largest = ind;
        if(left < n && nums[left] > nums[largest]) largest = left;
        if(right < n && nums[right] > nums[largest]) largest = right;

        if(largest != ind){
            swap(nums[largest], nums[ind]);
            heapifyDown(nums, largest, n);
        }

        return;
    }
public:
    vector<int> minToMaxHeap(vector<int> nums) {
        int n = nums.size();
        for(int i = n/2 - 1; i >= 0; i--){
            heapifyDown(nums, i , n);
        }

        return nums;
    }
};