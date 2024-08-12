#include <iostream>
using namespace std;

int binarySearch(int a[], int i, int j, int x){
    while(i <= j){
      int m = i + ( j - i)/2;

      if(a[m] == x){
        return m;
      }
      else if(a[m] < x){
        i = m + 1;
      }
      else{
        j = m - 1;
      }
    }

    return -1;
}

int exponentialSearch(int a[], int x, int n){

  if(a[0] == x) return 0;

  int i = 1;
  while(i < n && a[i] <= x){
    i = i*2; // i *= 2 // i = i << 1
  }
  return binarySearch(a, i/2, min(i, n-1), x);
}

int main() {
  int arr[] = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
  int x = 560;
  int n = sizeof(arr)/sizeof(arr[0]);

  int foundAt = exponentialSearch(arr, x, n);
  cout << "Element found At : "<< foundAt << endl;
  return 0;
}