#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
  
vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
    // code here
    vector<int> store;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            store.push_back(Mat[i][j]);
        }
    }

    sort(store.begin(), store.end());

    int k = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            Mat[i][j] = store[k++];
        }
    }

    return Mat;
}