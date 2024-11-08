#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix) {

  if (matrix.empty())
    return {};

  int top = 0;
  int left = 0;
  int bottom = matrix.size() - 1;
  int right = matrix[0].size() - 1;

  int count = 0;
  int total_elements = matrix.size() * matrix[0].size();

  vector<int> res;

  while (count < total_elements) {

    // Print starting row
    for (int i = left; i <= right && count < total_elements; i++) {
      res.push_back(matrix[top][i]);
      count++;
    }
    top++;

    // Print ending col
    for (int i = top; i <= bottom && count < total_elements; i++) {
      res.push_back(matrix[i][right]);
      count++;
    }
    right--;

    // Print ending row
    // if(top <= bottom){ // Check if there is a bottom row to traverse
    for (int i = right; i >= left && count < total_elements; i--) {
      res.push_back(matrix[bottom][i]);
      count++;
    }
    bottom--;
    // }

    // Print starting col
    // if(left <= right){ // Check if there is a left column to traverse
    for (int i = bottom; i >= top && count < total_elements; i--) {
      res.push_back(matrix[i][left]);
      count++;
    }
    left++;
    // }
  }

  return res;
}