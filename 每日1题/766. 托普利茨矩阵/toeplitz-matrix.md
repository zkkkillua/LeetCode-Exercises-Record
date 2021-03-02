## 1. 遍历
`matrix[i][j]`右下方的数据为`matrix[i+1][j+1]`.  
时间`O(mn)`，空间`O(1)`。  
```cpp
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool res = true;

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (matrix[i][j] != matrix[i + 1][j + 1]) {
                    res = false;
                    break;
                }
            }
        }

        return res;
    }
};
```