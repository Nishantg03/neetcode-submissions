class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;

    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < s.length(); right++) {

        // Duplicate found
        while (st.find(s[right]) != st.end()) {
            st.erase(s[left]);
            left++;
        }

        // Add current character
        st.insert(s[right]);

        // Calculate current window length
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
    }
};
