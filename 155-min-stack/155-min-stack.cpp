class StackItem {
private:
    const int val;
    const int smallest;

public:
    StackItem(int val, int smallest) : val(val), smallest(smallest){
        
    }
    
    int getVal() const {
        return val; 
    }
    
    int getSmallest() const {
        return smallest; 
    }
};

class MinStack {
private:
    std::stack<StackItem> stk;
    int minBelow = INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int newMin = std::min(minBelow, val);
        stk.push(StackItem(val, newMin));
        minBelow = newMin;
    }
    
    void pop() {
        stk.pop();
        if(stk.empty())
            minBelow = INT_MAX;
        else
            minBelow = getMin();
    }
    
    int top() const {
        return stk.top().getVal();
    }
    
    int getMin() const {
        return stk.top().getSmallest();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */