#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

// Brute force
int minSubArrayLen1(int x, vector<int>& arr) {

    int ans = INT_MAX;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int sum = 0;

        int len = 0;
        for(int j = i; j < n; j++){

            if(arr[j] >= x){
                return 1;
            }
            sum += arr[j];
            len++;
            if(sum >= x){
                ans = min(ans, len);
                break;
            }
        }
    }

    if(ans == INT_MAX){
        return 0;    
    }

    return ans;
}