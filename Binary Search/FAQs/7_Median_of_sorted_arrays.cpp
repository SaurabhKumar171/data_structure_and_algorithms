#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution {
public:
    double median(vector<int> &arr1, vector<int> &arr2) {
     
     vector<double> lst;

     for(int i = 0; i < arr1.size(); i++){
        lst.push_back(arr1[i]);
     }

     for(int i = 0; i < arr2.size(); i++){
        lst.push_back(arr2[i]);
     }

     sort(lst.begin(), lst.end());

     double median = (lst.size()%2 == 0) ? ((lst[lst.size()/2]+lst[(lst.size()/2)-1])/2) : (lst[lst.size()/2]);

     return median;
    }
};