## 1. 递归
二叉搜索树的节点大小有这个性质：左 < 根 < 右  
而后序遍历得到的整体上是 左 | 右 | 根  
因此最后一个一定是根节点，左右子树边界的判断是，左子树的值一定小于根节点，右子树的值一定大于根节点。  
同样地，也可以根据这个性质直接由前序遍历或者后序遍历构建出一棵二叉搜索树。  
  
时间最差`O(n^2)`，当树退化成链表时；空间`O(n)`。  
```cpp
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int n = postorder.size();

        return subVerify(postorder, 0, n - 1);
    }
private:
    bool subVerify(vector<int>& postorder, int left, int right) {
        if (left >= right)
            return true;
        
        int sep = left;
        while (sep < right) {
            if (postorder[sep] < postorder[right])
                sep++;
            else
                break;
        }
        for (int i = sep; i < right; i++)
            if (postorder[i] < postorder[right])
                return false;

        return subVerify(postorder, left, sep - 1) && subVerify(postorder, sep, right - 1);
    }
};
```