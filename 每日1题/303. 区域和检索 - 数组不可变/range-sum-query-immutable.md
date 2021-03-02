## 1. 朴素
每次计算时间复杂度为`O(n)`，如果需要频繁使用，则重复计算较多，时间复杂度较高。  
  
## 2. 前缀和
使用数组记录从开头到当前元素的总和，在复杂度为`O(n)`的预处理之后，每次计算区间和的时间复杂度为`O(1)`。  
```cpp
class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sums.resize(n + 1, 0);
        for (int i = 1; i <= n; i++)
            sums[i] = sums[i - 1] + nums[i - 1];
    }
    
    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
```