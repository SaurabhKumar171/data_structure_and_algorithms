#include <iostream>
#include <vector>
using namespace std;

bool checkPalindrome(int val){

  string str = to_string(val);
  int size = str.size();


  int i = 0;
  int j = size - 1;


  while(i < j){
      if(str[i] != str[j]){
          return false;
      }
      i++;
      j--;
  }
  return true;
}

bool PalinArray(vector<int> &arr) {
  // code here
  int n = arr.size();

  for(int i = 0; i < n; i++){
      if(!checkPalindrome(arr[i])){
          return false;
      }
  }

  return true;
}
