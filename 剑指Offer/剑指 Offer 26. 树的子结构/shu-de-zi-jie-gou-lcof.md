## 1. 递归
需要两个函数实现递归，一个负责选择共同开始的根节点，一个负责判断该根节点对应的两棵树是否是子树。  
时间`O(mn)`，空间`O(m)`  
```cpp
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr)
            return false;
        return hasSub(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
private:
    bool hasSub(TreeNode* A, TreeNode* B) {
        bool res = false;
        if (B == nullptr)
            res = true;
        else if (A != nullptr) {
            if (A->val == B->val)
                res = hasSub(A->left, B->left) && hasSub(A->right, B->right);
        }
        return res;
    }
};
```