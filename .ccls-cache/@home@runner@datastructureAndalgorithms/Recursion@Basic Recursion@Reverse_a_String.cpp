#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<char>& s, int start, int end){
  if(start >= end){
    return;
  }
  
  int temp = s[start];
  s[start] = s[end];
  s[end] = temp;
  
  reverse(s, start + 1, end - 1);
}

void reverseString(vector<char>& s) {
  int start = 0;
  int end = s.size() - 1;

  reverse(s, start, end);
}

