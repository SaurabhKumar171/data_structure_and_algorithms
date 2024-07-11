#include <iostream>
#include <limits.h>
using namespace std;

// Brute force (o(n^2)))
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