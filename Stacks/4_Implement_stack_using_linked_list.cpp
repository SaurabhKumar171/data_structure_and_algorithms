class LinkedListStack {
public:
    int data;
    LinkedListStack* next;
    LinkedListStack* topNode;

public:
    LinkedListStack() {
        topNode = nullptr; // Initialize the stack as empty
    }

    LinkedListStack(int data1, LinkedListStack* next1) {
        data = data1;
        next = next1;
    }
    
    void push(int x) {
        LinkedListStack* newElement = new LinkedListStack(x, topNode);
        topNode = newElement;
    
    }
    
    int pop() {
        LinkedListStack* temp = topNode;
        int element = temp->data;
        topNode = topNode->next;
        delete temp;

        return element;
    }
    
    int top() {
        int element = topNode->data;
        return element;
    }
    
    bool isEmpty() {
        return topNode == nullptr;
    }
};