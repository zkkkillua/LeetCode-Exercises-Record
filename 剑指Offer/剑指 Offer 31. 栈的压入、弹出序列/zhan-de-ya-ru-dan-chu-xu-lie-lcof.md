## 1. 辅助栈
使用一个栈模拟压入过程，当弹出序列当前的位置与栈顶相等时，代表可以弹出。  
```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        int pushi = 0, popi = 0;
        bool res = true;

        while (popi < n) {
            if (st.empty() || popped[popi] != st.top()) {
                if (pushi < n)
                    st.push(pushed[pushi++]);
                else {
                    res = false;
                    break;
                }
            } else if (popped[popi] == st.top()) {
                st.pop();
                popi++;
            }
        }

        return res;
    }
};
```