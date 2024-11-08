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

Node* convertArrayToLinkedList(vector<int> arr){

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++){
        Node* newNode = new Node(arr[i]);
        mover->next = newNode;

        mover = newNode;
    }

    return head; 
}

int main() {
  vector<int> arr = {5, 7 ,9};

  Node* head = convertArrayToLinkedList(arr);

  Node* temp = head;
  int cnt = 0;

  while(temp){
    temp = temp->next;
    cnt++;
  }

  cout << cnt;
}