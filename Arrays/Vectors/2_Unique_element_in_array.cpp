#include <iostream>
#include <vector>

using namespace std;

int uniqueElement(vector<int> nums) {
    int ans = 0;

    for(int i = 0; i < nums.size(); i++) {
        ans = ans ^ nums[i];
    }

    return ans;
}

// int main() {
//     int n;

//     cout << "Enter size of array: ";
//     cin >> n;

//     cout << "Enter array elements: ";
//     vector<int> arr(n);

//     for(int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     cout << "Unique element: " << singleNumber(arr) << endl;
//     return 0;
// }
