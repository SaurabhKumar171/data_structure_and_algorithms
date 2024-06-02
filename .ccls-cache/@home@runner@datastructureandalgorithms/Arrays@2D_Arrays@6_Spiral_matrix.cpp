#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {

    if (matrix.empty()) return {};

    int top = 0;
    int left = 0;
    int bottom = matrix.size() - 1;
    int right = matrix[0].size() - 1;

    vector<int> res;

    while(top <= bottom && left <= right){

        // Print starting row
        for(int i = left; i <= right; i++){
            res.push_back(matrix[top][i]);
        }
        top++;

        // Print ending col
        for(int i = top; i <= bottom; i++){
            res.push_back(matrix[i][right]);
        }
        right--;

        // Print ending row
        if(top <= bottom){ // Check if there is a bottom row to traverse
            for(int i = right; i >= left; i--){
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Print starting col
        if(left <= right){ // Check if there is a left column to traverse
            for(int i = bottom; i >= top; i--){
                res.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return res;
}