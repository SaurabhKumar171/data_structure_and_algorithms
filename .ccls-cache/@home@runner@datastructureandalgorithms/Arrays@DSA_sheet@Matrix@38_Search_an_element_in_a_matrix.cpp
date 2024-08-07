#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {

  int r = matrix.size();
  int c = matrix[0].size();

  int i = 0;
  int j = c - 1;

  while (i < r && j >= 0) {
    if (matrix[i][j] < target) {
      i++;
    } else if (matrix[i][j] > target) {
      j--;
    } else {
      return true;
    }
  }

  return false;
}