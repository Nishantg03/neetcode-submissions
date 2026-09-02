class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
     int n = temperatures.size();

        vector<int> result(n, 0);
        stack<int> st;  // stores indices

        for (int i = n - 1; i >= 0; i--) {

            // Remove temperatures that cannot be the answer
            while (!st.empty() &&
                   temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // If stack is not empty, its top is the next warmer day
            if (!st.empty()) {
                result[i] = st.top() - i;
            }

            // Current day becomes a candidate for days on its left
            st.push(i);
        }

        return result;  
    }
};
