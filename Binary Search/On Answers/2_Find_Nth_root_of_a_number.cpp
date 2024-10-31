#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
  int NthRoot(int N, int M) {
       
       int l = 1;
       int h = M;

       while(l <= h){
          int m = l + (h - l)/2;
          long long val = 1;

          for(int i = 1; i <= N; i++){
            val *= m;

            if(val > M) break;
          }

          if(val == (long long)M){
            return m;
          }
          else if(val > (long long)M){
            h = m - 1;
          }
          else{
            l = m + 1;
          }
       }
       return -1;
    }
};
