#include <iostream>
using namespace std;

string largeOddNum(string &s) {
  // your code goes here
  int ind = -1;
  int i = 0;

  for (i = s.size() - 1; i >= 0; i--) {
    if ((s[i] - '0') % 2 != 0) {
      ind = i;
      break;
      return s.substr(0, i + 1);
    }
  }

  i = 0;
  while (i <= ind && s[i] == '0')
    i++;

  return s.substr(i, ind - i + 1);
}