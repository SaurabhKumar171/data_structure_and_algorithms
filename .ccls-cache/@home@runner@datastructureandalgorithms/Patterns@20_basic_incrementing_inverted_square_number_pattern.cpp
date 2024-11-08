#include <iostream>
using namespace std;

int basic_incrementing_inverted_square_number_pattern(int n){

  int st = 13;
  for(int i = 1; i <= n; i++){

    int num = st;

    for(int j = 1; j<= n; j++){
      cout << num++ << " ";

      if( j < n){
        cout << "* ";
      }
    }

    st = st - (n);

    cout << endl;
  }

  return 0;
}