## 1. 原地
时间`O(n)`，空间`O(1)`。  
```cpp
class Solution {
public:
    string removeDuplicates(string S) {
        int n = S.length();
        int left = 1, right = 1;
        while (right < n) {
            S[left] = S[right++];
            if (left > 0 && S[left] == S[left - 1]) 
                left--;
            else
                left++;
        }

        S.resize(left);
        return S;
    }
};
```
  
## 2. 栈
使用辅助栈，同时string本身也类似栈。  
时间`O(n)`。  
```cpp
class Solution {
public:
    string removeDuplicates(string S) {
        string res;     // string 具有 pop_back() & push_back() & front() & back()
        for (int i = 0; i < S.length(); i++) {
            if (!res.empty() && res.back() == S[i])
                res.pop_back();
            else
                res.push_back(S[i]);
        }
        return res;
    }
};
```