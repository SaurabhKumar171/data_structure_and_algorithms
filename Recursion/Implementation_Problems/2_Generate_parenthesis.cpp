#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include <numeric>
using namespace std;
     
class Solution { 
private:
    void createPairs(int open, int close, string str, vector<string>& ans, int n){

        if(((open + close) == 2*n) && open == close){
            ans.push_back(str);
            return;
        }

        if(open < n){
            createPairs(open + 1, close, str + "(", ans, n);
        }

        if(close < open){
            createPairs(open, close + 1, str + ")", ans, n);
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        createPairs(0, 0, "", ans, n);

        return ans;        
    }
};