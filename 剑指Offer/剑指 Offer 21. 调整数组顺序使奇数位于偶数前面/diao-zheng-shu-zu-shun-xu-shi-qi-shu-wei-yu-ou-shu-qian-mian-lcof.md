类似快排，双指针从左右两侧向中间靠拢，满足条件时二者指向的值互换位置。  
```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            if (nums[left] % 2 != 0)
                left++;
            else if (nums[right] % 2 != 1)
                right--;
            else
                swap(nums[left], nums[right]);
        }

        return nums;
    }
};
```