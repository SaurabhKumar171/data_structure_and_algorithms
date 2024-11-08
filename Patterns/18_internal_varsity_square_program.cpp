#include <iostream>
using namespace std;

int internal_varsity_square_program(int n, int number){

  for(int i = 0; i < n ; i++){

    for(int j = 0; j<n-1; j++){

      if(i ==0 || i == n-1 || j == 0 || j == n-2){
        cout << number;
      }
      else{
        cout << i;
      }

    }
    cout << endl;
  }

  return 0;
}