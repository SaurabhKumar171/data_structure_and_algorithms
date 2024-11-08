#include <iostream>
using namespace std;

int numeric_palindrome_equilateral_pyramid(int n){
  for(int i =0 ; i < n; i++){
    for(int j =0; j < n-i-1; j++){
      cout << " ";
    }

    int start = 1;
    for(int j =0; j <= i; j++){
      cout << start++;
    }

    start -=1;
    for(int j =0; j < i; j++){
      cout << --start;
    }

    cout << endl;
  }
  return 0;
}