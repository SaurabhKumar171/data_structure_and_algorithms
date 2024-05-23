#include <iostream>
using namespace std;

int linear_search(){
  int arr[5];

  cout << "Enter values of array : " << endl;
  for(int i =0; i < 5; i++){
    cin >> arr[i];
  }

  int search;
  cout << "Enter values to search : " << endl;
  cin >> search;

  cout << "Array is : " << endl;
  for(int i =0; i < 5; i++){
    if(arr[i] == search){
      return i;
    }
  }

  return -1;
}

int main() {
  int index = linear_search();
  (index != -1 ? cout << "Found at :"<< index : cout << "Not found");
}