## 1. 分治
要求字符串中每一字符的出现次数都>=k，则首先统计字母次数，使用频率小于k的字符将字符串分割成多部分。  
然后对分成的子部分继续如上操作，直到某一字符串中的字符次数全部>=k。  
```cpp
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        if (n < k)
            return 0;

        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++)
            freq[s[i] - 'a']++;

        bool allBigger = true;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0 && freq[i] < k) {
                allBigger = false;
                break;
            }
        }
        if (allBigger)
            return n;
        
        int start = 0, res = 0;
        for (int i = 0; i < n; i++) {
            if (freq[s[i] - 'a'] < k) {
                if (start == i)
                    start++;
                else {
                    res = max(res, longestSubstring(s.substr(start, i - start), k));
                    start = i + 1;
                }
            } else if (i == n - 1)
                res = max(res, longestSubstring(s.substr(start, i - start + 1), k));
        }

        return res;
    }
};
```