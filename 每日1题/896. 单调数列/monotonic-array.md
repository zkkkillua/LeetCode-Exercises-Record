## 1. 遍历
初始两个bool变量为true，代表既是递增又是递减。遍历数组修改两个变量，如果不是单调，则两个都会变为false。  
时间`O(n)`，空间`O(1)`。  
```cpp
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        bool inc = true, dec = true;

        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1])
                dec = false;
            if (A[i] < A[i - 1])
                inc = false;
            if (!dec && !inc)
                break;
        }

        return inc || dec;
    }
};
```