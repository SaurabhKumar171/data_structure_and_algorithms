#include <iostream>
#include <vector>
using namespace std;

// int extreme_array(int arr[], int size);

// int main() {
//       int arr[] = {50, 80, 30, 10, 60};
//       int size = sizeof(arr) / sizeof(arr[0]);

//       extreme_array(arr, size);
//       return 0;
// } 

int sort01(vector<int>& arr);

int main() {

  int n;

  cout << "Enter size of array : ";
  cin >> n;

  cout << "Enter array elements : ";
  vector<int> arr(n);

  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort01(arr);

  cout << "Sorted array :" << endl;

  for(int i = 0; i < n; i++) {
    cout << arr[i]<< " ";
  }

  return 0;
}   