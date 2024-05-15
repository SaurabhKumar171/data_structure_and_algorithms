#include <iostream>
using namespace std;

int pascals_Triangle(int n){

  for(int i= 0; i < n; i++){

    for(int j=0; j < n-i-1; j++){
      cout << " ";
    }

    for(int k = 0; k < 2*i+1; k++){
      if(k == 0 || k == 2*i){
        cout << "1";
      }
      else{
        cout << "7";
      }
    }

    cout << endl;
  }
  return 0;
}