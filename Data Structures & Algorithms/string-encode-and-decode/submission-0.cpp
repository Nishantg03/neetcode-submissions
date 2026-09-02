class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";

        for (string &str : strs) {
            s += to_string(str.size()) + "#" + str;
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> output;

        int i = 0;

        while (i < s.size()) {
            int j = i;

            // Find '#'
            while (s[j] != '#') {
                j++;
            }

            // Get length
            int len = stoi(s.substr(i, j - i));

            // Move after '#'
            j++;

            // Get the actual string
            output.push_back(s.substr(j, len));

            // Move to next encoded string
            i = j + len;
        }

        return output;
    }
};
