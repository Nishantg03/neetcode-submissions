class Solution {
public:
    vector<vector<int>> ans;
    vector<int> perm;
    vector<bool> used;

    void solve(vector<int>& nums) {

        // If permutation is complete
        if (perm.size() == nums.size()) {
            ans.push_back(perm);
            return;
        }

        // Try every available element
        for (int i = 0; i < nums.size(); i++) {

            // Already used → cannot choose
            if (used[i])
                continue;

            // Choose
            perm.push_back(nums[i]);
            used[i] = true;

            // Fill the next position
            solve(nums);

            // Backtrack
            used[i] = false;
            perm.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(), false);

        solve(nums);

        return ans;
    }
};