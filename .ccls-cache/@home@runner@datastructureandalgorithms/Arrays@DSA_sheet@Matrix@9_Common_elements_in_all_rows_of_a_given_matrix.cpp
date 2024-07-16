#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
   
void commonElements(vector<vector<int>> arr, int n, int m){
  unordered_map<int, int> map;   

  for(int i = 0; i < arr[0].size(); i++){
    map[arr[0][i]]++;
  }

  for(int i = 1; i < n; i++){
    for(int j = 0; j < m; j++){
        if(map.find(arr[i][j]) != map.end() && map[arr[i][j]] == i){
          map[arr[i][j]]++;
        }
    }
  }


  // Traverse the map
    for (auto it = map.begin(); it != map.end(); ++it) {
        if (it->second == n) {
            cout << it->first << " ";
        }
    }
    cout << endl;
}    

