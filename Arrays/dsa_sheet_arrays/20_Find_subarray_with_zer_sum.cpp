#include <iostream>
#include <vector>
using namespace std; 

bool subArrayExists(int arr[], int n)
{
    //Your code here
    // int prefixSum[n];
    unordered_map<int, int> prefixSum;
    int s = 0;

    for(int i = 0; i < n ; i++){
        s += arr[i];

        if(s != 0 && prefixSum.find(s) == prefixSum.end()){
            prefixSum[s] = prefixSum[s]++;
        }
        else{
            return true;
        }
    }

    return false;
}