## 1. hash表
交换后二者各自的和相等，因此首先求出两个人总和的一半，然后少的与多的交换，换到两个人都是总和的一半。  
交换可以是遍历A的每一个数据，在B中找有没有一个数据能够满足交换之后，二者总和相等，这样的时间复杂度是`O(n^2)`。  
使用hash表可以将在B中查找的复杂度降低到`O(1)`，使得最终的时间复杂度为`O(1)`。  
```cpp
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int na = A.size(), nb = B.size();
        int sumA = 0, sumB = 0, sumHalf = 0;
        unordered_set<int> tableA, tableB;
        vector<int> ans(2);

        for (int i = 0; i < na; i++) {
            sumA += A[i];
            tableA.emplace(A[i]);
        }
        for (int i = 0; i < nb; i++) {
            sumB += B[i];
            tableB.emplace(B[i]);
        }

        sumHalf = (sumA + sumB) / 2;
        int gap = sumHalf - sumA;
        for (int i = 0; i < na; i++) {
            if (tableB.count(gap + A[i])) {
                ans[0] = A[i];
                ans[1] = gap + A[i];
                break;
            }
        }

        return ans;
    }
};
```