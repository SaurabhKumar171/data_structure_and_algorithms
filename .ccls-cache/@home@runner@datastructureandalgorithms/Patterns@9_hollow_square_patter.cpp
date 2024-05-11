// ******
// *    *
// *    *
// *    *
// *    *
// ******


#include <iostream>
using namespace std;

int hollow_square_pattern(){
  int n=5;
  for(int i=0; i<=n;i++){
    for(int j=0;j<=n; j++){
      if( i==0 || i == n || j == 0 || j == n){
        cout <<"*";
      }
      else{
      cout << " ";
      }
    }
    cout << endl;
  }
    return 0;
}