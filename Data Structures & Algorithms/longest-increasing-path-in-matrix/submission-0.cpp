class Solution {
public:

    int dfs(int i, int j, vector<vector<int>>& matrix,
            vector<vector<int>>& dp) {

        // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 1;  // At least the current cell

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {

            int ni = i + dr[k];
            int nj = j + dc[k];

            // Check boundaries
            if (ni >= 0 && ni < m &&
                nj >= 0 && nj < n) {

                // Only move to a strictly bigger value
                if (matrix[ni][nj] > matrix[i][j]) {

                    ans = max(
                        ans,
                        1 + dfs(ni, nj, matrix, dp)
                    );
                }
            }
        }

        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(
            m,
            vector<int>(n, -1)
        );

        int answer = 0;

        // Start DFS from every cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                answer = max(
                    answer,
                    dfs(i, j, matrix, dp)
                );
            }
        }

        return answer;
    }
};