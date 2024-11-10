#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// Brute force approach [O(n^2)]

class Solution {
  public:   
  int rowWithMax1s(vector < vector < int >> & mat) {
    

    int maxOneRow = -1;
    int maxOnes = 0;
    for(int i = 0; i < mat.size(); i++){

      int countOne = 0;
      for(int j = 0; j < mat[i].size(); j++){
        if(mat[i][j] == 1){
          countOne++;
        }
      }

      if(countOne > maxOnes){
        maxOnes = countOne;
        maxOneRow = i;
      }
    }

    return maxOneRow;
  }
};