#include <iostream>
#include <unordered_map>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) {

  if (m > n) {
    return "No";
  }

  unordered_map<int, int> map;

  for (int i = 0; i < n; i++) {
    map[a1[i]]++;
  }

  for (int i = 0; i < m; i++) {
    if (map[a2[i]]) {
      map[a2[i]]--;
    } else {
      return "No";
    }
  }

  // Brute force approach
  // for(int i = 0; i < m; i++){
  //     bool found = false;
  //     for(int j = 0; j < n; j++){
  //         if(a2[i] == a1[j]){
  //             found = true;
  //             a1[j] = INT_MIN;
  //             break;
  //         }
  //     }

  //     if(!found){
  //         return "No";
  //     }
  // }

  return "Yes";
}