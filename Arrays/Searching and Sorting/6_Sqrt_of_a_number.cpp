#include <iostream>
using namespace std;

int mySqrt(int x) {
  int i = 1;
  int j = x;
  int m = i + (j - i) / 2;
  int ans = 0;

  while (i <= j) {

    if (m == x / m) {
      return m;
    } else if (m > x / m) {
      j = m - 1;
    } else {
      i = m + 1;
      ans = m;
    }

    m = i + (j - i) / 2;
  }

  return ans;
}