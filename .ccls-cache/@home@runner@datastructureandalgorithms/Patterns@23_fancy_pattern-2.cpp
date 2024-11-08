#include <iostream>
using namespace std;

int fancy_pattern_2(int n){
  int st = 1;
  for(int i =0 ; i < n; i++){
    for(int j =0; j < 2*i+1; j++){
        if(j % 2 == 0){
          cout << " " << st++;
        }
        else{
          cout << " *";
        }
     }

    cout << endl;
  }

  int lower_half = st - 4;
  for(int i =0 ; i < n; i++){
    for(int j =0; j < 2*(n-i)-1; j++){
        if(j % 2 == 0){
          cout << " " << lower_half++;
        }
        else{
          cout << " *";
        }
    }

    cout << endl;
  }
  return 0;
}