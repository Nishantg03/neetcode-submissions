class Solution {
public:
    int solve(vector<int>& prices, int i, int buy,
              vector<vector<int>>& dp) {

        if (i >= prices.size())
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        if (buy) {
            // We can buy or skip
            int take = -prices[i] + solve(prices, i + 1, 0, dp);
            int skip = solve(prices, i + 1, 1, dp);

            return dp[i][buy] = max(take, skip);
        }
        else {
            // We can sell or skip
            int sell = prices[i] + solve(prices, i + 2, 1, dp);
            int skip = solve(prices, i + 1, 0, dp);

            return dp[i][buy] = max(sell, skip);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        // buy = 1 means we are allowed to buy / currently don't own
        // buy = 0 means we are holding a stock
        return solve(prices, 0, 1, dp);
    }
};