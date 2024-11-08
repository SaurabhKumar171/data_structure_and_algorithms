#include <iostream>
#include <vector>
using namespace std;

void explainVector() {

  vector<int> vec;

  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(0);

  vector<int>::iterator beginItr = vec.begin();
  vector<int>::iterator endItr = vec.end();

  // Accessing using iterator
  cout << "Accessing using iterator : ";
  for (vector<int>::iterator i = beginItr; i < endItr; i++) {
    cout << *i << " ";
  }

  cout << endl;

  // Accessing using foreach
  cout << "Accessing using foreach : ";
  for (auto i : vec) {
    cout << i << " ";
  }

  cout << endl;

  // Reverse iterator
  cout << "Reverse iterator : ";

  auto revBeginItr = vec.rbegin();
  auto revEndItr = vec.rend();

  for (auto i = revBeginItr; i < revEndItr; i++) {
    cout << *i << " ";
  }
}