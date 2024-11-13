#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


// Optimal Approach (r * log(c))
class Solution {
private:
    int max_ele(vector<vector<int>>& mat, int col){

        int maxEle = mat[0][col];
        int maxId = 0;

        for(int i = 0; i < mat.size(); i++){
            if(mat[i][col] >= maxEle){

                maxEle = mat[i][col];
                maxId = i;
            }
        }
        return maxId;
    }

public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();

        int l = 0;
        int h = c - 1;

        while(l <= h){
            int m = (l + h)/2;

            int maxRowId = max_ele(mat, m);

            int left = (m > 0) ? mat[maxRowId][m-1] : INT_MIN;
            int right = (m < c -1) ? mat[maxRowId][m+1] : INT_MIN;

            if(mat[maxRowId][m] > left && mat[maxRowId][m] > right){
                return {maxRowId, m};
            }
            else if(mat[maxRowId][m] < right){
                l = m + 1;
            }
            else{
                h = m - 1;
            }
        }

        return {-1 , -1};     
    }
};


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