## 1. 暴力
遍历每一种英文字符，然后以它作为开始，遍历字符串的每个位置作为起点，然后向后遍历得到最长的长度。  
时间`O(n^2)`，空间`O(1)`。  
```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int res = min(n, k);

        for (int ci = 0; ci < 26; ci++) {
            for (int i = 0; i < n - k; i++) {
                int count = 0;
                int j;
                for (j = i; j < n; j++) {
                    if (s[j] != 'A' + ci && count < k)
                        count++;
                    else if (s[j] != 'A' + ci && count == k)
                        break;
                }
                res = max(res, j - i);
            }
        }

        return res;
    }
};
```
  
## 2. 滑动窗口
方法1中判断一段子串是否能满足题目要求的方法是，遍历字母表，以其作为要替换的字母，然后向后找最长能多长。  
但实际上，可以统计这段子串中出现次数最多的字母，然后看剩余的其他字母的总和是否小于等于k即可。  
因此我们可以维护一个滑动窗口及这个窗口内部各字母的出现次数，取出现次数最多的字母作为要变成的字母，不断向右扩展。  
当超过k时，左和右窗口向右滑动1个位置，然后循环这两条操作。  
**虽然这样的操作会导致部分区间不符合条件，即该区间内非最长重复字符超过了k个。但是这样的区间也同样不可能对答案产生贡献。**  
时间`O(n)`，空间`O(1)`。  
```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int charCounter[26]{};
        int maxCount = 0;       // maxCount 保存的始终是经历过的窗口的重复个数的最大值
        int left = 0, right = 0;

        while (right < n) {
            charCounter[s[right] - 'A']++;
            maxCount = max(maxCount, charCounter[s[right] - 'A']);
            right++;

            if (right - left > maxCount + k) 
                charCounter[s[left++] - 'A']--;
        }
        
        return right - left;    // 窗口的大小被限制在，要么一直没有超过maxCount + k，要么超过了，但是又因为左右边界同时右移一直维护着窗口大小，直到遇到更大的maxCount。
    }
};
```