#include <iostream>
using namespace std;

int addDigits(int num) {
  // your code goes here
  if (num < 10) {
    return num;
  }

  int sum = 0;

  while (num != 0) {
    sum += num % 10;
    num = num / 10;
  }

  int ans = addDigits(sum);

  return ans;
}