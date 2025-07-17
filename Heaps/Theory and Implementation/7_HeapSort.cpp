#include <iostream>
#include <vector>
using namespace std;

//Approach :  O(nlogn) time complexity , O(1) space complexity
class Solution {
private:
    void heapifyDownMaxHeap(vector<int>&nums, int id, int n){
        int largest = id;
        int left = 2*id + 1, right = 2*id + 2;

        if(left < n && nums[left] > nums[largest]) largest = left;
        if(right < n && nums[right] > nums[largest]) largest = right;

        if(largest != id){
            swap(nums[largest], nums[id]);
            heapifyDownMaxHeap(nums, largest, n);
        }

        return;
    }
public:
    void heapSort(vector<int>&nums) {
        int n = nums.size();
        for(int i = n/2 - 1; i >= 0; i--){
            heapifyDownMaxHeap(nums, i, n);
        }

        for(int i = n - 1; i >= 1; i--){
            swap(nums[i], nums[0]);
            heapifyDownMaxHeap(nums, 0, i);
        }
    }
};