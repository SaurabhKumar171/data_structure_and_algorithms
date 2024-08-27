#include <iostream>
using namespace std;

void print_matrix_in_wave_form(int mat[][4], int n){

  for(int i = 0; i < n-1; i++){
    for(int j = 0; j < n; j++){
        if(i % 2 == 0){
          cout << mat[j][i] << " ";
        }
        else{
          cout << mat[n-j-1][i] << " "; 
        }
    }
  }
}

// int main() {

//   int arr[5][4] = {{ 1, 2, 3, 4 },
//     { 5, 6, 7, 8 },
//     { 9, 10, 11, 12 },
//     { 13, 14, 15, 16 },
//     { 17, 18, 19, 20 }
//   };

//   print_matrix_in_wave_form(arr, 5);
//   return 0;
// }