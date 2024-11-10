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


// Optimal approach [O( m * log(n) )]
class Solution {
  public:   
  int rowWithMax1s(vector < vector < int >> & mat) {
    

    int maxOneRow = -1;
    int maxOnes = 0;
    for(int i = 0; i < mat.size(); i++){

      int countOne = 0;
      
      int l = 0, h = mat[i].size()-1;

      while(l <= h){
        int m = (l+h)/2;

        if(mat[i][m] == 0){
          l = m + 1;
        }
        else{
          countOne = mat[i].size() - m +1 ;
          h = m - 1;
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