class Solution {
public:

    void dfs(vector<vector<int>>& grid,
             vector<vector<int>>& visited,
             int i, int j,
             int& ct) {

        int n = grid.size();
        int m = grid[0].size();

        // Out of bounds
        if (i < 0 || i >= n || j < 0 || j >= m)
            return;

        // Water or already visited
        if (grid[i][j] == 0 || visited[i][j] == 1)
            return;

        // Mark visited
        visited[i][j] = 1;

        // Count this land cell
        ct++;

        // Up
        dfs(grid, visited, i - 1, j, ct);

        // Down
        dfs(grid, visited, i + 1, j, ct);

        // Left
        dfs(grid, visited, i, j - 1, ct);

        // Right
        dfs(grid, visited, i, j + 1, ct);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Found a new island
                if (grid[i][j] == 1 && visited[i][j] == 0) {

                    int ct = 0;

                    dfs(grid, visited, i, j, ct);

                    ans = max(ans, ct);
                }
            }
        }

        return ans;
    }
};
