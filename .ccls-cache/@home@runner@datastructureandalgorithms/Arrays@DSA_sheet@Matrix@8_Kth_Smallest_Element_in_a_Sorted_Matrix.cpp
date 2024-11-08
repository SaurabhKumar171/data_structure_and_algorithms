#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {

  int n = matrix.size();

  int l = matrix[0][0];
  int h = matrix[n-1][n-1];

  while(l < h){
      int mid = l + (h-l)/2;
      int cnt = count(matrix, n, mid);

      if(cnt >= k){
          h = mid;
      }
      else{
          l = mid + 1;
      }
  }

  return l;
}

int count(vector<vector<int>>& mat, int n, int mid){

  int count = 0;
  for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
          if(mat[i][j] <= mid)
              count++;
      }
  }

  return count;
}