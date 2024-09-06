class QueueStack {

public:
   queue<int> q;

public:
    QueueStack() {

    }
    
    void push(int x) {
        int s = q.size();

        q.push(x);

        for(int i = 0; i < s; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int element = q.front();
        q.pop();

        return element;
    }
    
    int top() {
        return q.front();
    }
    
    bool isEmpty() {
        return q.size() == 0;
    }
};