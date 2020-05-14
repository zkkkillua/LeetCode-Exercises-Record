## 1. dfs
dfs记录根节点到p节点和q节点的路径，然后逆序比较这两条路径。  
时间复杂度：`O(n)`。  
空间复杂度：`O(n)`。  
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;

        vector<TreeNode*> pvec, qvec;
        stack
    }
};
```
```cpp
void preOrder(TreeNode* root) {
    if (root != nullptr) {
        cout << root->val << endl;
        preOrder(root->left);
        preOrder(root->right);
    }
}

void preOrder(TreeNode* root) {
    
}
```