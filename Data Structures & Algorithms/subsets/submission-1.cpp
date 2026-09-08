class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;

    void solve(vector<int>& nums, int i) {

        // Base case
        if (i == nums.size()) {
            ans.push_back(subset);
            return;
        }

        // Take nums[i]
        subset.push_back(nums[i]);
        solve(nums, i + 1);

        // Backtrack
        subset.pop_back();

        // Don't take nums[i]
        solve(nums, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums, 0);
        return ans;
    }
};