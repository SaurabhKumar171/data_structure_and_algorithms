#include <iostream>
#include <vector>
using namespace std;

//Approach :  O(nlogn) time complexity , O(logn) space complexity
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
    int kthLargestElement(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = n/2 - 1; i >= 0; i--){
            heapifyDownMaxHeap(nums, i, n);
        }

        for(int i = n - 1; i >= 1; i--){
            swap(nums[i], nums[0]);
            heapifyDownMaxHeap(nums, 0, i);
        }

        return nums[n - k];
    }
};


//Approach :  O(nlogn) time complexity , O(n) space complexity
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> maxHeap; 

        for(int i = 0; i < n; i++){
            maxHeap.push(nums[i]);
        }

        for(int i = 0; i < k - 1; i++){
            maxHeap.pop();
        }

        return maxHeap.top();
    }
};