class MinStack {
public:
stack<int>mainstk;
stack<int>minstk;
    MinStack() {
        //constructor , no specific intialization is needed so leave it empty
    }
    
    void push(int val) {
        mainstk.push(val);
        if(minstk.empty() || minstk.top()>val){
            minstk.push(val);
        }else minstk.push(minstk.top());
    }
    
    void pop() {
        if(!mainstk.empty()){
        minstk.pop();
        mainstk.pop();
        }
        //both from both to maintain the synchronism
    }
    
    int top() {
        return mainstk.top();
    }
    
    int getMin() {
        return minstk.top();
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