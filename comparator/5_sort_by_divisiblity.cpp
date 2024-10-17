// Sort Based on Divisibility

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool customComparator(int a , int b){
    
    if((a%3 == 0 && b%3 == 0)) return a<b;

    if(a%3 == 0) return true;
     if(b%3 == 0) return false;

    if((a%5 == 0 && b%5 == 0)) return a<b;

    if(a%5 == 0) return true;
    if(b%5== 0) return false;

    return a<b;
}

int main() {
    // Write C++ code here
    vector<int> arr = {12, 10, 15, 5, 8, 9, 25, 30, 7, 2, 18};
    
    sort(arr.begin(), arr.end(), customComparator);
    
    cout << "Sorted aray is : \n";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;
}



// NOTE : if comparator returns true then first no. will come first else second no.