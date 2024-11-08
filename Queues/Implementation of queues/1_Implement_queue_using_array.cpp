class ArrayStack {
private:
    int size;
    int topIndex;
    int* st;

public:
    ArrayStack(int size1 = 1000) {
        size = size1;
        st = new int[size];
        topIndex = -1;
    }

    ~ArrayStack(){
        delete[] st;
    }
    
    void push(int x) {
        if(topIndex >= size){
            cout << "Stack oveflow"<< endl;
            return;
        }

        st[++topIndex] = x;
    }
    
    int pop() {
        if(isEmpty()){
            cout << "Stack is empty"<< endl;
            // return invalid value
            return -1;
        }  

        return st[topIndex--];
    }   
    
    int top() {
        if(isEmpty()){
            cout << "Stack is empty"<< endl;
            // return invalid value
            return -1;
        }

        return st[topIndex];
    }
    
    bool isEmpty() {
        return topIndex == -1;
    }
};