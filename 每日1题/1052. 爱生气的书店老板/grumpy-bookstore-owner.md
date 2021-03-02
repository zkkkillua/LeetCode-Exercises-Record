## 1. 滑动窗口
固定窗口大小为`X`，向右移动，在此过程中记录最大顾客满意数。  
时间`O(n)`，空间`O(1)`。  
```cpp
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        int left = 0, right = X;
        int res = 0, ang = 0;

        for (int i = 0; i < right; i++)
            if (grumpy[i])
                ang += customers[i];
        res = ang;
        
        while (right < n) {
            if (grumpy[right])
                ang += customers[right];
            if (grumpy[left])
                ang -= customers[left];
            right++;
            left++;
            res = max(res, ang);
        }

        for (int i = 0; i < n; i++)
            if (!grumpy[i])
                res += customers[i];

        return res;
    }
};
```