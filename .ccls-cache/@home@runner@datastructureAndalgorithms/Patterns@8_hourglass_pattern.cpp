 // * * * *
 //  * * *
 //   * *
 //    *
 //   * *
 //  * * *
 // * * * *


#include <iostream>
using namespace std;

int hourglass_pattern(){
  int n=3;
  for(int i=0; i<=n;i++){
    for(int j=0;j<i; j++){
      cout << " ";
    }

    for(int k=0;k<=n-i; k++){
      cout << " *";
    }

    cout << endl;
  }

  for(int i =0 ; i<=n-1; i++){

    for(int j =0; j<= n-i-2; j++){
      cout << " ";
    }

    for(int k =0; k <= n+i-2; k++){
      cout << " *";
    }
    cout << endl;
  }
    return 0;
}