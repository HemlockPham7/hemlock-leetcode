class Solution {
public:
    int row, col;

    bool dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= row || c < 0 || c >= col) {
            return false;
        }
        if (grid[r][c] == 1) {
            return true;
        }
        grid[r][c] = 1;
        bool closed = true;
        closed = dfs(grid, r - 1, c) && closed;
        closed = dfs(grid, r + 1, c) && closed;
        closed = dfs(grid, r, c - 1) && closed;
        closed = dfs(grid, r, c + 1) && closed;
        return closed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        row = (int) grid.size();
        col = (int) grid[0].size();

        int cnt = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j)) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};