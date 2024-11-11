#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// Brute force [O(n^2)]
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int r = mat.size();
        int c = mat[0].size();

        int row = -1;
        int col = -1;

        int greatestElement = INT_MIN;

        for(int i = 0; i < r; i++){

            for(int j = 0; j < c; j++){

                if(greatestElement < mat[i][j]){
                    greatestElement = mat[i][j];
                    row = i;
                    col = j; 
                }
            }
        }

        return {row, col};
    }
};