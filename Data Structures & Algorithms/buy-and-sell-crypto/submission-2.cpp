class Solution {
public:
    int maxProfit(vector<int>& prices) {
           int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); i++) {
        // Sell today
        int profit = prices[i] - minPrice;

        // Update maximum profit
        maxProfit = max(maxProfit, profit);

        // Update minimum buying price
        minPrice = min(minPrice, prices[i]);
    }

    return maxProfit;
    }
};
