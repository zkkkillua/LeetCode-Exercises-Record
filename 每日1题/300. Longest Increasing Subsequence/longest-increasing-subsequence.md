Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
________________________  
  
### 框架
```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

    }
};
```
  
### 1. 朴素dp`O(n^2)`
设`dp[i]`为从`a[0]`到`a[i]`的最长上升子序列的长度。  
`dp[i]=max(dp[i], dp[j]+(a[i]>a[j]?1:0)), j<i`，需要遍历之前所有的`dp[j]`。  
  
### 2. dp+二分查找`O(nlogn)`
设`dp[i]`为长度为`i`的上升子序列的