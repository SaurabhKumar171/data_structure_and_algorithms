#include <iostream>
#include <algorithm>
using namespace std;

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    int inversionCount = 0;

    for(int i = 0; i < N-1 ; i++){
        for(int j = i+1; j < N ; j++){
            if(arr[i] > arr[j]){
                inversionCount++;
            }
        }
    }

    return inversionCount;
}