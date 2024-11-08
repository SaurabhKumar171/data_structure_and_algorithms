#include <iostream>
using namespace std;

int floyds_Triangle(){
  int n = 4;
  int start = 1;
  for(int i= 0; i < n; i++){

    for(int j=0; j <= i; j++){
      cout << start++ << " ";
    }

    cout << endl;
  }
  return 0;
}