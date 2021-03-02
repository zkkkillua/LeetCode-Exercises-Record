## 1. 朴素
由于不是方阵，因此必须建立新数组，对应复制。  
时间`O(mn)`，空间`O(mn)`。  
```cpp
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> res(n, vector<int>(m));

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                res[i][j] = matrix[j][i];
        
        return res;
    }
};
```