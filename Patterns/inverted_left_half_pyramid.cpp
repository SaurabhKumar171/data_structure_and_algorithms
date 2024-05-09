#include <iostream>
using namespace std;

int inverted_left_half_pyramid(){
  int n = 4;

  for(int i = 0; i<=n ; i++){
    // Printing space
    for(int j =n; j>(n-i) ; j--){
      cout << " ";
    }
    // Printing stars
    for(int k = 4; k >= i; k--){
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
}