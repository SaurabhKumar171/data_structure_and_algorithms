#include <iostream>
#include <vector>
using namespace std;

void sort01(vector<int>& arr){
  int i = 0;
  int j = arr.size()-1;

  while(i < j){
    if(arr[i] == 1){
      swap(arr[i], arr[j]);
    }
      i++;
      j--;
  }

}

// int main() {

//   int n;

//   cout << "Enter size of array : ";
//   cin >> n;

//   cout << "Enter array elements : ";
//   vector<int> arr(n);

//   for(int i = 0; i < n; i++) {
//     cin >> arr[i];
//   }

//   sort01(arr);

//   cout << "Sorted array :" << endl;

//   for(int i = 0; i < n; i++) {
//     cout << arr[i]<< " ";
//   }

//   return 0;
// }