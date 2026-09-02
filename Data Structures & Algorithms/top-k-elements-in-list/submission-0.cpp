class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Count frequency
        for (int x : nums) {
            freq[x]++;
        }

        // Store {frequency, element}
        vector<pair<int, int>> v;

        for (auto &it : freq) {
            v.push_back({it.second, it.first});
        }

        // Sort by frequency
        sort(v.begin(), v.end(), greater<pair<int, int>>());

        vector<int> ans;

        // Take k most frequent
        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].second);
        }

        return ans;
    }
};