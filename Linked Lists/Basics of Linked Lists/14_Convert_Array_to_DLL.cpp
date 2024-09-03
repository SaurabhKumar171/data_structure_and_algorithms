#include <iostream>
using namespace std;


class Node{
  public:
    int data;
    Node* next;
    Node* back;

  public:
    Node(int data1, Node* next1, Node* back1){
      data = data1;
      next = next1;    
      back = back1;
    }

  public:
    Node(int data1){
      data = data1;
      next = nullptr;
      back = nullptr;
    }
};

Node* converArrToDll(int arr[5], int n){

  Node* head = new Node(arr[0]);
  Node* current = head;

  for(int i = 1; i < n; i++){
    Node* newNode = new Node(arr[i]);
    newNode->back = current;
    current->next = newNode;

    current = newNode;
  }

  return head;
}

// Function to print the Doubly Linked List
void printDll(Node* head) {
  Node* current = head;
  while (current != nullptr) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

int main() {
  int arr[5] = {5, 3, 8, 9, 0};

  Node* head = converArrToDll(arr, 5);
  printDll(head);

  return 0;
}     