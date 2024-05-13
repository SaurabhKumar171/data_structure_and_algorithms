
# include <iostream>
using namespace std;

int hollow_full_pyramid_pattern(){
  int n=4;

  for(int i=0; i<=n; i++){

    for(int j=0; j<=n-i-1; j++){
      cout << " ";
    }

    for(int k=0; k <2*i +1; k++){
      if( i == 0 || i==n){
        if(k%2 == 0){
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

    cout << "\n";
  }
  return 0;
}
