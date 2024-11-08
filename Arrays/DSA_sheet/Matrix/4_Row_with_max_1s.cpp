#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

// Brute force approach
vector<int> rowAndMaximumOnes(vector<vector<int>>& arr) {

    int n = arr.size();
    int m = arr[0].size();
    int rowNum = -1;
  int maxOne = 0;

    vector<int> res(2,0);

  for(int i = 0; i < n; i++){
      int countOne = 0;
      for(int j = 0; j < m; j++){
          if(arr[i][j] == 1){
              countOne++;
          }
      }
      if(maxOne < countOne){
          maxOne = countOne;
          res[0] = i;
            res[1] = maxOne;
      }
  }

  return res;
}