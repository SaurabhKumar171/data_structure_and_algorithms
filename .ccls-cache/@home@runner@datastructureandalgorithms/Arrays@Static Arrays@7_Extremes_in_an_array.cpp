#include <iostream>
using namespace std;

void extreme_array(int arr[], int size){

    int i =0 ; 
    int j = size -1;
    int nums[size];
    int  k = 0;
    while ( i != j){
      nums[k++] = arr[i++];
      nums[k++] = arr[j--];
    }

    if(i == j){
      nums[k] = arr[i];
    }

    for (int i = 0; i < size; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

// int main() {
//     int arr[] = {50, 80, 30, 10, 60};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     extreme_array(arr, size);
//     return 0;
// }