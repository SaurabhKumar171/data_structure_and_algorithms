//     1
//    1 2
//   1   3
//  1     4
// 1 2 3 4 5

#include <iostream>
using namespace std;

int numeric_hollow_pyramid(){
  int n=4;

  for(int i=0; i<= n;i++){

    //spaces
    for(int j=0; j<= n-i-1; j++){
      cout << " ";
    }

    // numbers and spaces in between
    int start = 1;
    for( int k=0; k < 2*i+1; k++){
      // for 1st and last row
      if(i==0 || i==n){
        if(k%2 == 0){
          cout << start;
          start++;
        }
        else{
            cout << " ";
        }
      }
    // for rows in middle
      else{
         if(k==0){
            cout << k+1;
          }
          else if(k == 2*i){
            cout << i+1;
          }
          else{
            cout << " ";
          }
      }
    }

    cout << endl;
  }
  return 0;
}