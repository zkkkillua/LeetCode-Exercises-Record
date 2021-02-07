## 1. 不是动态规划
首先考虑的是BFS+动态规划，但实际发现不怎么可行。  
首先这个问题没有明确的扩展方向，并不是只能朝右下方走，而是比如[0,0]更新完[0,1]和[1,0]之后，假如下次使用[0,1]，则其更新完到[1,1]的最短距离之后，这个值也可能影响已经更新过的[1,0]，所以动态规划是不可行的，也不满足无后效性。  
  
*但是实际写了一下bfs居然解题效果还不错？*  
```cpp
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        queue<pair<int, int>> q;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        dist[0][0] = 0;
        q.emplace(0, 0);
        while (!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();
            int x = temp.first, y = temp.second;
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols) {
                    int calDist = max(dist[x][y], abs(heights[nx][ny] - heights[x][y]));
                    if (dist[nx][ny] > calDist) {
                        dist[nx][ny] = calDist;
                        q.emplace(nx, ny);
                    }
                }
            }
        }

        return dist[rows - 1][cols - 1];
    }
};
```
  
## 2. 