class Solution {
public:
    bool checkInclusion(string s1, string s2) {
   
    if (s1.length() > s2.length())
        return false;

    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);

    int windowSize = s1.length();

    // Frequency of s1
    for (char c : s1) {
        freq1[c - 'a']++;
    }

    // Sliding window
    for (int right = 0; right < s2.length(); right++) {

        // Add current character
        freq2[s2[right] - 'a']++;

        // Keep window size equal to s1
        if (right >= windowSize) {
            int left = right - windowSize;
            freq2[s2[left] - 'a']--;
        }

        // Check only when window has reached s1's size
        if (right >= windowSize - 1) {
            if (freq1 == freq2)
                return true;
        }
    }
    return false;
    }

};
