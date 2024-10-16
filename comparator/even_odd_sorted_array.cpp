// Write a program to sort an array such that all even numbers appear before all odd numbers, and within each group, the numbers are sorted in ascending order

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool customEvenOddComparator(int a , int b){
    // if one is odd and another is even
    if((a%2 == 0 && b%2 == 0) || (a%2 != 0 && b%2 != 0)){ 
        return a < b;
    }
    else{
        return a%2==0;
    }
}

int main() {
    // Write C++ code here
    vector<int> arr = {56, 11, 49, 0, 3, 7, 50};
    
    sort(arr.begin(), arr.end(), customEvenOddComparator);
    
    cout << "Sorted aray is : \n";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;
}



NOTE : if comparator returns true then first no. will come first else second no.