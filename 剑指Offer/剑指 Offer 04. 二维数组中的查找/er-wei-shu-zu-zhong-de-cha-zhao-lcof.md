从左下角或者右上角开始，根据要查找元素的大小移动，每次都可以排除一行或者一列。  
时间`O(m+n)`，空间`O(1)`。  
```cpp
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();

        bool res = false;
        int i = 0, j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] < target) 
                i++;
            else if (matrix[i][j] > target) 
                j--;
            else {
                res = true;
                break;
            }
        }

        return res;
    }
};
```