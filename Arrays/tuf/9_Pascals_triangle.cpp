#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution1 {
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


// variety 1 : (Creating Pascal's triangle by combination formula (nCr) , to calculate current value by n = row vale and c = col value )
class Solution2 {
public:
    vector<vector<int>> pascalTriangle(int numRows) {
        
        vector<vector<int>> ans(numRows);

        for(int i = 0; i < numRows; i++){
            
            ans[i].resize(i+1);

            for(int j = 0; j <= i; j++){
                ans[i][j] = nCr(i, j);
            }
        }

        return ans;
    }

    int nCr(int n, int r){
        long long res = 1;

        for(int i = 0; i < r; i++){
            res = res*(n-i);
            res = res/(i+1);
        }

        return (int)res;
    }
};



// Variety 2 : (To Print a row in a triangle using above formula)
class Solution3 {
public:
    int nCr(int n, int r){
        long long res = 1;
        for(int i = 0; i < r; i++){
            res = res*(n-i);
            res = res/(i+1);
        }
        return (int)res;
    }

    void pascalTriangle(int printRow) {
        
        // vector<vector<int>> ans(numRows)
        for(int j = 0; j < printRow; j++){
                cout << nCr(printRow - 1, j) << " ";
        }

        cout << endl;
    }

    int main() {
        pascalTriangle(1);
        pascalTriangle(2);
        pascalTriangle(3);
        pascalTriangle(4);
        return 0;
    }
};