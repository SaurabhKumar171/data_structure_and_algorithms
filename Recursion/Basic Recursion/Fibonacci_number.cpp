#include <iostream>
using namespace std;


int fib(int n) {
    
    return sum(0 , 1 , 1, n);
}

int sum(int first, int sec, int num, int n){
    if(n == 0){
        return 0;
    }
    else if(num == n){
        return sec;
    }
    return sum(sec, first + sec , num + 1, n);
}

int main(){

    cout << "Enter n : ";
    int n;
    cin << n;

    cout << fib(n);
    return 0;
}
