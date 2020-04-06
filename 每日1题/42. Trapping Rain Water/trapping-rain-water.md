## 框架
```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        
    }
};
```
  
## 1. 按列计算+dp
首先想到的是计算出一个“坑”，然后算这个坑可以储存多少水。  
但实际上也可以按列计算，计算每一列可以储存多少水，然后求和。  
算每一列存水的数量的方法就是找到该位置左侧的最大值和右侧的最大值，从而围成一个“坑”。  
所以：遍历每一个柱子，然后查找其左侧的最大值和右侧的最大值，时间复杂度是`O(n^2)`。  
可以使用记忆化搜索，`leftIndex[i]`和`rightIndex[i]`分别记录第i个元素左侧的最大高度的索引和右侧最大高度的索引。  
转移方程为`leftIndex[i] = i-1 || leftHeight[i-1]`  
这样，时间复杂度就降低为`O(n)`，而空间复杂度升高为`O(n)`。  
```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        vector<int> leftIndex(n, 0), rightIndex(n, n - 1);
        for (int i = 1; i < n - 1; i++) {
            leftIndex[i] = height[leftIndex[i - 1]] >= height[i - 1] ? leftIndex[i - 1] : i - 1;
            rightIndex[n - i - 1] = height[rightIndex[n - i]] >= height[n - i] ? rightIndex[n - i] : n - i;
        }

        for (int i = 1; i < n - 1; i++) {
            int minHeight = min(height[leftIndex[i]], height[rightIndex[i]]);
            if (minHeight > height[i])
                ans += minHeight - height[i];
        }

        return ans;
    }
};
```
  
## 2. 单调栈

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        
    }
};
```