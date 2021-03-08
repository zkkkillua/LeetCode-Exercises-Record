```cpp
class Solution {
public:
    bool isNumber(string s) {
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
        int n = s.length();
        bool hasDot = false, hasE = false, hasNum = false;
        bool res = true;

        for (int i = 0; i < n; i++) {
            if (s[i] == '+' || s[i] == '-') {
                if (i > 0 && (s[i - 1] != 'e' && s[i - 1] != 'E')) {
                    res = false;
                    break;
                }
            } else if (s[i] == '.') {
                if (hasDot || hasE) {
                    res = false;
                    break;
                }
                hasDot = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (hasE || (!hasE && !hasNum)) {
                    res = false;
                    break;
                }
                hasE = true;
                hasNum = false;
            } else if (s[i] >= '0' && s[i] <= '9') {
                if (!hasNum)
                    hasNum = true;
            } else {
                res = false;
                break;
            }
        }
        if (!hasNum)
            res = false;
        
        return res;
    }
};
```