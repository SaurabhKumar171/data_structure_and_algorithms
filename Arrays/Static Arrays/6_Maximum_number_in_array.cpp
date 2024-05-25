#include <iostream>
using namespace std;
#include <vector>
#include <limits.h>

int largest(vector<int> &arr, int n)
{

    int res = INT_MIN;

    for(int i = 0; i < n ; i++){

        if(arr[i] > res){
          res = arr[i]; 
        } 
    }

    return res;
}