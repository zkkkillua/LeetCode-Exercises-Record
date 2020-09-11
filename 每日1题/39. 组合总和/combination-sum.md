## 1. 递归和回溯
类似77.组合，递归+回溯不断选择新的元素，判断满足target时记录。  
但时间复杂度可能超级高？  
空间复杂度最坏为`O(target)`。  
```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sum = 0;
        dfs(candidates, 0, target);

        return ans;
    }

private:
    void dfs(vector<int>& candidates, int begin, int target) {
        if (sum > target)
            return;
        else if (sum == target) {
            ans.push_back(subAns);
            return;
        }

        int n = candidates.size();
        for (int i = begin; i < n; i++) {
            subAns.push_back(candidates[i]);
            sum += candidates[i];
            dfs(candidates, i, target);
            subAns.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> ans;
    vector<int> subAns;
    int sum;
};
```