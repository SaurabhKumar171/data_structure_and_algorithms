#include <iostream>
using namespace std;

int searchInNearlySortedArray(int arr[], int n, int target){
    int i = 0;
    int j = n - 1;

    while(i <= j){
      int m = i + (j - i)/2;

      if(arr[m] == target){
          return m;
      }
      else if(m + 1 < n && arr[m+1] == target){
          return m+1;
      }
      else if(m-1 >= 0 && arr[m-1] == target){
          return m-1;
      }
      else if(arr[m] < target){
          i = m + 2;
      }
      else{
          j = m - 2;
      }
    }

    return -1;
}