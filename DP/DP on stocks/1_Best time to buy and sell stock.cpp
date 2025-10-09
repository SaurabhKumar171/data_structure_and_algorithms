#include <bits/stdc++.h>
using namespace std;

// T.C: O(N)
// S.C: O(1)
class Solution{
public:
    int stockBuySell(vector<int> arr, int n){
        int ans = 0;
        int purchasedAt = INT_MAX;
        for(int i = 0; i < n; i++){
            if(purchasedAt > arr[i]) purchasedAt = arr[i];
            else ans = max(ans, arr[i] - purchasedAt);
        }

        return ans;
    }
};

