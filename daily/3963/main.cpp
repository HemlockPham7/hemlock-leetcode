class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, string(n, '#'));
        for (int i = 1; i < min(n, m); ++i) {
            ans[i - 1][i - 1] = ans[i - 1][i] = '.';
        }
        if (m < n) {
            for (int i = m - 1; i < n; ++i) {
                ans[m - 1][i] = '.';
            }
        } else if (m > n) {
            for (int i = n - 1; i < m; ++i) {
                ans[i][n - 1] = '.';
            }
        } else {
            ans[m - 1][n - 1] = '.';
        }
        return ans;
    }
};