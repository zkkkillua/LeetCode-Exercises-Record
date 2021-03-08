```cpp
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        for (int i = 1; i < pow(10, n), i++)
            res.push_back(i);
        return res;
    }
};
```
  
大数：  
方法1：string模拟加法  
方法2：回溯枚举每一位数（因为模拟加法每次只+1，速度慢  
```cpp
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        string s(n, '0');
        dfs(res, s, 0, n);  // s的索引：0123456789...

        return res;
    }
private:
    void dfs(vector<int>& res, string& s, int idx, int n) {
        if (idx >= n) {
            int start = s.find_first_not_of('0');
            if (start != s.npos)
                res.push_back(stoi(s.substr(start)));
        } else {
            for (int i = 0; i <= 9; i++) {
                s[idx] = '0' + i;
                dfs(res, s, idx + 1, n);
            }
        }
    }
};
```