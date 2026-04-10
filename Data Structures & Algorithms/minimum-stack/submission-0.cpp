class MinStack {
private:
    stack<pair<int, int>> stk;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty()){
            stk.push({val, val});
        }else{
            int temp = stk.top().second;
            stk.push({val, min(val, temp)});
        }
    }
    
    void pop() {
        stk.pop();
        
    }
    
    int top() {
        return stk.top().first;
        
    }
    
    int getMin() {
        return stk.top().second;
    }
};
