## 1. bool数组
bool数组做标记，时间`O(n)`，空间`O(n)`。  
```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);

        int res = -1;
        for (int i = 0; i < n; i++) {
            if (visited[nums[i]]) {
                res = nums[i];
                break;
            } else 
                visited[nums[i]] = true;
        }

        return res;
    }
};
```
  
## 2. 排序
在`O(nlogn)`的排序之后，比较相邻的元素。  
```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int res = -1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                res = nums[i];
                break;
            }
        }

        return res;
    }
};
```
  
## 3. 原地重排
bool数组需要额外的空间，排序需要更长的时间。  
考虑到给定的`n`个数据大小是`0 ~ n - 1`，因此可以考虑原地重排。  
每次移动都可以将一个数据移动到它该在的位置，因此时间复杂度降低到`O(n)`，并且在数组基础上修改，不需要额外的空间。  
```cpp
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();

        int res = -1;
        for (int i = 0; i < n; i++) {
            if (i != nums[i]) {
                if (nums[i] != nums[nums[i]]) {
                    int temp = nums[nums[i]];
                    nums[nums[i]] = nums[i];
                    nums[i] = temp;
                } else {
                    res = nums[i];
                    break;
                }
            }
        }

        return res;
    }
};
```