## 1. 辅助栈
用一个辅助栈储存非严格递减的元素。  
```cpp
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        st.push_back(x);
        if (minSt.empty() || x <= minSt.back())
            minSt.push_back(x);
    }
    
    void pop() {
        if (st.back() == minSt.back())
            minSt.pop_back();
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int min() {
        return minSt.back();
    }
private:
    vector<int> st, minSt;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
```