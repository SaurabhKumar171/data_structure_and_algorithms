#include <iostream>
using namespace std;

int twoD_basics() {


  // declare 2D Array
  int arr[3][3];

  // int brr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
        cin >> arr[i][j];
    }
  }

  cout << "Printing column wise : " << endl;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
        cout << arr[j][i]<<" " ;
    }
    cout << endl;
  }

  cout <<endl<< "Printing row wise : " << endl;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
        cout << arr[i][j]<<" " ;
    }
    cout << endl;
  }

  cout <<endl<< "Printing row wise sum : " << endl;
  for(int i = 0; i < 3; i++){
     int sum = 0;
    for(int j = 0; j < 3; j++){
      sum += arr[i][j];
    }
    cout <<"Sum of " << i << " row is : " << sum << endl;
  }

  cout <<endl<< "Printing column wise sum : " << endl;
  for(int i = 0; i < 3; i++){
     int sum = 0;
    for(int j = 0; j < 3; j++){
      sum += arr[j][i];
    }
    cout <<"Sum of " << i << " col is : " << sum << endl;
  }

  return 0;
}