class Solution {
public:
    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        // word1 is finished
        // Need to insert remaining characters of word2
        for (int j = 0; j <= m; j++) {
            dp[n][j] = m - j;
        }

        // word2 is finished
        // Need to delete remaining characters of word1
        for (int i = 0; i <= n; i++) {
            dp[i][m] = n - i;
        }

        // Start from back
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else {
                    int replace = dp[i + 1][j + 1];
                    int deleteChar = dp[i + 1][j];
                    int insertChar = dp[i][j + 1];

                    dp[i][j] = 1 + min({
                        replace,
                        deleteChar,
                        insertChar
                    });
                }
            }
        }

        return dp[0][0];
    }
};