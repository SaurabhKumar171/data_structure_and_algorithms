// 1 
// 2 3 
// 3 4 5 
// 4 5 6 7 
// 5 6 7 8 9 

#include <iostream>
using namespace std;

int right_half_number_pyramid(){
  int n= 4;
  for(int i= 0; i <= n; i++){
    for(int j=0; j<=i; j++){
      cout << (j +i+ 1) << " ";
    }
    cout << "\n";
  }
  return 0;
}