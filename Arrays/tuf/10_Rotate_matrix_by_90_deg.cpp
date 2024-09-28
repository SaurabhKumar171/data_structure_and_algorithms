#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        
        transPose(matrix);

        reverseMatrix(matrix);
    }

    void transPose(vector<vector<int>>& matrix){

        for(int i = 0; i < matrix.size(); i++){

            for(int j = i; j < matrix[i].size(); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void reverseMatrix(vector<vector<int>>& matrix){
        int i = 0;
        int j = matrix[0].size() - 1;

        while(i < j){

            for(int k = 0; k < matrix.size(); k++){
                swap(matrix[k][i], matrix[k][j]);
            }

            i++;
            j--;
        }
    }
};