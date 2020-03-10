Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

![question](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg)
The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
_________________

## 框架
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        
    }
};
```

## 1. 朴素
遍历所有的section，直接比较大小。`O(n^2)`  
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                int temp = min(height[i], height[j]) * (j - i);
                ans = ans < temp ? temp : ans;
            }
        }

        return ans;
    }
};
```

## 2. 双指针法
一开始想的是尺取法，`l`和`r`不断向右移动。但是这样考虑的情况会比较多。  
假设`l`和`r`初始时各在最两侧，逐渐向中心移动，这样情况比较简单。  
横轴的距离是不断缩小的，所以每次移动的都是`y值`最小的一侧，从而可能得到较大的面积。`O(n)`  
移动小的一侧可能会得到较大的值，但是移动大的一侧，只能得到比当前的值更小的值。  
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = min(height[l], height[r]) * (r - l);

        while(r > l){
            if(height[l] <= height[r])
                l++;
            else
                r--;
            int temp = min(height[l], height[r]) * (r - l);
            ans = temp > ans ? temp : ans;
        }

        return ans;
    }
};
```