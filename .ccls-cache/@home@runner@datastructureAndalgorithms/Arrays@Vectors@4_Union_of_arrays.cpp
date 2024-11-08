#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int doUnion(int a[], int n, int b[], int m)  {
    //code here
    // int size = 0;

    vector<int> res;


    for(int i = 0 ; i < n; i++){
        res.push_back(a[i]);
    }


    for(int i = 0 ; i < m; i++){
        if(!count(res.begin(), res.end(), b[i])){
            res.push_back(b[i]);
        }
    }

    // cout << "here" << res.size();



 return res.size();
}