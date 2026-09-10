class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n + 1, 0);

        dp[0] = 1;

        // First character
        if (s[0] != '0')
            dp[1] = 1;
        else
            return 0;

        for (int i = 2; i <= n; i++) {

            // Take one digit
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            // Take two digits
            int num = stoi(s.substr(i - 2, 2));

            if (num >= 10 && num <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};