class Solution {
public:

    int m, n;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(vector<vector<char>>& board, int r, int c) {

        // Outside
        if(r < 0 || r >= m || c < 0 || c >= n)
            return;

        // Only process O
        if(board[r][c] != 'O')
            return;

        // Mark as safe
        board[r][c] = 'S';

        for(int k = 0; k < 4; k++) {
            dfs(board, r + dr[k], c + dc[k]);
        }
    }


    void solve(vector<vector<char>>& board) {

        m = board.size();
        n = board[0].size();

        // 1. Start DFS from boundary O's

        // Top and bottom rows
        for(int c = 0; c < n; c++) {

            if(board[0][c] == 'O')
                dfs(board, 0, c);

            if(board[m-1][c] == 'O')
                dfs(board, m-1, c);
        }

        // Left and right columns
        for(int r = 0; r < m; r++) {

            if(board[r][0] == 'O')
                dfs(board, r, 0);

            if(board[r][n-1] == 'O')
                dfs(board, r, n-1);
        }


        // 2. Capture surrounded O's
        // 3. Restore safe cells

        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {

                if(board[r][c] == 'O')
                    board[r][c] = 'X';

                else if(board[r][c] == 'S')
                    board[r][c] = 'O';
            }
        }
    }
};