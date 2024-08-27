#include <iostream>
using namespace std;

int right_half_pyramid(){
  for(int i = 4; i>=0 ; i--){
    for(int j =0; j<=i ; j++){
      cout << "*";
    }
    cout << "/n";
  }
  return 0;
}