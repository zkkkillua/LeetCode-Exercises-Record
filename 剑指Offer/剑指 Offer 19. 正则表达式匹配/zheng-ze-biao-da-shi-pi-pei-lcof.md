## 1. dp
`dp[i][j]`代表s的前i个和p的前j个字符是否匹配  
```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.length(), np = p.length();
        vector<vector<bool>> match(ns + 1, vector<bool>(np + 1, false));

        match[0][0] = true;
        for (int i = 2; i <= np; i += 2)
            match[0][i] = match[0][i - 2] && p[i - 1] == '*';

        for (int i = 1; i <= ns; i++) {
            for (int j = 1; j <= np; j++) {
                if (p[j - 1] != '*')
                    match[i][j] = match[i - 1][j - 1] && (p[j - 1] == '.' || s[i - 1] == p[j - 1]);
                else
                    match[i][j] = match[i][j - 2] || (match[i - 1][j] && (p[j - 2] == '.' || s[i - 1] == p[j - 2]));
            }
        }

        return match[ns][np];
    }
};
```