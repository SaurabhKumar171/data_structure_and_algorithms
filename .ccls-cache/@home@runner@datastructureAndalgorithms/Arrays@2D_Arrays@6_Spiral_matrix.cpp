#include <iostream>
#include <vector>
using namespace std;

void spiralOrderUsingRowChecks(vector<vector<int>>& matrix) {


    int top = 0;
    int left = 0;
    int bottom = matrix.size() - 1;
    int right = matrix[0].size() - 1;

    vector<int> res;

    while(top <= bottom && left <= right){

        // Print starting row
        for(int i = left; i <= right; i++){
            cout << matrix[top][i] << " ";
        }
        top++;

        // Print ending col
        for(int i = top; i <= bottom; i++){
            cout << matrix[i][right] << " ";
        }
        right--;

        // Print ending row
        if(top <= bottom){ // Check if there is a bottom row to traverse
            for(int i = right; i >= left; i--){
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }

        // Print starting col
        if(left <= right){ // Check if there is a left column to traverse
            for(int i = bottom; i >= top; i--){
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }

}


void spiralOrderUsingElementCount(vector<vector<int>>& matrix) {


    int top = 0;
    int left = 0;
    int bottom = matrix.size() - 1;
    int right = matrix[0].size() - 1;

    int count = 0;
    int total_elements = matrix.size() * matrix[0].size();

    // vector<int> res;

    while(count < total_elements){

        // Print starting row
        for(int i = left; i <= right && count < total_elements; i++){
            cout << matrix[top][i] << " ";
            count ++;
        }
        top++;

        // Print ending col
        for(int i = top; i <= bottom && count < total_elements; i++){
            cout << matrix[i][right] << " ";
            count ++;
        }
        right--;

        // Print ending row
        // if(top <= bottom){ // Check if there is a bottom row to traverse
            for(int i = right; i >= left && count < total_elements; i--){
                cout << matrix[bottom][i] << " ";
                count ++;
            }
            bottom--;
        // }

        // Print starting col
        // if(left <= right){ // Check if there is a left column to traverse
            for(int i = bottom; i >= top && count < total_elements; i--){
                cout << matrix[i][left] << " ";
                count ++;
            }
            left++;
        // }
    }

}