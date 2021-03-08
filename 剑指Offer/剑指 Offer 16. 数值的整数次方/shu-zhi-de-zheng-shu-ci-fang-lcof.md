```cpp
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        if (x == 0 && n != 0)
            res = 0;
        else if (n != 0) {
            x = n < 0 ? 1 / x : x;
            // n = abs(n);     // abs(-2147483648)不能表示，返回的还是INT_MIN，用abs()要谨慎
            long long expo = abs((long long) n);

            while (expo) {
                if (expo & 1)
                    res *= x;
                x *= x;
                expo >>= 1;
            }
        }
        
        return res;
    }
};
```