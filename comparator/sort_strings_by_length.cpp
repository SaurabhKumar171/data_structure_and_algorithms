// Given an array of strings, sort the strings by their length in ascending order. If two strings have the same length, maintain their original order

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool customLengthComparator(string a , string b){

    return a.size() < b.size();
}

int main() {
    // Write C++ code here
    vector<string> arr = {"56", "111", "49", "0", "3", "7", "51"};
    
    // Use stable_sort to maintain the relative order of strings with the same length
    stable_sort(arr.begin(), arr.end(), customLengthComparator);    
    cout << "Sorted aray is : \n";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;
}



// NOTE : if comparator returns true then first no. will come first else second no.