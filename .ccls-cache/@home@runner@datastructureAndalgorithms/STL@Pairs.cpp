#include <iostream>
using namespace std;

void explainPair() {

  pair<int, int> pr1 = {3, 8};
  cout << pr1.first << endl;

  pair<char, string> pr2 = make_pair('j', "5");
  cout << pr2.first << " -- " << pr2.second << endl;

  pair<pair<int, int>, string> pr3 = {make_pair(5, 66), "saurabh"};
  cout << pr3.first.second << " -- " << pr3.second << endl;
}