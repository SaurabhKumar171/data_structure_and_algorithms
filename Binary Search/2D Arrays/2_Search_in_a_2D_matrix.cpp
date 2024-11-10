#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// Optimal approach [O( m * log(n) )]
class Solution{
private:
    bool binarySearch(vector<int> a, int x){
        int l = 0; 
        int h = a.size()-1;
        
        while(l <= h){
            int m = (l + h)/2;

            if(a[m] == x) return true;
            else if(a[m] < x) l = m + 1;
            else h = m - 1;
        }

        return false;
    }

public:
    bool searchMatrix(vector<vector<int>> &mat, int target){

        for(int i = 0; i < mat.size(); i++){
                
            if(target >= mat[i][0] && target <= mat[i][mat[i].size()-1]){
                return binarySearch(mat[i], target);
            }
        }

        return false;
    }
};