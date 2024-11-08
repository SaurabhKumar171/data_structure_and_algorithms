#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int r = matrix.size();
        int c = matrix[0].size();

        vector<int> result;
        int top = 0;
        int right = c - 1;
        int bottom = r - 1;
        int left = 0;


        while(top <= bottom && left <= right){

            for(int i = left; i <= right; i++){
                result.push_back(matrix[top][i]);
            }
            top++;

            for(int i = top; i <= bottom; i++){
                result.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                for(int i = right; i >= left; i--){
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right) {
                for(int i = bottom; i >= top; i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        
        return result;
    }
};