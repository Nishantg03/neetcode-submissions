#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        // dp[i] = minimum number of coins needed
        // to make amount i
        vector<int> dp(amount + 1, amount + 1);

        // Base case:
        // 0 amount requires 0 coins
        dp[0] = 0;

        // Calculate answer for every amount from 1 to amount
        for (int i = 1; i <= amount; i++) {
            
            // Try every coin
            for (int coin : coins) {
                
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // If amount cannot be formed
        if (dp[amount] == amount + 1) {
            return -1;
        }

        return dp[amount];
    }
};