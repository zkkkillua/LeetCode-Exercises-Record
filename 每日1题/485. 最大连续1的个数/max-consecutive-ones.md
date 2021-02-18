## 1. 滑动窗口
右边界向右移动，直到遇到0，统计此时长度，并左右窗口同时向后移动，重新开始。  
时间`O(n)`，空间`O(1)`。  
```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int maxLen = 0;

        while (right < n) {
            if (nums[right] == 0) {
                maxLen = max(maxLen, right - left);
                left = right + 1;
            }
            right++;
        }
        maxLen = max(maxLen, right - left);

        return maxLen;
    }
};
```