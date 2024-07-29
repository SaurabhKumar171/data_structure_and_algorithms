#include <iostream>
using namespace std;
#include <vector>

int peakIndexInMountainArray(vector<int>& arr) {

    int i = 0;
    int j = arr.size() - 1;

    while(i < j){
        int m = i + (j - i)/2;

        if(arr[m] > arr[m+1]){
            j = m;
        }
        else if(arr[m] < arr[m+1]){
            i = m + 1;
        }
    }

    return i;
}