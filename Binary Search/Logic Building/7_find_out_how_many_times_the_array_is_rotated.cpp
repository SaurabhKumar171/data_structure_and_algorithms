#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    int findKRotation(vector<int> &arr)  {

      int l = 0;
      int h = arr.size() - 1;
      int ele = INT_MAX;
      int id = -1;

      while(l <= h){
        int m = l + (h-l)/2;
        
        // left sorted
        if(arr[m] >= arr[l]){
          if(ele > arr[l]){
            ele = arr[l];
            id = l;
          }
          l = m + 1;
        }
        else{
      
          if(ele > arr[m]){
            ele = arr[m];
            id = m;
          }
          h = m - 1;
        }
      }

      return id;
    }
};