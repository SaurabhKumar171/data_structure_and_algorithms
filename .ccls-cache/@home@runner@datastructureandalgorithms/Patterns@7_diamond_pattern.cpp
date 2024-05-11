#include <iostream>
using namespace std;


int diamond(){
  int n=4;
  for(int i=0; i<=n;i++){
    for(int j=0;j<=n-i-1; j++){
      cout << " ";
    }

    for(int k=0;k<=i; k++){
      cout << " *";
    }

    cout << endl;
  }

  for(int i =0 ; i<=n; i++){

    for(int j =0 ; j<i; j++){
      cout << " ";
    }

    for(int k =0; k <= n-i; k++){
      cout << " *";
    }
    cout << endl;
  }
    return 0;
}