#include <iostream>
#include <queue>
using namespace std;

void ExplainPQ(){
  // internal DS - stores max element at top (Max heap)
  priority_queue<int> pq;

  pq.push(8);
  pq.push(27);
  pq.push(74);
  pq.push(72);

  while(pq.empty() == false){
      cout << pq.top() << " ";
      pq.pop();
  }

  cout << endl;

  // min heap
  priority_queue<int, vector<int>, greater<int>> pq2;

  pq2.push(98);
  pq2.push(7);
  pq2.push(04);
  pq2.push(72);

  while(pq2.empty() == false){
      cout << pq2.top() << " ";
      pq2.pop();
  }

}