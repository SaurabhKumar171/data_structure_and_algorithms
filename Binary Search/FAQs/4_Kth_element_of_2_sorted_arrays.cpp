#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// Brute force approach
class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
   
    vector<int> arr;

    for(int i = 0; i < a.size(); i++){
      arr.emplace_back(a[i]);
    }

    for(int i = 0; i < b.size(); i++){
      arr.emplace_back(b[i]);
    }

    sort(arr.begin(), arr.end());

    return arr[k-1];
  }
};