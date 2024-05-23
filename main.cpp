#include <iostream>
using namespace std;

int extreme_array(int arr[], int size);

int main() {
      int arr[] = {50, 80, 30, 10, 60};
      int size = sizeof(arr) / sizeof(arr[0]);

      extreme_array(arr, size);
      return 0;
} 