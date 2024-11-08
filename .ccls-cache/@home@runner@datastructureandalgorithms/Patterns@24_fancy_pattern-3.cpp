#include <iostream>
using namespace std;

int fancy_pattern_3(int n){

    cout << "* "<< endl;
    for(int i=0; i < n ; i++){
      int condition = i < n/2 ? 2*i : 2*(n-i-1);

      cout << "* ";
      for(int j=0; j <= condition ; j++){
        if(j <= condition/2){
          cout << j+1<< " ";
        }
        else{
          cout << condition - j +1<< " ";
        }
      }
      cout << "* ";
      cout <<endl;
    }
    cout << "* "<< endl;

    return 0;
}