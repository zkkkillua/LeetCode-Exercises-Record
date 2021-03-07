## 1. 记忆化
时间复杂度`O(n)`，空间复杂度优化到`O(1)`  
```cpp
class Solution {
public:
    int fib(int n) {
        int fa = 0, fb = 1;
        const int M = 1e9 + 7;

        for (int i = 2; i <= n; i++) {
            int fc = (fa % M + fb % M) % M;
            fa = fb;
            fb = fc;
        }

        return n == 0 ? 0 : fb;
    }
};
```
  
## 2. 快速幂
```
-              -         -      -
| f(n+1) f(n)  |    =    | 1  1 | ^ n
| f(n)  f(n-1) |         | 1  0 |
-              -         -      -
```
```cpp
const int M = 1e9 + 7;

struct matrix {
    long long arr[2][2];
    
    matrix(long long a = 0, long long b = 0, long long c = 0, long long d = 0) {
        arr[0][0] = a;
        arr[0][1] = b;
        arr[1][0] = c;
        arr[1][1] = d;
    }

    friend matrix operator * (const matrix& a, const matrix& b) {
        matrix res;
        for (int i = 0; i < 2; i++) 
            for (int j = 0; j < 2; j++) 
                for (int k = 0; k < 2; k++) 
                    res.arr[i][j] = (res.arr[i][j] % M + a.arr[i][k] % M * b.arr[k][j] % M) % M;
        
        return res;
    }
};

class Solution {
public:
    int fib(int n) {
        matrix m(1, 1, 1, 0), res(1, 0, 0, 1);
        while (n != 0) {
            if (n & 1)
                res = res * m;
            m = m * m;
            n >>= 1;
        }

        return res.arr[0][1];
    }
};
```