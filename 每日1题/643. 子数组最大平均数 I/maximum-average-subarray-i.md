## 1. 滑动窗口
滑动窗口不断向右滑动，在此过程中记录区间的数据总和，记录最大值即可。  
时间`O(n)`，空间`O(1)`。  
```cpp
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = k, sum = 0, maxSum;   // [left, right)

        for (int i = 0; i < right; i++) 
            sum += nums[i];
        maxSum = sum;
        
        while (right < n) {
            sum += nums[right++];
            sum -= nums[left++];
            maxSum = max(maxSum, sum);
        }

        return static_cast<double>(maxSum) / k;
    }
};
```