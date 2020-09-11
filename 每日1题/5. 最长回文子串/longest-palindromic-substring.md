## 1. 暴力
遍历任意一个子串，判断是否是回文的。  
时间`O(n^3)`，空间`O(1)`。  
```cpp
class Solution {
public:
    bool isPalindromic(const string& s) {
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1])
                return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0)
            return s;

        int len = 1, start = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPalindromic(s.substr(i, j - i + 1)) && j - i + 1 > len) {
                    len = j - i + 1;
                    start = i;
                }
            }
        }

        return s.substr(start, len);
    }
};
```
  
## 2. 动态规划优化暴力算法
`bool dp[i][j]`记录ij段子串是否是回文串。  
`dp[i][j] = dp[i+1][j-1] && s[i] == s[j]`  
时间`O(n^2)`，空间`O(n^2)`。  
```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0)
            return s;
        
        bool** dp = new bool* [n];
        for (int i = 0; i < n; i++)
            dp[i] = new bool[n]{false};
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        
        int start = 0, len = 1;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (j == i + 1)
                    dp[i][j] = s[i] == s[j];
                else 
                    dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                
                if (dp[i][j] && j - i + 1 > len) {
                    len = j - i + 1;
                    start = i;
                }
            }
        }

        for (int i = 0; i < n; i++)
            delete []dp[i];
        delete []dp;

        return s.substr(start, len);
    }
};
```
  
## 3. 中心扩展法
从回文串的性质出发，每个回文串都是关于中心对称的。因此我们只需要对每个中点，向外扩展即可。  
回文子串的长度可能是奇数，也可能是偶数。  
- 奇数：中点为中间的那个字符。  
- 偶数：中点为两个字符之间的“间距”  
因此中心一共有`n + n - 1`个。  
对于每个中心，向左右两侧扩展，每次扩展最多扩展n/2次。  
因此时间`O(n^2)`，空间`O(1)`。  
```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0)
            return s;
        
        int len = 1, start = 0;

        // odd
        for (int i = 0; i < n; i++) {
            int l;
            for (l = 1; i - l >= 0 && i + l < n; l++)
                if (s[i - l] != s[i + l])
                    break;
            l--;
            if (2 * l + 1 > len) {
                len = 2 * l + 1;
                start = i - l;
            }
        }

        // even
        for (int i = 0; i < n - 1; i++) {
            int l;
            for (l = 1; i - l + 1 >= 0 && i + l < n; l++)
                if (s[i - l + 1] != s[i + l])
                    break;
            l--;
            if (2 * l > len) {
                len = 2 * l;
                start = i - l + 1;
            }
        }

        return s.substr(start, len);
    }
};
```
  
## 4. 最长公共子串
回文串正着读和倒着读都是相同的，因此可以找`s`和`s'`的最长公共子串。  
`s`和`t`的最长公共子串：  
设`dp[i][j]`是以`s[i-1], t[j-1]`为结尾字符的s和t的前i和前j部分公共子串的长度。  
（这样设方便处理i或j为0的情况。）  
`dp[i][j] = s[i] == t[j] ? dp[i-1][j-1] + 1 : 0`  
时间复杂度`O(n^2)`，空间复杂度`O(n^2)`。  
不过由于此处`dp[i][j]`的更新只需要`dp[i-1][j-1]`，所以可以通过逆序更新将空间复杂度降低到`O(n)`。  
**需要注意的是这种方法存在一定的问题**  
比如`abcdecba`，可以找到和它的逆序字符串的最长公共子串是`abc`(`cba`)，但它并不是回文串，这个可以通过索引位置来判断。  
```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0)
            return s;
        
        string revs(s);
        for (int i = 0; i < n; i++)
            revs[i] = s[n - i - 1];

        int* dp = new int[n + 1]{0};
        int len = 1, start = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = n; j > 0; j--) {
                dp[j] = s[i - 1] == revs[j - 1] ? dp[j - 1] + 1 : 0;
                if (i + j == n + dp[j] && dp[j] > len) {
                    len = dp[j];
                    start = i - dp[j];
                }
            }
        }

        delete []dp;
        return s.substr(start, len);
    }
};
```
  
## 5. Manacher's Algorithm
