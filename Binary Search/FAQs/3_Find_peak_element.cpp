// Optimal force ( Binary search )
class Solution {
public:
    int findPeakElement(vector<int>& arr) {
      
      int n = arr.size();

      if(n == 1 || arr[0] > arr[1]) return 0;
      else if(arr[n-1] > arr[n-2]) return n-1;

      int low = 1;
      int high = n - 2;

      while(low <= high){ 
        int mid = low + (high - low)/2;

        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
            return mid;
        }
        else if(arr[mid] > arr[mid - 1]){
          low = mid + 1;
        }
        else{
          high = mid - 1;
        }
      }

      return -1;    
    }
};
 

// Brute force ( Linear search )
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution1 {
public:
    int findPeakElement(vector<int> &arr) {

      int n = arr.size();
      
      for(int i = 0; i < n; i++){ 

        if((i == 0 || arr[i] > arr[i-1]) && (i == n - 1 || arr[i] > arr[i+1])){
            return i;
        }
      }

      return -1;  
    }
};


class Solution {
public:
    int findPeakElement(vector<int>& arr) {
      
      int n = arr.size();

      if(n == 1 || arr[0] > arr[1]) return 0;
      else if(arr[n-1] > arr[n-2]) return n-1;

      int low = 1;
      int high = n - 2;

      while(low <= high){ 
        int mid = low + (high - low)/2;

        if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
            return mid;
        }
        else if(arr[mid] > arr[mid - 1]){
          low = mid + 1;
        }
        else{
          high = mid - 1;
        }
      }

      return -1;    
    }
};