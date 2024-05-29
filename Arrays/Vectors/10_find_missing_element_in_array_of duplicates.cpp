#include <iostream>
#include <vector>
using namespace std;

void find_missing_array_elements_with_duplicates(vector<int>& arr){

    // vector<int> res;

    for(int i = 0; i < arr.size(); i++){
      int index = abs(arr[i]);

      if(arr[index-1] > 0){
        arr[index - 1] *= -1;
      }
    }

  cout << endl << "Missing elements are :" << endl;

  for(int i = 0; i < arr.size(); i++) {
    if(arr[i] > 0)
      cout << i+1<< " ";
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

//   find_missing_array_elements_with_duplicates(arr);

//   return 0;
// }