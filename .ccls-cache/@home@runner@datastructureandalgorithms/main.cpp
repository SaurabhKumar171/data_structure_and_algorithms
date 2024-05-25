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

int uniqueElement(vector<int> nums);

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements: ";
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Unique element: " << uniqueElement(arr) << endl;
    return 0;
}