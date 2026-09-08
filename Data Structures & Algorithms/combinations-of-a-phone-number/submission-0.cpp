class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;

    // Check whether s[l...r] is a palindrome
    bool isPalindrome(string& s, int l, int r) {

        while (l < r) {

            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    void solve(string& s, int i) {

        // We have used the entire string
        if (i == s.size()) {
            ans.push_back(path);
            return;
        }

        // Try every possible substring starting at i
        for (int j = i; j < s.size(); j++) {

            // Check whether s[i...j] is palindrome
            if (!isPalindrome(s, i, j))
                continue;

            // Choose the palindrome substring
            path.push_back(s.substr(i, j - i + 1));

            // Solve the remaining string
            solve(s, j + 1);

            // Backtrack
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {

        solve(s, 0);

        return ans;
    }
};