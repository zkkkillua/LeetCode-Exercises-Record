## 1. dfs 
空字符`\0`代表访问过。  
时间`O(mn*4^k)`代表可能任意起点开始每次都最长有4^k种可能，空间`O(k)`。  
```cpp
class Solution {
public:
    bool check(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    bool dfs(vector<vector<char>>& board, string word, int sloc, int i, int j) {
        if (sloc == word.length())
            return true;
        bool res = false;
        for (int k = 0; k < 4; k++) {
            int nexti = i + di[k], nextj = j + dj[k];
            if (check(nexti, nextj) && board[nexti][nextj] == word[sloc]) {
                char temp = board[nexti][nextj];
                board[nexti][nextj] = '\0';
                res = dfs(board, word, sloc + 1, nexti, nextj);
                board[nexti][nextj] = temp;
                if (res)
                    break;
            }
        }
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        bool res = false;
        if (word.empty())
            res = true;
        else {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == word[0]) {
                        char temp = board[i][j];
                        board[i][j] = '\0';
                        res = dfs(board, word, 1, i, j);
                        board[i][j] = temp;
                        if (res)
                            break;
                    }
                }
                if (res)
                    break;
            }
        }

        return res;
    }
private:
    int m, n;
    const int di[4] = {-1, 1, 0, 0};
    const int dj[4] = {0, 0, -1, 1};
};
```