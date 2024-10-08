#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution1 {
public:
   long long int numberOfInversions(vector<int> nums) {

        int n = nums.size();

        int low = 0;
        int high = nums.size() - 1;

        long long int inversionCount = mergeSortHelper(nums, 0, high);

        return inversionCount;
    }

    long long int mergeSortHelper(vector<int> &nums, int low, int high){
 
        long long int cnt = 0;

        if(low < high){
            int mid = (low + high)/2;

            cnt += mergeSortHelper(nums, low, mid);

            cnt += mergeSortHelper(nums, mid + 1, high);

            cnt += merge(nums, low, mid, high);
        }

        return cnt;
    }

    long long int merge(vector<int> &nums, int low, int mid, int high){

        int left = low;
        int right = mid + 1;
        long long int inversionCount = 0;

        vector<int> temp;

        while(left <= mid && right <= high){

            if(nums[left] <= nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                inversionCount += (mid - left + 1);;

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

        return inversionCount;
    }
};