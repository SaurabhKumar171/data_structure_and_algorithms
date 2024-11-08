// Given an array of integers, sort the array based on the last digit of each number. If two numbers have the same last digit, sort them by their value

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool customLastDigitComparator(int a , int b){

    // get last digit of both numbers    
    int r1 = a%10;
    int r2 = b%10;
    
    // if last digits are equal
    if(r1 == r2){
        // sort by value
        return a < b;
    }
    // if last digits are not equal
    else{
        // sort by last dgit
        return r1 < r2;
    }
}

int main() {
    // Write C++ code here
    vector<int> arr = {56, 111, 49, 0, 3, 7, 51};
    
    sort(arr.begin(), arr.end(), customLastDigitComparator);
    
    cout << "Sorted aray is : \n";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;
}



// NOTE : if comparator returns true then first no. will come first else second no.