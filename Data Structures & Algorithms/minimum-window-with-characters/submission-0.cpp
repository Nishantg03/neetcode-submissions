class Solution {
public:
    string minWindow(string s, string t) {
   
    vector<int> need(128, 0);

    // Count characters needed
    for (char c : t) {
        need[c]++;
    }

    int left = 0;
    int count = 0;

    int start = 0;
    int minLen = INT_MAX;

    for (int right = 0; right < s.length(); right++) {

        // If this character is required
        if (need[s[right]] > 0) {
            count++;
        }

        // We use this character
        need[s[right]]--;

        // Window contains all characters of t
        while (count == t.length()) {

            // Save smallest window
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            // Remove left character
            need[s[left]]++;

            // If it was a required character,
            // window is no longer valid
            if (need[s[left]] > 0) {
                count--;
            }

            left++;
        }
    }

    if (minLen == INT_MAX)
        return "";

    return s.substr(start, minLen);
}
};
