## 1. 并查集
题目中要求找关联组的个数，实际上就是求连通分支的个数，每个连通分支内部的字符串满足题目中相似的要求。  
所以就是遍历每两个字符串`O(n^2)`，判断二者是否符合相似的要求`O(n)`，然后放入并查集中。  
带路径压缩的并查集的并和查操作大概都是对数级别的复杂度？  
相似的条件是，要么相同，要么交换一位，故只需要逐位比较，有0或2位不相同的，即为相似。  
因为如果2位不相同，则必是通过1次交换实现的；而1次交换也只能造成0位或2位不相同。  
```cpp
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();

        uf.resize(n);
        for (int i = 0; i < n; i++)
            uf[i] = i;
        
        for (int i = 0; i < n; i++) 
            for (int j = i + 1; j < n; j++) 
                if (checkSim(strs[i], strs[j]))
                    UFunion(i, j);
        
        int res = 0;
        for (int i = 0; i < n; i++)
            if (i == uf[i])
                res++;
        
        return res;
    }

private:
    vector<int> uf;

    int UFfind(int x) {
        return x == uf[x] ? x : uf[x] = UFfind(uf[x]);
    }

    void UFunion(int a, int b) {
        int pa = UFfind(a), pb = UFfind(b);
        if (pa != pb)
            uf[pb] = pa;
    }

    bool checkSim(string a, string b) {
        int len = a.length();
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (a[i] != b[i])
                count++;
            if (count > 2)
                break;
        }

        return count == 0 || count == 2;
    }
};
```