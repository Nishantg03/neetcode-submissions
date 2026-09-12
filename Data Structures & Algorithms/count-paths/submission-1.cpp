class Solution {
public:
    int solve(int m, int n, int i, int j, vector<vector<int>>& dp) {

        // Reached destination
        if(i == m - 1 && j == n - 1) {
            return 1;
        }

        // Already calculated
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int down = 0;
        int right = 0;

        // Move down
        if(i + 1 < m) {
            down = solve(m, n, i + 1, j, dp);
        }

        // Move right
        if(j + 1 < n) {
            right = solve(m, n, i, j + 1, dp);
        }

        return dp[i][j] = down + right;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m, n, 0, 0, dp);
    }
};