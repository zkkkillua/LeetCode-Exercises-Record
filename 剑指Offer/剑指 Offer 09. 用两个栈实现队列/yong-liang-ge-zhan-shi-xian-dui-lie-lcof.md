## 1. 双栈
一个输入栈和一个输出栈，不需要来回倒。  
```cpp
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        inStack.push(value);
    }
    
    int deleteHead() {
        if (outStack.empty())
            move();
        int res = -1;
        if (!outStack.empty()) {
            res = outStack.top();
            outStack.pop();
        }

        return res;
    }
private:
    stack<int> inStack, outStack;
    void move() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```