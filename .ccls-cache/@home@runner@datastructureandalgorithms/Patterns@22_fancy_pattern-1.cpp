#include <iostream>
using namespace std;

int fancy_pattern_1(int n){
  for(int i =0 ; i < n; i++){
    for(int j =8; j > i; j--){
      cout << " *";
    }

    for(int j =0; j < 2*i+1; j++){

      if(i % 2 == 0){
        if(j % 2 == 0){
          cout << " " << i+1;
        }
        else{
          cout << " *";
        }
      }
      else{
        if(j % 2 != 0){
          cout << " " << i+1;
        }
        else{
          cout << " *";
        }
      }
    }

    for(int j =8; j > i; j--){
      cout << " *";
    }

    cout << endl;
  }
  return 0;
}