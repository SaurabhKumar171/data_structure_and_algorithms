#include <iostream>
using namespace std;

int hollow_Hourglass_Pattern(int n){

  for(int i= 0; i < n; i++){

    for(int j=0; j < i; j++){
      cout << " ";
    }

    for(int k = 0; k < 2*(n-i)-1; k++){
      if(i ==0 || i == n-1){
        if(k%2 ==0){
          cout << "*";
        }
        else{
          cout << " ";
        }
      }
      else{
        if(k==0 || k == 2*(n-i)-2){
          cout << "*";
        }
        else{
          cout << " ";
        }
      }
    }

    cout << endl;
  }

  for(int i= 1; i <= n-1; i++){

    for(int j=0; j < n-i-1; j++){
      cout << " ";
    }

    for(int k = 0; k < 2*i+1; k++){
      if(i ==0 || i == n-1){
        if(k%2 ==0){
          cout << "*";
        }
        else{
          cout << " ";
        }
      }
      else{
        if(k==0 || k == 2*i){
          cout << "*";
        }
        else{
          cout << " ";
        }
      }
    }

    cout << endl;
  }
  
  return 0;
}