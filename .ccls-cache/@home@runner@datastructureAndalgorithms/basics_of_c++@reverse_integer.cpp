#include <iostream>
#include <limits.h>
using namespace std; 

int reverse(int x) {
    bool isNeg = false;
    int res = 0;
    if(x <= INT_MIN){
        return 0;
    }

    if(x < 0){
        isNeg = true;
        x = -x;
    }

    while(x > 0){
        int rem = x %  10;

        if (res > INT_MAX/10) return 0;

        res = res*10 + rem;
        x = x/10;
    }
    return (isNeg ? - res : res);
}