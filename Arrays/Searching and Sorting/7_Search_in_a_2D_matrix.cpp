#include <iostream>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int r = matrix.size();
    int c = matrix[0].size();

    int i = 0;
    int j = (r*c) - 1;

    while(i <= j){
        int m = i + (j - i)/2;

        int row = m/c;
        int col = m%c;

        if(matrix[row][col] == target){
            return true;
        }
        else if(matrix[row][col] > target){
            j = m - 1;
        }
        else{
            i = m + 1;
        }
    }

    return false;
}