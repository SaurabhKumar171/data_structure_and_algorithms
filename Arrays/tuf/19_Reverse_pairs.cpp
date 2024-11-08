#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        
        int n = nums.size();

        int cnt = mergeSort(nums, 0, n - 1);

        return cnt;
    }

    int mergeSort(vector<int>& nums, int low, int high){

        int cnt = 0;

        if(low < high){

            int mid = low + (high -low)/2;

            cnt += mergeSort(nums, low, mid);

            cnt += mergeSort(nums, mid+1, high);

            cnt += countPairs(nums, low, mid, high);

            merge(nums, low, mid, high);

        }

        return cnt;
    }

    int merge(vector<int>& nums, int low, int mid, int high){

        int left = low;
        int right = mid+1;

        int cnt = 0;

        vector<int> temp;

        int i = left;
        int j = right;

        while(left <= mid && right <= high){

            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++; 
            }
        }

        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i = low; i <= high; i++){
            nums[i] = temp[i - low];
        }

        return cnt;
    }

    int countPairs(vector<int> &arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;
        
        for (int i = low; i <= mid; i++) {
            
            /*while right is less than equal to high 
           and arr[i] is greater than 2 * arr[right] 
           then increment right by 1*/
            while (right <= high && (long long)arr[i] > 2LL * arr[right]) {
                right++;
            }
            
            cnt += (right - (mid + 1));
        }
        //Return the count
        return cnt;
    }
};