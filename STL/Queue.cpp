#include <iostream>
#include <queue>
using namespace std;

void explainQueue() {
  queue<int> q;

  q.push(8);
  q.push(27);
  q.push(74);
  q.push(72);
  q.push(97);

  while (q.empty() == false) {
    cout << q.front() << " ";
    q.pop();
  }
}
