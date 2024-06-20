#include <iostream>
#include <unordered_map>
using namespace std; 

int findLongestConseqSubseq(int nums[], int N)
{
  //Your code here
    int n = N;
    int count = 0;
    int ans = 0;

    unordered_map<int, int> umap;

    for(int i = 0; i<n ; i++){
        umap[nums[i]]++;
    }

    for(int i = 0; i < n ; i++){

        int element = nums[i];

        while(umap[element] > 0){
            count++;
            element++;
        }
        ans = max(ans, count);
        count = 0;
    }

    return ans;
}