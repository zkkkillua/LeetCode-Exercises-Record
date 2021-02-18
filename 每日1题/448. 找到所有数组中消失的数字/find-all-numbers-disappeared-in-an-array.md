## 1. 原地重排
题目要求不使用额外空间，则要么使用数学算法，要么在原数组基础上进行修改。  
通过分析没有发现有数学方法可以求出消失的数字，因此考虑在原数组的基础上进行调整。  
遍历数组，将每个元素`a[i]`都交换到索引为`a[i] - 1`的位置上。每交换一次，必有一个元素换到它对应的位置上，直到要交换的元素已经在它该在的位置上了。  
最终如果出现了的元素，则一定有一个在对应的索引位置上，如果索引对应的位置是其他元素，则说明该索引对应的元素值消失了。  
时间`O(n)`，空间`O(1)`。  
```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        for (int i = 0; i < n; i++) {
            while (nums[i] - 1 != i && nums[i] != nums[nums[i] - 1]) {
                int temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            }
        }
        for (int i = 0; i < n; i++)
            if (nums[i] - 1 != i)
                res.push_back(i + 1);
        
        return res;
    }
};
```