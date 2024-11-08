#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    long long floorSqrt(long long n)  {
      
      if(n == 0) return 0;
      
      long long l = 1;
      long long h = n;
      long long sqrt = 1;

      while(l <= h){

        long long m = l + (h-l)/2;

        if(m*m > n){
            h = m - 1;
        }
        else if(m*m <= n){
            l = m+1;
        }

      }

      return h;
    }
};