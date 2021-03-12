## 1. 模拟
因为不好一个循环直接写出来，因此可以四个循环依次添加 从左到右、从上到下、从右到左、从下到上 四个方向的数据，同时注意调整边界。  
```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0)
            return {};
        int n = matrix[0].size();
        vector<int> res;

        int left = 0, right = n - 1, top = 0, bottom = m - 1;

        while (true) {
            for (int i = left; i <= right; i++)
                res.push_back(matrix[top][i]);
            if (++top > bottom)
                break;
            for (int i = top; i <= bottom; i++)
                res.push_back(matrix[i][right]);
            if (--right < left)
                break;
            for (int i = right; i >= left; i--)
                res.push_back(matrix[bottom][i]);
            if (--bottom < top)
                break;
            for (int i = bottom; i >= top; i--)
                res.push_back(matrix[i][left]);
            if (++left > right)
                break;
        }

        return res;
    }
};
```