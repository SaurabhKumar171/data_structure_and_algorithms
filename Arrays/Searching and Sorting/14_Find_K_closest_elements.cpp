#include <iostream>
#include <vector>
using namespace std;


// Two Pointer Approach
vector<int> findClosestElements1(vector<int>& arr, int k, int x) {

    int l = 0;
    int h = arr.size() - 1;

    while(h - l >= k){
        if(x - arr[l] > arr[h] - x){
            l++;
        }
        else{
            h--;
        }
    }

    vector<int> res;

    for(int i = l; i <= h; i++){
        res.push_back(arr[i]);
    }

    return res;
}