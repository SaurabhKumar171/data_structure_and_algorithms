#include <iostream>
using namespace std;

int array(){
  int arr[10];
  char ch[10];
  bool bo[10];

  cout << "Array created successfully" << endl;
  cout << &arr << endl;
  cout << &ch << endl;
  cout << &bo << endl;

  return 0;
}