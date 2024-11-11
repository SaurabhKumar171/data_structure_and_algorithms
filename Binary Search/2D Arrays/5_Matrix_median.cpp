#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution{
public:
    int findMedian(vector<vector<int>>&matrix) {
        
        vector<int> lst;
        int n = matrix.size();
        int m = matrix[0].size(); 
        
        /* Traverse the matrix and 
        copy the elements to list*/
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                lst.push_back(matrix[i][j]);
            }
        }

        sort(lst.begin(), lst.end());

        return lst[(n*m)/2];
    }
};
