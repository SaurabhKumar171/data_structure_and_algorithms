#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

// Optimal Approach [T.C : O(n* logn) | S.C : O(1)])
bool isAnagram(string s, string t) {

  sort(s.begin(), s.end());
  sort(t.begin(), t.end());

  if (s == t) {
    return true;
  }

  return false;
}

// Brute force [T.C : O(n) | S.C : O(n)])
bool anagramStringsBruteForce(string &s, string t) {
  // your code goes here
  if (s.size() != t.size()) {
    return false;
  }

  unordered_map<char, int> map;

  for (int i = 0; i < s.size(); i++) {
    map[s[i]]++;
  }

  for (int i = 0; i < t.size(); i++) {
    if (map[t[i]] > 0) {
      map[t[i]]--;
    } else {
      return false;
    }
  }

  return true;
}