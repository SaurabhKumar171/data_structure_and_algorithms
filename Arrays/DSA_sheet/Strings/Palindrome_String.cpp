#include <iostream>
using namespace std;

int isPalindrome(string S) {
  // Your code goes here
  int i = 0;
  int j = S.size() - 1;

  while (i < j) {
    if (S[i] != S[j]) {
      return 0;
    }
    i++;
    j--;
  }
  return 1;
}