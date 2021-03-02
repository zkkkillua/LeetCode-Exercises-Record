## 1. 滑动窗口
右窗口向右滑动直到不可移动，然后左窗口向右滑动直到跳过1个0，继续右窗口滑动。  
时间`O(n)`，空间`O(1)`。  
```cpp
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        int left = 0, right = 0, res = 0;

        while (right < n) {
            if (A[right] == 1)
                right++;
            else if (A[right] == 0 && K > 0) {
                K--;
                right++;
            }
            else if (A[right] == 0 && K == 0) {
                res = max(res, right - left);
                if (left == right) {
                    left++;
                    right++;
                } else {
                    while (left < right) {
                        if (A[left] == 0) {
                            K++;
                            left++;
                            break;
                        }
                        left++;
                    }
                }
            }
        }
        res = max(res, right - left);

        return res;
    }
};
```