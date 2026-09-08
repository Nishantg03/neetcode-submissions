class Solution {
public:

    bool dfs(vector<vector<char>>& board, string& word,
             int r, int c, int index) {

        // We found the complete word
        if (index == word.size()) {
            return true;
        }

        // Out of bounds
        if (r < 0 || r >= board.size() ||
            c < 0 || c >= board[0].size()) {
            return false;
        }

        // Current cell doesn't match
        if (board[r][c] != word[index]) {
            return false;
        }

        // Mark current cell as visited
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore 4 directions
        bool found =
            dfs(board, word, r + 1, c, index + 1) || // down
            dfs(board, word, r - 1, c, index + 1) || // up
            dfs(board, word, r, c + 1, index + 1) || // right
            dfs(board, word, r, c - 1, index + 1);   // left

        // Backtrack: restore cell
        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {

                // Try starting the word from every cell
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};