// Sorted array by absolute values

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool customComparator(int a , int b){
    return abs(a) < abs(b);
}

int main() {
    // Write C++ code here
    vector<int> arr = {-4, 3, -9, 2, 7, -1};
    
    sort(arr.begin(), arr.end(), customComparator);
    
    cout << "Sorted aray is : \n";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;
}



// NOTE : if comparator returns true then first no. will come first else second no.