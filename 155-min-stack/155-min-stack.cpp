class MinStack {
public:
    
    // most optimal - using constant space
    
    // uses a variable to keep track of min
    
    stack<long long> st;
    long long min_ele;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            min_ele = val;
        }
        else{
            // if val is more than min till now, no change
            if(val>min_ele){
                st.push(val);
            }
            // else val will be the new minimum
            // to recover prev min we insert 2*val - prev_min instead of val
            else{
                st.push(2LL*val-min_ele);
                min_ele = val;
            }
        }
    }
    
    // have to recover the previous min
    void pop() {
        // identifies that current top is the min
        if(st.top()<min_ele){
            long long prev_min = 2LL*min_ele-st.top();
            min_ele = prev_min; 
        }
        st.pop();
    }
    
    // original element in stack = 2*current_min - st.top() 
    int top() {
        if(st.top()<min_ele){
            return min_ele;
        }
        return st.top();
    }
    
    // directly return the min_ele, stored in variable
    int getMin() {
        return min_ele;
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