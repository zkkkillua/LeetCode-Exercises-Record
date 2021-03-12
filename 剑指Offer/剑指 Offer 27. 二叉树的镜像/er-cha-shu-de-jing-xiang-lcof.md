## 1. 递归
```cpp
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root != nullptr) {
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
            root->left = mirrorTree(root->left);
            root->right = mirrorTree(root->right);
        }
        return root;
    }
};
```
  
## 2. 迭代
层次遍历访问每个节点，交换其左右子节点。  
```cpp
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        queue<TreeNode*> q;
        if (root != nullptr) 
            q.push(root);
        
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            TreeNode* temp = cur->left;
            cur->left = cur->right;
            cur->right = temp;
            if (cur->left != nullptr)
                q.push(cur->left);
            if (cur->right != nullptr)
                q.push(cur->right);
        }

        return root;
    }
};
```