#include <iostream>
using namespace std;

int full_pyramid(){
  int n = 4;

  for(int i = 0; i<=n ; i++){
    // Printing space
    for(int j =0; j<=(n-i-1) ; j++){
      cout << " ";
    }
    // Printing stars
    for(int k = 0; k <= i; k++){
      cout << "* ";
    }
    cout << "\n";
  }
  return 0;
}