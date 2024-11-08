#include <iostream>
#include <vector>
using namespace std;

// void move_all_neg(vector<int>& arr){
  // Brute force
//   vector<int> pos;
//   vector<int> neg;

//   for(int i = 0; i < arr.size(); i++) {
//     if(arr[i] >= 0){
//       pos.push_back(arr[i]);
//     }
//     else{
//       neg.push_back(arr[i]);
//     }
//   }

//   arr.clear();

//   for(int i = 0; i < neg.size(); i++) {
//       arr.push_back(neg[i]);
//   }

//   for(int i = 0; i < pos.size(); i++) {
//       arr.push_back(pos[i]);
//   }

// }

void move_all_neg(vector<int>& arr){
  // Duth national flag algorithm
  int l = 0;
  int h = arr.size()-1;

  while(l < h){
    if(arr[l] < 0){
      l++;
    }
    else if(arr[h] > 0){
      h--;
    }
    else{
      swap(arr[l], arr[h]);
      l++;
      h--;    
    }
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

//   move_all_neg(arr);

//   cout << endl << "Array elements : ";
//   for(int i = 0; i < n; i++) {
//     cout << arr[i]<< " ";
//   }
// }