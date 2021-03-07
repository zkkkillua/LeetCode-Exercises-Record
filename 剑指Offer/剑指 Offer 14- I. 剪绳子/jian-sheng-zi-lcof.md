## 1. 数学+贪心
```cpp
class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3)
            return n - 1;
        int a = n / 3, b = n % 3;
        int res;
        if (b == 0)
            res = pow(3, a);
        else if (b == 1)
            res = pow(3, a - 1) * 4;
        else 
            res = pow(3, a) * 2;
        return res;
    }
};
```