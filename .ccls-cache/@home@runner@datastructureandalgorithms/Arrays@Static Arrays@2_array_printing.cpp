#include <iostream>
using namespace std;

int array_creation_and_displaying(){
  char ch[5];

  cout << "Enter character values : " << endl;
  for(int i =0; i < 5; i++){
    cin >> ch[i];
  }

  cout << "Array is : " << endl;
  for(int i =0; i < 5; i++){
    cout << ch[i]<< " ";
  }

  return 0;
}