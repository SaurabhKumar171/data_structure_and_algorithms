#include<iostream>
using namespace std;

int hollow_diamond_pattern(){
  int n=4;

  for(int i=0; i<n; i++){

    for(int j=0; j<=n-i-1; j++){
      cout << " ";
    }

    for(int k=0; k< 2*i+1; k++){

      if(i==0){
        if(k%2 == 0){
          cout << "*";
        }
        else{
         cout << " ";
        }
      }
      else{
        if (k ==0 || k == 2*i){
          cout << "*";
        }
        else{
         cout << " ";
        }
      }
    }

    for(int k=0; k< 2*(n-i)-3; k++){

    }

    cout << "\n";
  }

  for(int i=1; i<= n; i++){

    for(int j=0; j <=i; j++){
      cout << " ";
    }

    for(int k=0; k <= 2*(n-i)-1; k++){
      if(i == n){
        cout << "*";
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
  return 0;
}