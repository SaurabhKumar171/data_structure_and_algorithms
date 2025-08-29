
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void shortestDistance(vector<vector<int>>&matrix) {
        int n = matrix.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == -1) matrix[i][j] = 1e9;
                if(i == j) matrix[i][j] = 0;
            }
        }        

        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }

        // Checks -ve cycles -> any node having less than 0 distance from itself means the graph has -v cycles
        // for(int i = 0; i < n; i++){
        //     if(matrix[i][j] < 0) {
                
        //     }
        // } 

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1e9) matrix[i][j] = -1;
            }
        }  
	}
};