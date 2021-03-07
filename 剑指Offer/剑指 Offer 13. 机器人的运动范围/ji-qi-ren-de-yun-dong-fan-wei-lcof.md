## 1. bfs
复杂度`O(mn)`。  
```cpp
class Solution {
public:
    int movingCount(int m, int n, int k) {
        int res = 1;
        queue <pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        if(0 <= k)
            q.emplace(0, 0);
        vis[0][0] = true;
        
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            for (int r = 0; r < 2; r++) {
                int nexti = cur.first + di[r], nextj = cur.second + dj[r];
                if (nexti < m && nextj < n && check(nexti, nextj, k) && !vis[nexti][nextj]) {
                    q.emplace(nexti, nextj);
                    vis[nexti][nextj] = true;
                    res++;
                }
            }
        }

        return res;
    }
private:
    bool check(int i, int j, int k) {
        int sum = 0;
        while (i != 0) {
            sum += i % 10;
            i /= 10;
        }
        while (j != 0) {
            sum += j % 10;
            j /= 10;
        }
        return sum <= k;
    }
    int di[2] = {0, 1};
    int dj[2] = {1, 0};
};
```