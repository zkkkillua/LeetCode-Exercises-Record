## 1. 层次遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root != nullptr)
            q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            vector<int> subAns;
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                subAns.push_back(node->val);
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
            res.push_back(subAns);
        }

        return res;
    }
};
```