#include <iostream>
#include <vector>
using namespace std;

struct Node {
  public:
  int data;
  Node* next;

  public:
  Node(int data1, Node* next1){
    data = data1;
    next = next1;
  }

  public:
  Node(int data1){
    data = data1;
    next = nullptr;
  }
};

int main() {
  vector<int> arr = {3, 5, 7 ,9};

  Node* y = new Node(arr[0]);
  cout << y->data;
}