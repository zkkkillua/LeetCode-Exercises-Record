## 1. 数学+贪心+快速幂
```cpp
class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3)
            return n - 1;
        int a = n / 3, b = n % 3;
        int res = 0;
        if (b == 0)
            res = fpow(3, a);
        else if (b == 1)
            res = (fpow(3, a - 1) * 4) % M;
        else
            res = (fpow(3, a) * 2) % M;
        
        return res;
    }
private:
    const int M = 1e9 + 7;
    long long fpow(long long x, int n) {
        long long res = 1;
        while (n != 0) {
            if (n & 1) 
                res = (res * x) % M;
            x = (x * x) % M;
            n >>= 1;
        }
        return res;
    }
};
```