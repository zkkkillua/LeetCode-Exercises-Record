## 1. `string.replace()`
`string.replace(pos, len, string)`  
```cpp
class Solution {
public:
    string replaceSpace(string s) {
        for (int i = 0; i < s.length(); i++)
            if (s[i] == ' ') {
                s.replace(i, 1, "%20");
                i += 2;
            }
        
        return s;
    }
};
```
  
## 2. 定义另一个变量
```cpp
class Solution {
public:
    string replaceSpace(string s) {
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ')
                res += "%20";
            else 
                res += s[i];
        }
        
        return res;
    }
};
```
  
## 3. 提前计算
首先遍历一次获得空格的总个数，然后扩展s，从后向前更新。  
同`vector`，`string`也可以利用`resize()`来修改长度。  
```cpp
class Solution {
public:
    string replaceSpace(string s) {
        int n = s.length();
        int freq = 0;

        for (int i = 0; i < n; i++)
            if (s[i] == ' ')
                ++freq;
        s.resize(n + 2 * freq);

        for (int i = n - 1; i >= 0 && freq > 0; --i) {
            if (s[i] != ' ') 
                s[i + 2 * freq] = s[i];
            else {
                --freq;
                s[i + 2 * freq] = '%';
                s[i + 2 * freq + 1] = '2';
                s[i + 2 * freq + 2] = '0';
            }
        }

        return s;
    }
};
```