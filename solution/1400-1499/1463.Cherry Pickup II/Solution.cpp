class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n)));
        vector<vector<vector<bool>>> valid(m, vector<vector<bool>>(n, vector<bool>(n)));
        dp[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
        valid[0][0][n - 1] = true;
        for (int i = 1; i < m; ++i) {
            for (int j1 = 0; j1 < n; ++j1) {
                for (int j2 = 0; j2 < n; ++j2) {
                    int t = grid[i][j1];
                    if (j1 != j2) t += grid[i][j2];
                    bool ok = false;
                    for (int y1 = j1 - 1; y1 <= j1 + 1; ++y1)
                        for (int y2 = j2 - 1; y2 <= j2 + 1; ++y2)
                            if (y1 >= 0 && y1 < n && y2 >= 0 && y2 < n && valid[i - 1][y1][y2]) {
                                dp[i][j1][j2] = max(dp[i][j1][j2], dp[i - 1][y1][y2] + t);
                                ok = true;
                            }
                    valid[i][j1][j2] = ok;
                }
            }
        }
        int ans = 0;
        for (int j1 = 0; j1 < n; ++j1)
            for (int j2 = 0; j2 < n; ++j2)
                ans = max(ans, dp[m - 1][j1][j2]);
        return ans;
    }
};