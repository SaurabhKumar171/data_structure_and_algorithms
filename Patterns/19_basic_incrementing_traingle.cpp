#include <iostream>
using namespace std;

int basic_incrementing_traingle(int n){

  int st = 1;
  for(int i = 1; i < n; i++){

    st = st + i;
    int num = st;

    for(int j = 1; j<= i; j++){
      cout << num -- << " ";
    }
    cout << endl;
  }

  for(int i = n-1; i >= 1; i--){
    int num = st;
    for(int j = 1; j<= i; j++){
      cout << num -- << " ";
    }

    st = st - i;
    cout << endl;
  }

  return 0;
}