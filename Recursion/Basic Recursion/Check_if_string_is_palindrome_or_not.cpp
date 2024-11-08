#include <algorithm>
#include <iostream>
using namespace std;

bool check(string &s, int start, int end) {

  if (start >= end) {
    return true;
  } else if (s[start] != s[end]) {
    return false;
  }

  return check(s, start + 1, end - 1);
}

bool palindromeCheck(string &s) {
  // your code goes here
  int start = 0;
  int end = s.size() - 1;

  return check(s, start, end);
}
