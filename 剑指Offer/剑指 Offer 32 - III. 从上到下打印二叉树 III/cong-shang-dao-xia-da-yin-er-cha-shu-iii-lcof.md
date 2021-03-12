# 1. 双端队列
可以正常层次遍历获得每层元素之后再reverse()，但效率较低。  
使用双端队列：  
当访问的是奇数层时，从左向右访问，子节点从左向右添加到deque的尾部；  
当访问的是偶数层时，从右向左访问，子节点从右向左添加到deque的头部。  
```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        deque<TreeNode*> dq;
        int level = 1;
        if (root != nullptr)
            dq.push_front(root);
        
        while (!dq.empty()) {
            int n = dq.size();
            vector<int> subRes;
            TreeNode* node;
            for (int i = 0; i < n; i++) {
                if (level % 2 == 1) {
                    node = dq.front();
                    dq.pop_front();
                    if (node->left != nullptr)
                        dq.push_back(node->left);
                    if (node->right != nullptr)
                        dq.push_back(node->right);
                } else {
                    node = dq.back();
                    dq.pop_back();
                    if (node->right != nullptr)
                        dq.push_front(node->right);
                    if (node->left != nullptr)
                        dq.push_front(node->left);
                }
                subRes.push_back(node->val);
            }
            level++;
            res.push_back(subRes);
        }

        return res;
    }
};
```