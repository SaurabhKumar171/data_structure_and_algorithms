#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

// Better approach
long long findMinDiff1(vector<long long> a, long long n, long long m){

      long long minDiff = INT_MAX;
      long long l = 0;
      long long r = 0;

      sort(a.begin(), a.end());

      for(int i = 0; i < n-m+1; i++){
          for(int j = i+m-1; j < n; j++){
              long long diff = a[j] - a[i];
              minDiff = min(minDiff, diff);
          }
      }

      return minDiff;
  } 

// Optimal approach
long long findMinDiff2(vector<long long> a, long long n, long long m){
      sort(a.begin(), a.end());

      long long diff = a[m-1] - a[0];
      long long minDiff = diff;
      int j = m;
      int i = 1;

      while(j < n){
          diff = a[j] - a[i];
          minDiff = min(minDiff, diff);
          i++;
          j++;
      }

      return minDiff;
  } 