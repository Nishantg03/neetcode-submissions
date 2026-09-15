class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // Put all rotten fruits into queue
        // and count fresh fruits
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                
                if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty() && fresh > 0) {

            // Number of rotten fruits at this minute
            int size = q.size();

            // Process one complete level
            while(size--) {

                auto [r, c] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    // Valid cell and fresh fruit
                    if(nr >= 0 && nr < m &&
                       nc >= 0 && nc < n &&
                       grid[nr][nc] == 1) {

                        // Make it rotten
                        grid[nr][nc] = 2;

                        fresh--;

                        q.push({nr, nc});
                    }
                }
            }

            // One complete BFS level = one minute
            minutes++;
        }

        if(fresh == 0)
            return minutes;

        return -1;
    }
};