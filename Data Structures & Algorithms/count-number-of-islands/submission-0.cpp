class Solution {
public:

    void dfs(vector<vector<char>>& grid,
             vector<vector<int>>& visited,
             int i, int j) {

        int n = grid.size();
        int m = grid[0].size();

        // Out of bounds
        if (i < 0 || i >= n || j < 0 || j >= m)
            return;

        // Water or already visited
        if (grid[i][j] == '0' || visited[i][j] == 1)
            return;

        // Mark current land as visited
        visited[i][j] = 1;

        // Go up
        dfs(grid, visited, i - 1, j);

        // Go down
        dfs(grid, visited, i + 1, j);

        // Go left
        dfs(grid, visited, i, j - 1);

        // Go right
        dfs(grid, visited, i, j + 1);
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        int count = 0;

        // Traverse every cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // New unvisited island found
                if (grid[i][j] == '1' && visited[i][j] == 0) {

                    count++;

                    // Mark the complete island
                    dfs(grid, visited, i, j);
                }
            }
        }

        return count;
    }
};