class Solution {
public:
    int row, col;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    long long bfs(const vector<vector<int>>& grid, vector<vector<int>>& visited, int r, int c) {
        long long sum = 0;

        vector<pair<int, int>> queue;
        queue.push_back({r, c});
        visited[r][c] = -1;

        for (int i = 0; i < queue.size(); ++i) {
            auto [y, x] = queue[i];
            sum += 1LL * grid[y][x];

            for (int d = 0; d < 4; ++d) {
                int yy = y + dy[d];
                int xx = x + dx[d];
                if (xx < 0 || xx >= col || yy < 0 || yy >= row) {
                    continue;
                }
                if (grid[yy][xx] != 0 && visited[yy][xx] == 0) {
                    queue.push_back({yy, xx});
                    visited[yy][xx] = -1;
                }
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        row = (int) grid.size();
        col = (int) grid[0].size();
        vector<vector<int>> visited(row, vector<int> (col, 0));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 0) {
                    visited[i][j] = -1;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] != 0 && visited[i][j] != -1) {
                    long long sum = bfs(grid, visited, i, j);
                    if (sum % (1LL * k) == 0) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};