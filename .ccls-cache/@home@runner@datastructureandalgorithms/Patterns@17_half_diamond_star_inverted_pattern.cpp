#include <iostream>
using namespace std;

int half_diamond_star_inverted_pattern(int n){

  for(int i = 0; i < n ; i++){

    for(int j = 0; j < n-i-1; j++){
      cout << " ";
    }

    for(int j = 0; j<=i; j++){
      cout << "*";
    }
    cout << endl;
  }

  for(int i = 1; i < n ; i++){

    for(int j = 0; j < i; j++){
      cout << " ";
    }

    for(int j = 1; j<=n-i; j++){
      cout << "*";
    }
    cout << endl;
  }
  return 0;
}