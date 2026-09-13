class Solution {
public:
    int solve(int i, int amount, vector<int>& coins,
              vector<vector<int>>& dp) {

        // Exact amount formed
        if (amount == 0)
            return 1;

        // No coins left
        if (i == coins.size())
            return 0;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        // Skip current coin
        int skip = solve(i + 1, amount, coins, dp);

        int take = 0;

        // Take current coin
        // Stay at i because we can use the coin again
        if (coins[i] <= amount) {
            take = solve(i, amount - coins[i], coins, dp);
        }

        return dp[i][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(
            n, vector<int>(amount + 1, -1)
        );

        return solve(0, amount, coins, dp);
    }
};