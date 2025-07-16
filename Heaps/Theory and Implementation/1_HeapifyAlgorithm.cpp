#include <iostream>
#include <vector>
using namespace std;

//Approach :  O(log) time complexity - heapifyDown and heapifyUp have a logarithmic time complexity due to the height of the heap, O(log) space complexity - due to the recursive calls in heapifyDown or heapifyUp
class Solution {
private:
    void heapifyDown(vector<int> &nums, int ind, int n){
        int left = 2*ind + 1;
        int right = 2*ind + 2;

        int smallest = ind;
        if(left < n && nums[left] < nums[smallest]) smallest = left;
        if(right < n && nums[right] < nums[smallest]) smallest = right;

        if(smallest != ind){
            swap(nums[smallest], nums[ind]);
            heapifyDown(nums, smallest, n);
        }

        return;
    }

    void heapifyUp(vector<int> &nums, int ind, int n){
        int parent = (ind - 1)/2;

        if(ind > 0){
            if(nums[parent] > nums[ind]){
                swap(nums[parent], nums[ind]);
                heapifyUp(nums, parent, n);
            }
        }

        return;
    }

public:
    void heapify(vector<int> &nums, int ind, int val) {
        int n = nums.size();

        if(nums[ind] > val){
            nums[ind] = val;
            heapifyUp(nums, ind, n);
        }
        else{
            nums[ind] = val;
            heapifyDown(nums, ind, n);
        }

        return;
    }
};