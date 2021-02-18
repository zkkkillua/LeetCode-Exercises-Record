## 1. 排序
一定是排序之后，两两组合，得到的每组的最小值的总和最大。  
因为如果已经排好序了，交换任意两组中的任意元素，得到的最小值的总和都不会比原来的总和大。  
时间`O(nlogn)`，空间`O(1)`。  
```cpp
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i += 2)
            sum += nums[i];
        
        return sum;
    }
};
```