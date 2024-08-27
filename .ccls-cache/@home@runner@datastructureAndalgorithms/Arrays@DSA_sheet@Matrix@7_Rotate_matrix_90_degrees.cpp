#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> &matrix) {
  int n = matrix.size();

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int t = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = t;
    }
  }

  for (int i = 0; i < n; i++) {
    int s = 0;
    int l = n - 1;
    while (s < l) {
      swap(matrix[i][s], matrix[i][l]);
      s++;
      l--;
    }
  }
}