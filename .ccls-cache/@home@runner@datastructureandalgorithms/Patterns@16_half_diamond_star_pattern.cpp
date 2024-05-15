#include <iostream>
using namespace std;

int half_diamond_star_pattern(int n){

  for(int i = 0; i < n ; i++){

    for(int j = 0; j<=i; j++){
      cout << "* ";
    }
    cout << endl;
  }

  for(int i = 1; i < n ; i++){

    for(int j = 1; j<=n-i; j++){
      cout << "* ";
    }
    cout << endl;
  }
  return 0;
}