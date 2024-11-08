// Optimal Approach ( Binary search )
class Solution {
private:
    int allocStudents(vector<int> &nums, int currMaxPages){
        int n = nums.size();
        int pageCnt = 0;
        int student = 1;

        for(int i = 0; i < n; i++){
            
            if(pageCnt + nums[i] <= currMaxPages){
                pageCnt += nums[i];
            }
            else{
                student++;
                pageCnt = nums[i];
            }
        }

        return student;
    }

public:
    int findPages(vector<int> &nums, int m)  {

       int n = nums.size();

        if (m > n) return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

       while(low <= high){

        int mid = low + (high - low)/2;

        int studentCount = allocStudents(nums, mid);

        if(studentCount > m){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
       } 

       return low;
    }
};


// Brute force ( Linear search )
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include <numeric>
using namespace std;

class Solution {
private:
    int allocStudents(vector<int> &nums, int currMaxPages){
        int n = nums.size();
        int pageCnt = 0;
        int student = 1;

        for(int i = 0; i < n; i++){
            
            if(pageCnt + nums[i] <= currMaxPages){
                pageCnt += nums[i];
            }
            else{
                student++;
                pageCnt = nums[i];
            }
        }

        return student;
    }

public:
    int findPages(vector<int> &nums, int m)  {

       int n = nums.size();

        if (m > n) return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

       for(int i = low; i <= high; i++){

        int studentCount = allocStudents(nums, i);
        
        if(studentCount == m){
            return i;
        }
       } 

       return low;
    }
};