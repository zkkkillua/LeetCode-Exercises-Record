## 1. 记忆化
首先对矩阵进行初始化，记录以`[0, 0]`为左上角，`[i, j]`为右下角的正片矩形区域的总和即为`sums[i][j]`，则待求的任意部分的矩形区域都可以通过`O(1)`的数学运算实现。  
```cpp
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0)
            return;
        int n = matrix[0].size();
        sums = vector<vector<int>>(m, vector<int>(n, 0));

        sums[0][0] = matrix[0][0];
        for (int i = 1; i < n; i++)
            sums[0][i] = sums[0][i - 1] + matrix[0][i];
        for (int i = 1; i < m; i++)
            sums[i][0] = sums[i - 1][0] + matrix[i][0];
        for (int i = 1; i < m; i++) 
            for (int j = 1; j < n; j++)
                sums[i][j] = sums[i][j - 1] + sums[i - 1][j] - sums[i - 1][j - 1] + matrix[i][j];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (sums.size() == 0)
            return 0;
        int leftPart = col1 == 0 ? 0 : sums[row2][col1 - 1];
        int upPart = row1 == 0 ? 0 : sums[row1 - 1][col2];
        int upleftPart = (row1 == 0 || col1 == 0) ? 0 : sums[row1 - 1][col1 - 1];

        return sums[row2][col2] - leftPart - upPart + upleftPart;
    }
private:
    vector<vector<int>> sums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
```