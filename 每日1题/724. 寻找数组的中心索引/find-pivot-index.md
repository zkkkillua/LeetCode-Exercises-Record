## 1. 遍历
遍历每个位置作为中心索引，左侧每次+1，右侧每次-1.  
时间`O(n)`，空间`O(1)`。  
```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        int lpart = 0, rpart = 0;
        for (int i = 1; i < n; i++)
            rpart += nums[i];
        
        int res = -1;
        for (int i = 0; i < n; i++) {
            if (lpart == rpart) {
                res = i;
                break;
            } else {
                lpart += nums[i];
                if (i + 1 < n)
                    rpart -= nums[i + 1];
            }
        }

        return res;
    }
};
```