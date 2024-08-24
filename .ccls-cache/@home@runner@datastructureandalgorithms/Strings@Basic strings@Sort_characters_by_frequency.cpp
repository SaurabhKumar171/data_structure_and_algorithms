#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool comparator(char a, char b, const vector<int> &freq) {
  if (freq[a] == freq[b]) {
    return a < b;
  }
  return freq[a] > freq[b];
}

string frequencySort(string s) {
  // Frequency vector to store the count of each character
  vector<int> freq(128, 0);

  // Count the frequency of each character
  for (auto ch : s) {
    freq[ch]++;
  }

  // Sort the string using the custom comparator
  sort(s.begin(), s.end(),
       [&](char a, char b) { return comparator(a, b, freq); });

  return s;
}
