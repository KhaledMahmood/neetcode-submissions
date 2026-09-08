class MinStack {
    stack<int> stk, minStk;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        if(minStk.empty()) {
            minStk.push(val);
        } else {
            minStk.push(min(minStk.top(), val));
        }
    }
    
    void pop() {
        stk.pop();
        minStk.pop();        
    }
    
    int top() {
        return stk.top();
        
    }
    
    int getMin() {
        return minStk.top();
        
    }
};
