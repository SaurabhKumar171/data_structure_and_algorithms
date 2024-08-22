#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool isIsomorphic(string s, string t) {

  if (s.size() != t.size()) {
    return false;
  }

  unordered_map<char, char> map;

  for (int i = 0; i < s.size(); i++) {

    if (map.find(s[i]) == map.end()) {
      map[s[i]] = t[i];
    } else if ((map.find(s[i]) != map.end()) && (map[s[i]] != t[i])) {
      return false;
    }
  }

  map.clear();

  for (int i = 0; i < t.size(); i++) {

    if (map.find(t[i]) == map.end()) {
      map[t[i]] = s[i];
    } else if ((map.find(t[i]) != map.end()) && (map[t[i]] != s[i])) {
      return false;
    }
  }

  return true;
}