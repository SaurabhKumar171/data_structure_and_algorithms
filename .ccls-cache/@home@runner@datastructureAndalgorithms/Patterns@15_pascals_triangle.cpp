#include <iostream>
using namespace std;

int pascals_Triangle(int n) {

  for (int i = 1; i <= n; i++) {

    for (int j = 1; j <= n - i - 1; j++) {
      cout << " ";
    }
    int c = 1;
    for (int k = 1; k <= i; k++) {
      cout << c << " ";
      c = c * (i-k)/k;
    }

    cout << endl;
  }
  return 0;
}