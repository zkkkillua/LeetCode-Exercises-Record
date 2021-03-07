## 1. 遍历
`O(n)`。  
  
## 2. 二分
`O(logn)`。  
```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        int left = 0, right = n, mid;
        while (left < right) {
            mid = (right - left) / 2 + left;
            if (numbers[mid] > numbers[right])
                left = mid + 1;
            else if (numbers[mid] < numbers[right])
                right = mid;
            else
                right--;
        }

        return numbers[left];
    }
};
```