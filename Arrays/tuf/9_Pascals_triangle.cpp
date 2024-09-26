#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> pascalTriangle(int numRows) {
        
        vector<vector<int>> ans;

        for(int i = 0; i < numRows; i++){
            vector<int> subArr(i+1, 1);
            ans.push_back(subArr);
        }

        if(numRows >=2 ){
            
            for(int r = 2; r < numRows; r++){
                
                int i = 1;

                while(i < ans[r].size() - 1){
                    ans[r][i] = ans[r - 1][i - 1] + ans[r - 1][i];
                    i++;
                }
            }

        }

        return ans;
    }
};