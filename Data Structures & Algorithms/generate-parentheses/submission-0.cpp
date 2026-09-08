class Solution {
public:
    vector<string> ans;
    string s;

    void solve(int n, int open, int close) {

        // Complete valid string
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // Option 1: Add '('
        if (open < n) {
            s.push_back('(');
            solve(n, open + 1, close);

            // Backtrack
            s.pop_back();
        }

        // Option 2: Add ')'
        if (close < open) {
            s.push_back(')');
            solve(n, open, close + 1);

            // Backtrack
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        solve(n, 0, 0);
        return ans;
    }
};