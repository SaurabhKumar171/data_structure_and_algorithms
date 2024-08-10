#include <iostream>
#include <vector>
using namespace std;

// Brute force Approach [ Time complexity : O(n2) , Space complexity : O(n) ]
double findSmallestMaxDistBruteForceApproach(vector<int> &stations, int k) {
  // Code here
  int n = stations.size();

  vector<int> howMany(n - 1, 0);

  for (int i = 1; i <= k; i++) {

    long double maxVal = -1;
    int maxValPos = -1;

    for (int j = 0; j < n - 1; j++) {
      long double diff = stations[j + 1] - stations[j];
      long double sectionLength = diff / (long double)(howMany[j] + 1);

      if (maxVal < sectionLength) {
        maxVal = sectionLength;
        maxValPos = j;
      }
    }
    howMany[maxValPos]++;
  }

  long double maxAns = -1;
  for (int i = 0; i < n - 1; i++) {

    long double diff = stations[i + 1] - stations[i];
    long double sectionLength = diff / (long double)(howMany[i] + 1);

    maxAns = max(maxAns, sectionLength);
  }

  return maxAns;
}
