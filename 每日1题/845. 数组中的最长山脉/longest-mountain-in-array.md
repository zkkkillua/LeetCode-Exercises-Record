## 1. 双指针
使用双指针表示山脉的左右边界，序列上升时不断r++，使用一个bool变量记录数据是否上升过。  
在上升阶段出现相等时，放弃左部分；在下降阶段出现相等时，右边界终止。  
时间`O(n)`，空间`O(1)`。  
```cpp
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        if (n < 3)
            return 0;

        int l = 0, r = 0, ans = 0;
        while (r < n - 1) {
            bool up = true;
            while (r + 1 < n && A[r + 1] > A[r]) {
                if (up)
                    up = false;
                r++;
            }

            if (r + 1 < n && A[r + 1] == A[r]) {
                l = r + 1;
                r = r + 1;
                continue;
            }
            
            bool down = true;
            while (r + 1 < n && A[r + 1] < A[r]) {
                if (down)
                    down = false;
                r++;
            }

            if (!up && !down) 
                ans = max(ans, r - l + 1);
            
            l = r;
            r = r;
        }

        return ans;
    }
};
```