#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// Optimal approach [O(m+n)]
class Solution{
public:
 bool searchMatrix(vector<vector<int>> &mat, int target){

        int r = 0;
        int c = mat[0].size()-1;

        while(r < mat.size() && c >= 0){

            if(target == mat[r][c]) return true;
            else if(target > mat[r][c]) r++;
            else c--;
        }

        return false;   
    }
};

// Better approach [O( m * log(n) )]
class Solution{
public:
 bool searchMatrix(vector<vector<int>> &mat, int target){
        
        for(int i = 0; i < mat.size(); i++){  

            int l = 0; 
            int h = mat[i].size()-1;

            while(l <= h){
                int m = (l + h)/2;

                if(mat[i][m] == target) return true;
                else if(mat[i][m] < target) l = m + 1;
                else h = m - 1;
            }
        }

        return false;   
    }
};