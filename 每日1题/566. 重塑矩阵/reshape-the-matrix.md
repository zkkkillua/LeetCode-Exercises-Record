## 1. 数学
使用一个变量`k`代表一维的个数，则`i = k / n, j = k % n`。  
时间`O(n)`，空间`O(1)`。  
```cpp
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size();
        int total = m * n;
        if (total != r * c)
            return nums;

        vector<vector<int>> res(r, vector<int>(c));
        for (int k = 0; k < total; k++)
            res[k / c][k % c] = nums[k / n][k % n];
        
        return res;
    }
};
```