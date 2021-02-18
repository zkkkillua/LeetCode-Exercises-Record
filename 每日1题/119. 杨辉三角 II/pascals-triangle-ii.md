## 1. 数学
杨辉三角第k行的元素是C(k, i)，直接求解即可。  
有意思的是，这道题目的中文名叫杨辉三角，英文名叫pascal's triangle。  
时间`O(k)`，空间`O(k)`。  
```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for (int i = 1; i <= rowIndex; i++) 
            res[i] = ((long long)res[i - 1] * (rowIndex - i + 1)) / i;  // 此处虽然结果不会溢出，但过程会溢出

        return res;
    }
};
```