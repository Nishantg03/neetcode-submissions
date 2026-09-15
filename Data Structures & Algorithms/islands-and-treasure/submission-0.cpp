class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        // Push all treasure cells into queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while(!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                // Boundary check
                if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                // Only visit INF cells
                if(grid[nr][nc] != 2147483647)
                    continue;

                // Update distance
                grid[nr][nc] = grid[r][c] + 1;

                // Push for next BFS level
                q.push({nr, nc});
            }
        }
    }
};