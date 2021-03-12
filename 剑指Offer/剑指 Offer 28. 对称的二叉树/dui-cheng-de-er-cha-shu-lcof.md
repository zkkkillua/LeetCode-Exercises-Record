## 1. 递归
镜像对称：左左==右右 && 左右==右左  
```cpp
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        bool res = false;
        if (root == nullptr)
            res = true;
        else 
            res = isSame(root->left, root->right);

        return res;
    }

private:
    bool isSame(TreeNode* t1, TreeNode* t2) {
        bool res = false;
        if (t1 == nullptr && t2 == nullptr)
            res = true;
        else if (t1 != nullptr && t2 != nullptr)
            res = t1->val == t2->val && isSame(t1->left, t2->right) && isSame(t1->right, t2->left);
        return res;
    }
};
```