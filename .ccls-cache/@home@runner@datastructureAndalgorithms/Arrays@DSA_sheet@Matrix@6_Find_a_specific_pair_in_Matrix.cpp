#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

// Brute force (o(n^4)))
int specificPair1(int mat[][5], int n) {

  int maxDiff = INT_MIN;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1; j++) {

      for (int k = i + 1; k < n; k++) {
        for (int l = j + 1; l < n; l++) {
          if (k > i && l > j) {
            int diff = mat[k][l] - mat[i][j];
            maxDiff = max(maxDiff, diff);
          }
        }
      }
    }
  }

  return maxDiff;
}

// Optimal approach (o(n^2))
int specificPair(int mat[][5], int n){

    vector<vector<int>> maxMat(n, vector<int>(n));

    // store last element of matrix in new matMax
    maxMat[n-1][n-1] = mat[n-1][n-1];

    // store last row of matrix in new matMax
    for(int j = n-2; j >= 0; j--){
        maxMat[n-1][j] = max(maxMat[n-1][j+1], mat[n-1][j]);
    }

    // store last col of matrix in new matMax
    for(int i = n-2; i >= 0; i--){
        maxMat[i][n-1] = max(maxMat[i+1][n-1], mat[i][n-1]);
    }

    // store rest elements in new matMax
    for(int i = n-2; i >= 0; i--){
      for(int j = n-2; j >= 0; j--){
        maxMat[i][j] = max({maxMat[i+1][j], maxMat[i][j+1], mat[i][j]});
      }
    }

    int ans = INT_MIN;
    for(int i = 0; i < n-1; i++){
      for(int j = 0; j < n-1; j++){
        ans = max(ans, (maxMat[i+1][j+1] - mat[i][j]));
      }
    }

    return ans;
}