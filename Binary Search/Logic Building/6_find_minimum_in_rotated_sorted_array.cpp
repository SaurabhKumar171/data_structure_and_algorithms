#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& arr) {
      
      int l = 0;
      int h = arr.size() - 1;
      int ele = INT_MAX;

      while(l <= h){
        int m = l + (h-l)/2;

        // left sorted
        if(arr[m] >= arr[l]){
            ele = min(ele, arr[l]);
            l = m + 1;
        }
        // right soretd
        else{
            ele = min(ele, arr[m]);
            h = m-1;
        }
      }

      return ele;        
    }
};