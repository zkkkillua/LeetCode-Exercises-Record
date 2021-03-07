## 1. dp
f[0] = 1;
f[1] = 1;
f[2] = f[0] + f[1];
f[n] = f[n - 2] + f[n - 1];
```cpp
class Solution {
public:
    int numWays(int n) {
        const int M = 1e9 + 7;
        int a = 1, b = 1;
        while (n--) {
            int c = (a + b) % M;
            a = b;
            b = c;
        }

        return a;
    }
};
```