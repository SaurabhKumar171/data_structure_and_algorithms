#include <iostream>
#include <list>
#include <vector>
using namespace std;

void explainList() {

  list<int> ls = {7, 9};

  ls.push_front(22);

  for (auto i : ls) {
    cout << i << " ";
  }
}