#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        unordered_set<string> words(wordDict.begin(), wordDict.end());

        // dp[i] = true if first i characters can be segmented
        vector<bool> dp(n + 1, false);

        dp[0] = true;

        for (int i = 1; i <= n; i++) {

            // Try every possible previous starting point
            for (int j = 0; j < i; j++) {

                // First part must already be valid
                if (!dp[j])
                    continue;

                // Check if s[j...i-1] is a dictionary word
                string word = s.substr(j, i - j);

                if (words.count(word)) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};