Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
_____________________________

## 框架
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
    }
};
```

## 1. 尺取法/滑动窗口
定义左右l, r，r不断向右移动，当出现与lr串中相同的字母时，l串移动到前面的相同字母之后一个字母的位置。取r-l。`O(n)`  
第一次提交失败，错误是因为输入是" "，题目只说了字符串，character应该是字符。用map代替一下int loc;
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        map<char, int> loc;
        // int loc[26];
        // for(int i = 0; i < 26; i++)
        //     loc[i] = -1;    //初始化
        
        int length = s.size();
        int maxl = 0;

        while(r < length){
            if(loc.count(s[r]) && loc[s[r]] >= l)
                l = loc[s[r]] + 1;
            loc[s[r]] = r;
            r++;
            maxl = maxl < r - l ? r - l : maxl;
        }

        return maxl;
    }
};
```