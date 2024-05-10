//     1
//    232
//   34543
//  4567654
// 567898765


#include <iostream>
using namespace std;

int numeric_full_pyramid(){
  int n= 4;
  for(int i= 0; i <= n; i++){
    for(int j=0; j<=(n-i-1); j++){
      cout << " ";
    }

    for(int j=0; j<=i; j++){
      cout << (j+i+1);
    }

    for(int j=0; j<i; j++){
      cout << ((2*i)-j);
    }
    cout << "\n";
  }
  return 0;
}