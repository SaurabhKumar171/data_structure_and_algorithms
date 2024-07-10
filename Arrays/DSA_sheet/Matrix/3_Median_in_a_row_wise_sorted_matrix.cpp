#include <iostream>
#include <vector>
using namespace std;

int median(vector<vector<int>> &matrix, int R, int C){
    // code here  

    vector<int> res;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            res.push_back(matrix[i][j]);
        }
    }

    sort(res.begin(), res.end());

    return res[(R*C)/2];
}