#include <iostream>
#include <vector>
using namespace std;

bool linear_search(int arr[][3],int n ,int m,int target){

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        if(arr[i][j] == target){
          return true;
        }
    }
  }

  return false;
}


// int main() {
//   // declare 2D Array
//   int arr[3][3];

//   // int brr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

//   for(int i = 0; i < 3; i++){
//     for(int j = 0; j < 3; j++){
//         cin >> arr[i][j];
//     }
//   }

//   if(linear_search(arr, 3 , 3, 0)){
//     cout << "Element found";
//   }
//   else{
//     cout << "Element not found";
//   }

//   return 0;
// }