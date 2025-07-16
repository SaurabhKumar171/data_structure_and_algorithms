#include <iostream>
#include <vector>
using namespace std;

//Approach :  O(N) time complexity , O(log) space complexity - due to the recursive calls in heapifyDown
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

public:
    void buildMinHeap(vector<int> &nums) {
        int n = nums.size();
        for(int i = n - 1; i >= 0; i--){
            heapifyDown(nums, i, n);
        }
    }
};