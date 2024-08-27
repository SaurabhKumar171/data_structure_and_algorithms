#include <iostream>
using namespace std;

long long int factorial(long long int n){
    long long int fact = 1;
    for(int i=n; i >=1 ; i--){
      fact *= i;
    }

    return fact;
}

// int main() {
//   cout << "Enter the number :";
//   int num;
//   cin >> num;
//   long long int ans = factorial(num);

//   cout << "Factorial of "<< num << " is "<< ans;
// }