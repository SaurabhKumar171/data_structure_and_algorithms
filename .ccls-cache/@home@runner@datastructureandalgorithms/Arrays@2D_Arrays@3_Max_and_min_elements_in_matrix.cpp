#include <iostream>
#include <limits.h>
using namespace std;
  
int min(int arr[][3],int n ,int m,int target){
  int min = INT_MAX;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        if(arr[i][j] < min){
          min = arr[i][j];
        }
    }
  }

  return min;
}

int max(int arr[][3],int n ,int m,int target){

  int max = INT_MIN;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        if(arr[i][j] > max){
          max = arr[i][j];
        }
    }
  }
  return max;
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

//   cout << "Max is : " << max(arr, 3 , 3, 0) << endl;

//   cout << "Min is : " << min(arr, 3 , 3, 0) << endl;

//   return 0;
// }