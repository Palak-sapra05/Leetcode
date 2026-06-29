class MinStack {
    stack<int> main;
    stack<int> min;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        main.push(value);
        if(min.empty() or value<=min.top()) min.push(value);
    }
    
    void pop() {
        if(main.empty()) return;
        int val=main.top();
        if(val==min.top()) min.pop();
        main.pop();
    }
    
    int top() {
        return (main.empty()?-1:main.top());
    }
    
    int getMin() {
        if(min.empty()){
            return -1;
        }
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */