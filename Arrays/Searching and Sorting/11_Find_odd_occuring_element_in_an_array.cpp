#include <iostream>
using namespace std;

int findOddOccuringElement(int a[], int n) {
  int i = 0;
  int j = n - 1;

  while (i <= j) {
    int m = i + (j - i) / 2;

    if (i == j) {
      return m;
    } else if (m % 2 == 0) {
      if (a[m] == a[m + 1]) {
        i = m + 2;
      } else {
        j = m;
      }
    } else {
      if (a[m] == a[m - 1]) {
        i = m + 1;
      } else {
        j = m - 1;
      }
    }
  }
}

// int main() {
//   int arr[] = { 1, 1, 2, 2, 3, 3, 4, 4, 600, 600, 9, 9, 1};
//   int n = sizeof(arr)/sizeof(arr[0]);
//   cout << "Odd occuring element is : " << arr[findOddOccuringElement(arr, n)]
//   << " at -->" << findOddOccuringElement(arr, n) << endl; return 0;
// }