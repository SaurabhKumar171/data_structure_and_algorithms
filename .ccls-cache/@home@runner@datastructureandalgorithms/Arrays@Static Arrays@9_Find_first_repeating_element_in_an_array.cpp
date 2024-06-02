#include <iostream>
#include <limits.h>
using namespace std;
#include <unordered_map>
#include <cstring>
// solution 1
int usingUnorderdMap(int arr[], int n){
    unordered_map<int, int> map;

    for(int i =0; i< n ;i++){
        map[arr[i]]++;
    }

    for(int i =0; i< n ;i++){
        if(map[arr[i]] > 1){
            return i+1;
        }
    }
    return -1;
}

// solution 2
int usingArray(int arr[], int n){
    int maximum = INT_MIN;

    for(int i =0; i< n ;i++){
        maximum = max(maximum, arr[i]);
    }


    int *track_array = new int[maximum+1];
    memset(track_array, 0, sizeof(int)*(maximum+1));

    for(int i = 0; i< n ;i++){

        int index = arr[i];
        track_array[index]++;
    }

    for(int i = 0; i< n ;i++){
        int indexToCheck = arr[i];

        if(track_array[indexToCheck] > 1){
            return i+1;
        }
    }
    return -1;
}

// Function to return the position of the first repeating element.
int firstRepeated(int arr[], int n) {
    // code here

    return usingArray(arr, n);

}
