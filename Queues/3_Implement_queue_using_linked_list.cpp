// Node structure 
struct Node {
    int data; 
    Node* next; 
};

class LinkedListQueue {
public:
    Node* start;
    Node* end;
    int size;

public:
    LinkedListQueue(){
        start = end = nullptr;
        size = 0;
    }

    void push(int x) {
        // Create a new node
        Node* temp = new Node();
        // Assign data 
        temp->data = x; 
        // Set next to nullptr
        temp->next = nullptr; 

        if(start == NULL){
            start = end = temp;
        }
        else{
            // Link new node
            end->next = temp; 
            // Update end
            end = temp; 
        }
        size++;
    }
    
    int pop() {
        if(start == NULL){
            cout << "Queue is empty" << endl;
            return -1;      
        }

        Node* temp = start;
        int data = start->data;
        start = start->next;

        delete temp;
        size--;

          // If queue is now empty
        if (start == nullptr) {
            end = nullptr; 
        }

        return data; 
    }
    
    int peek() {
        if(start == NULL){
            cout << "Queue is empty" << endl;
            return -1;      
        }

        return start->data;; 
    }
    
    bool isEmpty() {
        return size == 0;
    }
};