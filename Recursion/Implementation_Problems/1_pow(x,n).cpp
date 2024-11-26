#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include <numeric>
using namespace std;
 
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 1){
            return x;
        }
        else if(n == 0){
            return 1;
        }

        long long num = n;
        if(n < 0){
            num = -1 * num;
            x = 1/x;
        }

        if(n % 2 == 0){
            return myPow(x*x, (int)(num/2));
        }
        else{
            return x*myPow(x, (int)(num-1));
        }

        return -1;  
    }
};

