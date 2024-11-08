#include <iostream>
using namespace std;

int doubles_in_array(){
  int arr[5];

  cout << "Enter character values : " << endl;
  for(int i =0; i < 5; i++){
    cin >> arr[i];
  }

  cout << "Array is : " << endl;
  for(int i =0; i < 5; i++){
    cout << 2*arr[i]<< " ";
  }

  return 0;
}