
#include <iostream>
#include <vector>
using namespace std;

// Approach 1: Brute Force
 string longestCommonPrefix(vector<string>& str) {

   string firstString = str[0];
   string ans = "";

   for(int i = 0; i < firstString.size(); i++){

     char charToCheck = firstString[i]; 

     // cout << "charToCheck" << charToCheck << endl;

     for(int j = 1; j < str.size(); j++){

       if(charToCheck != str[j][i]){
         return ans;
       }

     }

     ans += charToCheck;

   }

   return ans;
 }

// Approach 2 : Optimal Approach
string longestCommonPrefixOptimalApproach(vector<string>& str) {

  sort(str.begin(), str.end());

  string firstString = str[0];
  string lastString = str[str.size() - 1];

  string ans = "";

  int minLength = min(firstString.size(), lastString.size());

  for(int i = 0; i < minLength; i++){ 
    if(firstString[i] != lastString[i]){
      return ans;
    }

    ans += firstString[i];
  }

  return ans;
}