#include<iostream>
using namespace std;

void hollow_inverted_full_pyramid(){
  int n=4;

  for(int i=0; i<=n; i++){

    for(int j=0; j<i; j++){
      cout << " ";
    }

    for(int k=0; k <= 2*(n-i)-1; k++){

     if( i ==0 || i == n){
        if(k%2 == 0){
          cout << "*";
        }
        else{
        cout << " ";
      }
     }
     else{
          if(k ==0 || k == 2*(n-i)-2){
            cout << "*";
          }
          else{
          cout << " ";
        }
      }
    }

    cout << "\n";
  }
}