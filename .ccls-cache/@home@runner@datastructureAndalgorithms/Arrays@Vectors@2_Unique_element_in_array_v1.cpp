#include <iostream>
#include <vector>
using namespace std;

int unionOFArray(vector<int> a, int n , vector<int> b, int m) {

      vector<int> nums;

      for(int i = 0 ; i< a.size(); i++){
        nums.push_back(a[i]);
      }

      for(int i = 0 ; i< b.size(); i++){
        nums.push_back(b[i]);
      }

      cout << endl << "Nums array : ";
      for(int i = 0 ; i< nums.size(); i++){
        cout << nums[i] << " ";
      }
      cout << endl;


    return nums.size();
}

// int main() {
//     int n;

//     cout << "Enter size of 1st array: ";
//     cin >> n;

//     cout << "Enter array elements: ";
//     vector<int> arr(n);

//     for(int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int m;

//     cout << "Enter size of second array: ";
//     cin >> m;

//     cout << "Enter second array elements: ";
//     vector<int> brr(m);

//     for(int i = 0; i < n; i++) {
//         cin >> brr[i];
//     }

//     cout << endl << "Unique element: " << unionOFArray(arr, n , brr, m) << endl;
//     return 0;
// }
